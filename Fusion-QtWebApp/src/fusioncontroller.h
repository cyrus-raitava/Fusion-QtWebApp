#ifndef FUSIONCONTROLLER_H
#define FUSIONCONTROLLER_H

#include "httprequesthandler.h"

using namespace stefanfrings;

class FusionController : public HttpRequestHandler
{
    Q_OBJECT
public:
    FusionController(QObject* parent=0);
    void service(HttpRequest &request, HttpResponse &response);
    void returnJson(HttpRequest &request, HttpResponse &response);
    void returnJs(HttpRequest &request, HttpResponse &response);
    void returnCSS(HttpRequest &request, HttpResponse &response);
};

#endif // FUSIONCONTROLLER_H
