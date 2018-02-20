#include <QCoreApplication>
#include <QSettings>
#include <QFile>
#include <QDir>
#include <QString>
#include "httplistener.h"

#include "requestmapper.h"

#include "testcontroller.h"
#include "htmltestcontroller.h"
#include "fusioncontroller.h"
#include "fusionmusiccontroller.h"

using namespace stefanfrings;

/**
 * Search the configuration file.
 * Aborts the application if not found.
 * @return The valid filename
 */
QString searchConfigFile() {
    QString binDir=QCoreApplication::applicationDirPath();
    QString appName=QCoreApplication::applicationName();
    QFile file;
    file.setFileName(binDir+"/webapp1.ini");
    if (!file.exists()) {
        file.setFileName(binDir+"/etc/webapp1.ini");
        if (!file.exists()) {
            file.setFileName(binDir+"/../etc/webapp1.ini");
            if (!file.exists()) {
                file.setFileName(binDir+"/../"+appName+"/etc/webapp1.ini");
                if (!file.exists()) {
                    file.setFileName(binDir+"/../../"+appName+"/etc/webapp1.ini");
                    if (!file.exists()) {
                        file.setFileName(binDir+"/../../../../../"+appName+"/etc/webapp1.ini");
                        if (!file.exists()) {
                            file.setFileName(QDir::rootPath()+"etc/webapp1.ini");
                        }
                    }
                }
            }
        }
    }
    if (file.exists()) {
        QString configFileName=QDir(file.fileName()).canonicalPath();
        qDebug("using config file %s", qPrintable(configFileName));
        return configFileName;
    }
    else {
        qFatal("config file not found");
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QString configFileName=searchConfigFile();

    // Static file controller
    QSettings* fileSettings=new QSettings(configFileName,QSettings::IniFormat,&app);
    fileSettings->beginGroup("files");
    RequestMapper::staticFileController=new StaticFileController(fileSettings,&app);

    // Configure template cache
    QSettings* templateSettings=new QSettings(configFileName,QSettings::IniFormat,&app);
    templateSettings->beginGroup("templates");
    RequestMapper::templateCache=new TemplateCache(templateSettings,&app);

    // HTTP server
    QSettings* listenerSettings=new QSettings(configFileName,QSettings::IniFormat,&app);
    listenerSettings->beginGroup("listener");
    new HttpListener(listenerSettings,new RequestMapper(&app),&app);

    return app.exec();


}
