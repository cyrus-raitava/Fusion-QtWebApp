#ifndef REQUESTMAPPER_H
#define REQUESTMAPPER_H

#include "httprequesthandler.h"
#include "httpsessionstore.h"
#include "helloworldcontroller.h"
#include "listdatacontroller.h"
#include "logincontroller.h"
#include "cookietestcontroller.h"
#include "staticfilecontroller.h"
#include "datatemplatecontroller.h"
#include "templatecache.h"

using namespace stefanfrings;

class RequestMapper : public HttpRequestHandler {
    Q_OBJECT
public:
    RequestMapper(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
    static HttpSessionStore* sessionStore;
    static StaticFileController* staticFileController;
    static TemplateCache* templateCache;
private:
    HelloWorldController helloWorldController;
    ListDataController listDataController;
    LoginController loginController;
    CookieTestController cookieTestController;
    DataTemplateController dataTemplateController;
};

#endif // REQUESTMAPPER_H
