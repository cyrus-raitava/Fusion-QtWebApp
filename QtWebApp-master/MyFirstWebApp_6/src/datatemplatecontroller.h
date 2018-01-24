#ifndef DATATEMPLATECONTROLLER_H
#define DATATEMPLATECONTROLLER_H

#include "httprequesthandler.h"
#include <QString>

using namespace stefanfrings;

class DataTemplateController : public HttpRequestHandler
{
    Q_OBJECT
public:
    DataTemplateController(QObject* parent=0);
    void service(HttpRequest &request, HttpResponse &response);
    QString readJson(QString dataName, int position);
private:
    QList<QString> list;
};

#endif // DATATEMPLATECONTROLLER_H
