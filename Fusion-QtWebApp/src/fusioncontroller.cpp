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

    response.write("<script src='/returnJs' type='text/javascript'></script>");

    response.write("<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'>");
    response.write("<link rel='icon' href='data:;base64,iVBORw0KGgo='>");
    response.write("</head>");



    response.write("<body onLoad='loadElements(); fillHTML();'>");
    response.write("<h1>Fusion HTML5 Interface Application</h1>");
    response.write("</body></html>", true);
}

void FusionController::returnJs(HttpRequest &request, HttpResponse &response) {
    response.write("function loadElements() { var subTitle = document.createElement('h2'); subTitle.id = 'subTitle'; subTitle.innerHTML = 'It works!'; document.body.appendChild(subTitle); var currentSourceID = document.createElement('h3'); currentSourceID.id = 'currentSourceID'; currentSourceID.innerHTML = 'The current source ID is: '; document.body.appendChild(currentSourceID); var flags = document.createElement('h3'); flags.id = 'flags'; flags.innerHTML = 'The current flag(s) are: '; document.body.appendChild(flags); var model = document.createElement('h3'); model.id = 'model'; model.innerHTML = 'The model is: '; document.body.appendChild(model); var name = document.createElement('h3'); name.id = 'name'; name.innerHTML = 'The current name is: '; document.body.appendChild(name); var nameSize = document.createElement('h3'); nameSize.id = 'nameSize'; nameSize.innerHTML = 'The name size is: '; document.body.appendChild(nameSize); var sourceID = document.createElement('h3'); sourceID.id = 'sourceID'; sourceID.innerHTML = 'The source ID is: '; document.body.appendChild(sourceID); var sourceType = document.createElement('h3'); sourceType.id = 'sourceType'; sourceType.innerHTML = 'The current source type is: '; document.body.appendChild(sourceType); } function fillHTML() { var xhttp = new XMLHttpRequest(); xhttp.overrideMimeType('application/json'); xhttp.onreadystatechange = function() { if (this.readyState == 4 && this.status == 200) { console.log(this.responseText); var obj = JSON.parse(this.responseText); for (var p in obj) { var keyName = ''; var keyPair = ''; if (obj.hasOwnProperty(p)) { var keyName = '' + p; var keyPair = '' + obj[p]; } if (!!document.getElementById(keyName)) { document.getElementById(keyName).innerHTML += keyPair; } } } }; xhttp.open('GET', '/jsonData', true); xhttp.send(); }", true);
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
