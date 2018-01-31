#include "fusioncontroller.h"
#include "requestmapper.h"
#include "template.h"


FusionController::FusionController(QObject* parent) : HttpRequestHandler(parent)
{
    // Empty
}

void FusionController::service(HttpRequest &request, HttpResponse &response) {

    response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");
    response.write("<html lang='en'><head>");
    response.write("<script src='/files/fusion.js' type='text/javascript'></script>");
    response.write("<script src='/files/music_app.js' type='text/javascript'></script>");
    response.write("<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'>");
    response.write("</head>");


    response.write("<body onLoad='loadElements(); fillHTML();'>");
    response.write("<h1>Fusion HTML5 Interface Application</h1>");
    response.write("</body></html>", true);
}
