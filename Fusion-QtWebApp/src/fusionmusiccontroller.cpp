#include "fusionmusiccontroller.h"
#include "requestmapper.h"
#include "template.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QtEndian>

FusionMusicController::FusionMusicController (QObject* parent) : HttpRequestHandler(parent)
{
    // Empty
}

void FusionMusicController::service(HttpRequest &request, HttpResponse &response)
{

    QByteArray example;

    example[0] = 0x1c;
    example[1] = 0x00;
    example[2] = 0x01;


    QByteArray ex = checkSumXor(example);

    QByteArray nam = "iPod";

    QByteArray iPod = fapiSetDeviceName(nam);

    qDebug() << iPod << "<--- THIS IS IPOD AS HEX" << endl;

    qDebug() << iPod[0] << "<--- iPod[0]" << endl;

    qDebug() << iPod[1] << "<--- iPod[1]" << endl;

    QByteArray size(4, 0);


    size = sizeBytes(17);

    qDebug() << size.toHex() << endl;

    QByteArray powerState = request.getParameter("powerState");

    QByteArray pow = fapiSetPowerState(powerState);

















    if (request.hasParameter("deviceName", request.getParameter("deviceName")))
    {
        QByteArray deviceName = request.getParameter("deviceName");
    }


    if (request.hasParameter("songState", request.getParameter("songState")))
    {
       QByteArray songState = request.getParameter("songState");
    }




    if (request.hasParameter("sourceType", request.getParameter("sourceType")))
    {
        QByteArray sourceType = request.getParameter("sourceType");
    }



    if (request.hasParameter("powerState", request.getParameter("powerState")))
    {
        QByteArray powerState = request.getParameter("powerState");
    }











    // Simple HTML5 webpage to be sent to the client, for Fusion_QtWebApp Music UI Application

    response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");

    response.write("<html>");

    response.write("<head>");

    response.write("<link type='text/css'  rel='stylesheet' href='/fusionMusic/fusion.css'/>");
    response.write("<script type='text/javascript' src='/fusionMusic/fusion.js'></script>");

     response.write("</head>");

     response.write("<body>");



     response.write("<div>");
       response.write("<button class='dName centerElements' type='button' id='moreInfoButton'>More Information</button>");

       response.write("<h1 class='dName centerElements' id='deviceName'>Device Name:<h1>");


         response.write("<input class='dName centerElements' type='text' id='setDeviceName'>");


       response.write("<h2 class='dName centerElements' id='name'>Cyrus<h2>");
       response.write("<button class='centerElements' type='button' id='changeButton' onclick='changeName()'>CHANGE</button>");
       response.write("<p class='centerElements' id='warningLabel'>Warning! Name cannot be longer than 10 characters.<p>");

       response.write("<button class='centerElements' type='button' id='playPauseButton' onclick='playPause()'>Play</button>");

       response.write("<select class='comboBox centerElements' id='choiceBox' onchange='sourceChange()'>");
         response.write("<option value='AM'>AM</option>");
         response.write("<option value='FM'>FM</option>");
         response.write("<option value='AUX'>AUX</option>");
         response.write("<option value='Bluetooth'>Bluetooth</option>");
       response.write("</select>");

       response.write("<h2 class='dName centerElements' id='sourceTitle'>Source Type:<h2>");

       response.write("<label class='switch centerElements' id='powerSwitch' >");
         response.write("<input type='checkbox' id='switch' onclick='powerChange();'/>");
         response.write("<span class='slider round'></span>");
       response.write("</label>");

       response.write("<h3 class='centerElements' id='onLabel'>OFF</h3>");

       response.write("<h3 class='dName centerElements' id='foot1'>Powered by </h3><h2 class='dName centerElements' id='foot2' style='color: #03c46a'>Fusion Entertainment</h2>");

     response.write("</div>");



     response.write("</body>");

     response.write("</html>", true);

}

QByteArray FusionMusicController::commandEncode(QByteArray &command)
{
    QByteArray output(2, 0);

    if (command == "fapiGetState") {
        output[0] = 0x01;
        output[1] = 0x00;
    } else if (command == "fapiSetDeviceName") {
        output[0] = 0x1d;
        output[1] = 0x00;
    } else if (command == "fapiSetPowerState") {
        output[0] = 0x1c;
        output[1] = 0x00;
    } else if (command == "fapiSource") {
        output[0] = 0x02;
        output[1] = 0x80;
    } else if (command == "fapiSetSource") {
        output[0] = 0x02;
        output[1] = 0x00;
    } else if (command == "fapiSetMedia") {
        output[0] = 0x03;
        output[1] = 0x00;
    } else {
        output = "INVALID COMMAND";
    }

    return output;
}

void FusionMusicController::byteMerger(QByteArray &command, QByteArray &message)
{

    QByteArray outputPacket;

    // Set header byte
    outputPacket[0] = 0xff;

    QByteArray commandCode = commandEncode(command);

    QByteArray messageLength[2];





}

QByteArray FusionMusicController::sizeBytes(int size)
{
    QByteArray result(2, 0);

    QString hexNum = QString().number(size, 16);

    qDebug() << "HEX equivalent of " << size << " is: " << hexNum << endl;

    if (hexNum.size() == 1) {
        hexNum.prepend("000");
    } else if (hexNum.size() == 2) {
        hexNum.prepend("00");
    } else if (hexNum.size() == 3) {
        hexNum.prepend("0");
    } else {

    }

    QString temp = (QString)hexNum[0];
    temp.append(hexNum[1]);

    hexNum[0] = hexNum[2];
    hexNum[1] = hexNum[3];
    hexNum[2] = temp[0];
    hexNum[3] = temp[1];

    result = QByteArray::fromHex(hexNum.toLatin1());

    return result;
}

QByteArray FusionMusicController::fapiSetDeviceName(QByteArray &deviceName)
{
    int nameLength = deviceName.size() + 1;

    QByteArray message(nameLength, 0);

//    QString nameLengthHex = QString().number(nameLength, 16);

//    if (nameLengthHex.size() == 1)
//    {
//        nameLengthHex.prepend("0");
//    }

//    QByteArray messagePrefix(1, 0);

//    messagePrefix = QByteArray::fromHex(nameLengthHex.toLatin1());

    message[0] = nameLength; /*messagePrefix[0];*/

    QByteArray hexName(nameLength, 0);

    hexName = deviceName.toHex();

    qDebug << (QString)hexName[0] << "<----- hexName[0]" << endl;

// NEED TO FIX ALL AROUND HERE PROPERLY, AND COMMENT CODE, WON'T COMPILE IN CURRENT STATE


    message.insert(1, hexName);




    qDebug() << deviceName.toHex().size()/2 << endl;

    return message;
}

QByteArray FusionMusicController::fapiSetPowerState(QByteArray &state)
{
       QByteArray powerState(1, 0);

       if (state == "ON")
       {
            powerState[0] = 0x01;

       } else if (state == "OFF")
       {
            powerState[0] = 0x02;
       } else {
           qDebug() << "ERROR! Request is neither ON nor OFF." << endl;
       }

       qDebug() << powerState.toHex();


       return powerState;
}



QByteArray FusionMusicController::checkSumXor(QByteArray &input)
{
    int XOR = 0;
    int i;

    QByteArray result(1, 0);

    for (i = 0; i <= input.size(); i++)
    {
        XOR ^= input[i];

        qDebug() << "input[" << i << "] is: " << input[i] << endl;
    }

    qDebug() << "THIS IS THE CHECKSUM RESULT RIGHT HERE:" << QString::number(XOR, 16) << endl;

    result.append(QString::number(XOR, 16));

    return result;

}





















void FusionMusicController::returnJson(HttpRequest &request, HttpResponse &response)
{

}


void FusionMusicController::returnJs(HttpRequest &request, HttpResponse &response)
{

//    response.write("", true);

    response.write("function changeName() { document.getElementById('setDeviceName').value = document.getElementById('name').innerHTML; document.getElementById('name').style.visibility = 'hidden'; document.getElementById('setDeviceName').style.visibility = 'visible'; document.getElementById('changeButton').innerHTML = 'DONE'; document.getElementById('changeButton').onclick = doneName; document.getElementById('setDeviceName').focus(); document.getElementById('setDeviceName').select(); } function doneName() { var name = document.getElementById('setDeviceName').value; if (name.length > 10) { document.getElementById('warningLabel').innerHTML = 'Warning! Name cannot be longer than 10 characters.'; document.getElementById('warningLabel').style.visibility = 'visible'; } else if (name.length == 0) { document.getElementById('warningLabel').innerHTML = 'Warning! Name must be at least one character long.'; document.getElementById('warningLabel').style.visibility = 'visible'; } else { document.getElementById('warningLabel').style.visibility = 'hidden'; document.getElementById('name').innerHTML = name; document.getElementById('setDeviceName').value = ''; document.getElementById('name').style.visibility = 'visible'; document.getElementById('setDeviceName').style.visibility = 'hidden'; document.getElementById('changeButton').innerHTML = 'CHANGE'; document.getElementById('changeButton').onclick = changeName; sendFormData('deviceName', name); } } function playPause() { var songState; if (document.getElementById('playPauseButton').innerHTML == 'Play') { songState = 'PAUSED'; document.getElementById('playPauseButton').innerHTML = 'Pause'; } else { songState = 'PLAYING...'; document.getElementById('playPauseButton').innerHTML = 'Play'; } sendFormData('songState', songState); } function powerChange() { var powerState; if (document.getElementById('switch').checked) { document.getElementById('onLabel').innerHTML = 'ON'; document.getElementById('onLabel').style.color = '#03c46a'; powerState = 'ON'; } else { document.getElementById('onLabel').innerHTML = 'OFF'; document.getElementById('onLabel').style.color = '#ba3728'; powerState = 'OFF'; } sendFormData('powerState', powerState); } function sourceChange() { var sourceType = document.getElementById('choiceBox').value; sendFormData('sourceType', sourceType); } function sendFormData(attribute, information) { var formData = new FormData(); formData.append(attribute, information); var request = new XMLHttpRequest(); request.open('POST', '/fusionMusic'); request.send(formData); }", true);
}

void FusionMusicController::returnCSS(HttpRequest &request, HttpResponse &response)
{
    response.write("body { background-color: #7a7a7a; font-family: 'Helvetica Neue', Helvetica, Arial, sans-serif; } button, .comboBox { background-color: #03c46a; border: none; color: white; padding: 10px 25px; text-align: center; text-decoration: none; display: inline-block; font-size: 16px; position:absolute; top:0; right:0; } .centerElements { top: 0%; position: absolute !important; left: 0 !important; right: 0 !important; margin-left: auto !important; margin-right: auto !important; } .dName { color: #03c46a; text-align: center; font-size: 3em; width: 350px; } #moreInfoButton { width: 200px; height: 30px; color: #ffffff; font-size: 1em; text-align: center; } #setDeviceName { position: absolute; width: 250px; height: 40px; font-size: 1em; top: 13%; visibility: hidden; } #name { top: 7%; color: #ffffff; } #changeButton { top: 22%; color: #ffffff; text-align: center; width: 120px; height: 35px; } #doneButton { top: 22%; color: #ffffff; text-align: center; width: 120px; height: 35px; visibility: hidden; background-color: #03c46a; border: none; padding: 10px 25px; text-decoration: none; display: inline-block; font-size: 16px; } #warningLabel { top: 27%; color: #ad3c2e; text-align: center; width: 200px; height: 30px; font-size: 0.5em; visibility: hidden; } #playPauseButton { top: 35%; color: #ffffff; text-align: center; width: 150px; height: 80px; } #sourceTitle { top: 45%; } #choiceBox { top: 60%; width: 100px; height: 50px; text-align: center; select:active, select:hover { outline: none } select:active, select:hover { outline-color: #03c46a; } } #powerSwitch { top: 70%; } #onLabel { top: 70%; color: #ba3728; text-align: center; font-size: 3em; width: 350px; } .switch { position: relative; display: inline-block; width: 60px; height: 34px; } .switch input {display:none;} .slider { position: absolute; cursor: pointer; top: 0; left: 0; right: 0; bottom: 0; background-color: #ccc; -webkit-transition: .4s; transition: .4s; } .slider:before { position: absolute; content: ''; height: 26px; width: 26px; left: 4px; bottom: 4px; background-color: white; -webkit-transition: .4s; transition: .4s; } input:checked + .slider { background-color: #03c46a; } input:focus + .slider { box-shadow: 0 0 1px #03c46a; } input:checked + .slider:before { -webkit-transform: translateX(26px); -ms-transform: translateX(26px); transform: translateX(26px); } .slider.round { border-radius: 34px; } .slider.round:before { border-radius: 50%; } #foot1 { position: absolute; font-size: 1em; color: #000000; top: 88%; } #foot2 { position: absolute; top: 90%; font-size: 2em; }", true);
}

