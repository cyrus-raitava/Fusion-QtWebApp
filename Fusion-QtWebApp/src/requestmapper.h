#ifndef REQUESTMAPPER_H
#define REQUESTMAPPER_H

#include "httprequesthandler.h"
#include "staticfilecontroller.h"
#include "templatecache.h"
#include "templatecontrollerexample.h"
#include "fusioncontroller.h"
#include "fusionmusiccontroller.h"

using namespace stefanfrings;

class RequestMapper : public HttpRequestHandler {
    Q_OBJECT
public:
    RequestMapper(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
    static StaticFileController* staticFileController;
    static TemplateCache* templateCache;

private:
    templateControllerExample TemplateControllerExample;
    FusionController fusionController;
    FusionMusicController fusionMusicController;
};

#endif // REQUESTMAPPER_H
