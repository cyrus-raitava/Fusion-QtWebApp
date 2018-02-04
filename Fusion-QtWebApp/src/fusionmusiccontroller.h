#ifndef FUSIONMUSICCONTROLLER_H
#define FUSIONMUSICCONTROLLER_H

#include "httprequesthandler.h"

using namespace stefanfrings;

class FusionMusicController : public HttpRequestHandler
{
    Q_OBJECT
public:
    FusionMusicController(QObject* parent=0);

    void service(HttpRequest &request, HttpResponse &response);
    void returnJson(HttpRequest &request, HttpResponse &response);
    void returnJs(HttpRequest &request, HttpResponse &response);
    void returnCSS(HttpRequest &request, HttpResponse &response);
};

#endif // FUSIONMUSICCONTROLLER_H
