#include "fusioncontroller.h"
#include "requestmapper.h"
#include "template.h"

#include <QJsonObject>
#include <QJsonDocument>


FusionController::FusionController(QObject* parent) : HttpRequestHandler(parent)
{
    // Empty
}

void FusionController::service(HttpRequest &request, HttpResponse &response) {

    // Simple HTML template to be sent to client: apart from header, all elements are created and filled via javascript

    response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");
    response.write("<html lang='en'><head>");
    response.write("<script src='/files/fusion.js' type='text/javascript'></script>");
    response.write("<script src='/files/music_app.js' type='text/javascript'></script>");
    response.write("<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'>");
    response.write("<link rel='icon' href='data:;base64,iVBORw0KGgo='>");
    response.write("</head>");


    response.write("<body onLoad='loadElements(); fillHTML();'>");
    response.write("<h1>Fusion HTML5 Interface Application</h1>");
    response.write("</body></html>", true);
}

void FusionController::returnJson(HttpRequest &request, HttpResponse &response) {

    QJsonObject data
    {
            {"command", "fapiSource"},
            {"currentSourceID", "170135815"},
            {"flags", "01"},
            {"model", "PANEL-STEREO"},
            {"name", "CYRUS"},
            {"nameSize", "13"},
            {"sourceID", "170135815"},
            {"sourceType", "10"}
    };

    QJsonDocument doc(data);

    QString qstrJson(doc.toJson(QJsonDocument::Compact));

    QByteArray strJson = qstrJson.toUtf8().constData();


    response.write(strJson);



}
