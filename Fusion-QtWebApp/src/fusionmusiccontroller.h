#ifndef FUSIONMUSICCONTROLLER_H
#define FUSIONMUSICCONTROLLER_H

#include "httprequesthandler.h"
#include <QByteArray>
#include <iostream>
#include "fusionhexencode.h"

using namespace stefanfrings;

class FusionMusicController : public HttpRequestHandler
{
    Q_OBJECT
public:
    FusionMusicController(QObject* parent=0);

    // Functions for responding to all http requests from client (see requestmapper.cpp to see what URLs lead where).
    void service(HttpRequest &request, HttpResponse &response);
    void returnJson(HttpRequest &request, HttpResponse &response);
    void returnJs(HttpRequest &request, HttpResponse &response);
    void returnCSS(HttpRequest &request, HttpResponse &response);




private:

};

#endif // FUSIONMUSICCONTROLLER_H
