#include "templatecontrollerexample.h"
#include "requestmapper.h"
#include "template.h"

templateControllerExample::templateControllerExample(QObject* parent) : HttpRequestHandler(parent)
{
    // Empty
}

void templateControllerExample::service(HttpRequest &request, HttpResponse &response) {
    QByteArray language=request.getHeader("Accept-Language");

    response.setHeader("Content-Type", "text/html; charset=UTF-8");

    Template t=RequestMapper::templateCache->getTemplate("/files/staticTest", language);
    response.write(t.toUtf8(), true);
}
