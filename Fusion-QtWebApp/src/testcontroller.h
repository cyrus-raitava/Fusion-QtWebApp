#ifndef TESTCONTROLLER_H
#define TESTCONTROLLER_H

#include "httprequesthandler.h"

using namespace stefanfrings;

class testcontroller : public HttpRequestHandler
{
    Q_OBJECT
public:
    testcontroller(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
};

#endif // TESTCONTROLLER_H
