#ifndef TEMPLATECONTROLLEREXAMPLE_H
#define TEMPLATECONTROLLEREXAMPLE_H

#include "httprequesthandler.h"

using namespace stefanfrings;

class templateControllerExample : public HttpRequestHandler
{
    Q_OBJECT
public:
    templateControllerExample(QObject* parent=0);
    void service(HttpRequest &request, HttpResponse &response);
};

#endif // TEMPLATECONTROLLEREXAMPLE_H
