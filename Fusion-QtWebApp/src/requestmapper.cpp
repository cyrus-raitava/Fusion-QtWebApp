#include "requestmapper.h"

#include "testcontroller.h"
#include "htmltestcontroller.h"

StaticFileController* RequestMapper::staticFileController=0;
TemplateCache* RequestMapper::templateCache=0;

RequestMapper::RequestMapper(QObject* parent)
    : HttpRequestHandler(parent) {
    // empty
}

void RequestMapper::service(HttpRequest& request, HttpResponse& response) {
    QByteArray path=request.getPath();
    qDebug("RequestMapper: path=%s",path.data());

    if (path=="/" || path=="/test") {
        testcontroller().service(request, response);
    }
    else if (path=="/fusion") {
        fusionController.service(request, response);
    }
    else if (path=="/htmlTest") {
        htmlTestController().service(request, response);
    }
    else if (path.startsWith("/files")) {
        staticFileController->service(request,response);
    }
    else if (path=="/templateExample") {
        TemplateControllerExample.service(request, response);
    }
    else if (path=="/jsonData") {
        fusionController.returnJson(request, response);
    }
    else {
        response.setStatus(404,"Not found");
        response.write("The URL is wrong, no such document.",true);
    }

    qDebug("RequestMapper: finished request");
}
