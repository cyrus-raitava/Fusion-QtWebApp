#include "requestmapper.h"
#include "httpsession.h"

HttpSessionStore* RequestMapper::sessionStore=0;
StaticFileController* RequestMapper::staticFileController=0;

TemplateCache* RequestMapper::templateCache=0;

RequestMapper::RequestMapper(QObject* parent)
    : HttpRequestHandler(parent) {
    // empty
}

void RequestMapper::service(HttpRequest& request, HttpResponse& response) {
    QByteArray path=request.getPath();
    qDebug("RequestMapper: path=%s",path.data());

    /*
    QByteArray sessionId=sessionStore->getSessionId(request,response);
    if (sessionId.isEmpty() && path!="/login") {
        qDebug("RequestMapper: redirect to login page");
        response.redirect("/login");
        return;
    }
    */

    if (path=="/" || path=="/hello") {
        helloWorldController.service(request, response);
    }
    else if (path=="/list") {
        listDataController.service(request, response);
    }
    else if (path=="/login") {
        loginController.service(request, response);
    }
    else if (path=="/cookie") {
        cookieTestController.service(request, response);
    }
    else if (path.startsWith("/files")) {
        staticFileController->service(request,response);
    }
    else if (path.startsWith("/music")) {
        dataTemplateController.service(request,response);
    }
    else {
        response.setStatus(404,"Not found");
        response.write("The URL is wrong, no such document.");
    }

    qDebug("RequestMapper: finished request");
}

