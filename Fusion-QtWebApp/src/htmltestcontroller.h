#ifndef HTMLTESTCONTROLLER_H
#define HTMLTESTCONTROLLER_H

#include "httprequesthandler.h"

using namespace stefanfrings;

class htmlTestController : public HttpRequestHandler
{
    Q_OBJECT
public:
    htmlTestController(QObject* parent=0);
    void service(HttpRequest &request, HttpResponse &response);
};

#endif // HTMLTESTCONTROLLER_H
