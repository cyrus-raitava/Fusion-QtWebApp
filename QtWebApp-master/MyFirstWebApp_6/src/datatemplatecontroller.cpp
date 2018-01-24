#include "datatemplatecontroller.h"
#include "requestmapper.h"
#include "template.h"

#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFile>
#include <QJsonDocument>
#include <QString>


DataTemplateController::DataTemplateController(QObject* parent) : HttpRequestHandler(parent)
{
    list.append("Cyrus");
    list.append("Software");
    list.append("Reading");
    list.append("Music");

}

void DataTemplateController::service(HttpRequest &request, HttpResponse &response) {

        QByteArray language=request.getHeader("Accept-Language");
        response.setHeader("Content-type", "text/html; charset=UTF-8");

        Template t=RequestMapper::templateCache->getTemplate("files/music_app", language);

        QString data;

        QStringList names;
        names << "sourceID" << "currenSourceID" << "sourceType" << "flags" << "nameSize" << "name";

        for (int i = 0; i < names.size(); i++) {


            data = DataTemplateController::readJson((QString)names.at(i), (int)i);
            t.setVariable(names.at(i), data);


        }

        response.write(t.toUtf8(), true);

}


/**
 * @brief DataTemplateController::readJson
 * @return
 *
 * Method to read into JSON file (with a pre-set structure), scrape data and fill in an html template,
 * to be delivered to a client
 */

QString DataTemplateController::readJson(QString dataName, int position) {

        QString val;
        QFile file;

        file.setFileName("/home/raitava/Documents/Qt Projects/Newer Copy/QtWebApp-master/MyFirstWebApp_6/docroot/files/name.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();

        QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
        QJsonObject jObj = d.object();

        QJsonArray array = jObj["fapiSource"].toArray();

        QVariantMap json_map = jObj.toVariantMap();


        return (array.at(position).toObject())[dataName].toString();

}
