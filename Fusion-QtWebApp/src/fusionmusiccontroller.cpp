#include "fusionmusiccontroller.h"
#include "requestmapper.h"
#include "template.h"
#include "fusionhexencode.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QtEndian>
#include <iostream>
#include <QString>

FusionMusicController::FusionMusicController (QObject* parent) : HttpRequestHandler(parent)
{
    // Empty
}



void FusionMusicController::service(HttpRequest &request, HttpResponse &response)
{

    QByteArray command;

    if (request.hasParameter("deviceName", request.getParameter("deviceName")))
    {
        QByteArray deviceName = request.getParameter("deviceName");
        command = "fapiSetDeviceName";

        FusionHexEncode::byteMerger(command,  deviceName);
    }


    if (request.hasParameter("songState", request.getParameter("songState")))
    {
       QByteArray songState = request.getParameter("songState");
       command = "fapiSetMedia";

       FusionHexEncode::byteMerger(command,  songState);
    }




    if (request.hasParameter("sourceType", request.getParameter("sourceType")))
    {
        QByteArray sourceType = request.getParameter("sourceType");
        command = "fapiSetSource";


    }



    if (request.hasParameter("powerState", request.getParameter("powerState")))
    {
        QByteArray powerState = request.getParameter("powerState");
        command = "fapiSetPowerState";
        FusionHexEncode::byteMerger(command,  powerState);


    }






    // Simple HTML5 webpage to be sent to the client, for Fusion_QtWebApp Music UI Application

    response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");

    response.write("<!DOCTYPE html> <html id='html'> <head> <link type='text/css' rel='stylesheet' href='/fusionMusic/fusion.css'/> <script type='text/javascript' src='/fusionMusic/fusion.js'></script> </head> <body onload='powerChange()'> <div> <button class='dName centerElements' type='button' id='moreInfoButton'>More Information</button> <h1 class='dName centerElements' id='deviceName'>Device Name:<h1> <input class='dName centerElements' type='text' id='setDeviceName'> <h2 class='dName centerElements' id='name'>Cyrus<h2> <button class='centerElements' type='button' id='changeButton' onclick='changeName()'>CHANGE</button> <p class='centerElements' id='warningLabel'>Warning! Name cannot be longer than 10 characters.<p> <button class='centerElements' type='button' id='playPauseButton' onclick='playPause()'>Play</button> <select class='comboBox centerElements' id='choiceBox' onchange='sourceChange()'> <option value='AM'>AM</option> <option value='FM'>FM</option> <option value='AUX'>AUX</option> <option value='iPod'>iPod</option> <option value='Bluetooth'>Bluetooth</option> </select> <h2 class='dName centerElements' id='sourceTitle'>Source Type:<h2> <label class='switch centerElements' id='powerSwitch' > <input type='checkbox' id='switch' onclick='powerChange();'/> <span class='slider round'></span> </label> <h3 class='centerElements' id='onLabel'>OFF</h3> <h3 class='dName centerElements' id='foot1'>Powered by </h3><h2 class='dName centerElements' id='foot2' style='color: #03c46a'>Fusion Entertainment</h2> </div> </body> </html>", true);


    //FusionHexEncode::hexDecoderCheck();


}




void FusionMusicController::returnJson(HttpRequest &request, HttpResponse &response)
{

}


void FusionMusicController::returnJs(HttpRequest &request, HttpResponse &response)
{

//    response.write("", true);

    response.write("function changeName() { document.getElementById('setDeviceName').value = document.getElementById('name').innerHTML; document.getElementById('name').style.visibility = 'hidden'; document.getElementById('setDeviceName').style.visibility = 'visible'; document.getElementById('changeButton').innerHTML = 'DONE'; document.getElementById('changeButton').onclick = doneName; document.getElementById('setDeviceName').focus(); document.getElementById('setDeviceName').select(); } function doneName() { var name = document.getElementById('setDeviceName').value; if (name.length > 10) { document.getElementById('warningLabel').innerHTML = 'Warning! Name cannot be longer than 10 characters.'; document.getElementById('warningLabel').style.visibility = 'visible'; } else if (name.length == 0) { document.getElementById('warningLabel').innerHTML = 'Warning! Name must be at least one character long.'; document.getElementById('warningLabel').style.visibility = 'visible'; } else { document.getElementById('warningLabel').style.visibility = 'hidden'; document.getElementById('name').innerHTML = name; document.getElementById('setDeviceName').value = ''; document.getElementById('name').style.visibility = 'visible'; document.getElementById('setDeviceName').style.visibility = 'hidden'; document.getElementById('changeButton').innerHTML = 'CHANGE'; document.getElementById('changeButton').onclick = changeName; sendFormData('deviceName', name); } } function playPause() { var songState; if (document.getElementById('playPauseButton').innerHTML == 'Play') { songState = 'PLAYING'; document.getElementById('playPauseButton').innerHTML = 'Pause'; } else { songState = 'PAUSED'; document.getElementById('playPauseButton').innerHTML = 'Play'; } sendFormData('songState', songState); } function powerChange() { var powerState; if (document.getElementById('switch').checked) { document.getElementById('html').style = '-webkit-filter: grayscale(0%); -moz-filter: grayscale(0%); filter: grayscale(0%);'; document.getElementById('onLabel').innerHTML = 'ON'; document.getElementById('onLabel').style.color = '#03c46a'; powerState = 'ON'; document.getElementById('moreInfoButton').disabled = false; document.getElementById('changeButton').disabled = false; document.getElementById('playPauseButton').disabled = false; document.getElementById('choiceBox').disabled = false; } else { document.getElementById('html').style = '-webkit-filter: grayscale(100%); -moz-filter: grayscale(100%); filter: grayscale(100%);'; document.getElementById('onLabel').innerHTML = 'OFF'; document.getElementById('onLabel').style.color = '#ba3728'; document.getElementById('moreInfoButton').disabled = true; document.getElementById('changeButton').disabled = true; document.getElementById('warningLabel').style.visibility = 'hidden'; document.getElementById('playPauseButton').disabled = true; document.getElementById('choiceBox').disabled = true; powerState = 'OFF'; } sendFormData('powerState', powerState); } function sourceChange() { var sourceType = document.getElementById('choiceBox').value; sendFormData('sourceType', sourceType); } function sendFormData(attribute, information) { var formData = new FormData(); formData.append(attribute, information); var request = new XMLHttpRequest(); request.open('POST', '/fusionMusic'); request.send(formData); }", true);
}

void FusionMusicController::returnCSS(HttpRequest &request, HttpResponse &response)
{
    response.write("body { background-color: #7a7a7a; font-family: 'Helvetica Neue', Helvetica, Arial, sans-serif; } button, .comboBox { background-color: #03c46a; border: none; color: white; padding: 10px 25px; text-align: center; text-decoration: none; display: inline-block; font-size: 16px; position:absolute; top:0; right:0; } .centerElements { top: 0%; position: absolute !important; left: 0 !important; right: 0 !important; margin-left: auto !important; margin-right: auto !important; } .dName { color: #03c46a; text-align: center; font-size: 3em; width: 350px; } #moreInfoButton { width: 200px; height: 30px; color: #ffffff; font-size: 1em; text-align: center; } #setDeviceName { position: absolute; width: 250px; height: 40px; font-size: 1em; top: 13%; visibility: hidden; } #name { top: 7%; color: #ffffff; } #changeButton { top: 22%; color: #ffffff; text-align: center; width: 120px; height: 35px; } #doneButton { top: 22%; color: #ffffff; text-align: center; width: 120px; height: 35px; visibility: hidden; background-color: #03c46a; border: none; padding: 10px 25px; text-decoration: none; display: inline-block; font-size: 16px; } #warningLabel { top: 27%; color: #ad3c2e; text-align: center; width: 200px; height: 30px; font-size: 0.5em; visibility: hidden; } #playPauseButton { top: 35%; color: #ffffff; text-align: center; width: 150px; height: 80px; } #sourceTitle { top: 45%; } #choiceBox { top: 60%; width: 100px; height: 50px; text-align: center; select:active, select:hover { outline: none } select:active, select:hover { outline-color: #03c46a; } } #powerSwitch { top: 70%; } #onLabel { top: 70%; color: #ba3728; text-align: center; font-size: 3em; width: 350px; } .switch { position: relative; display: inline-block; width: 60px; height: 34px; } .switch input {display:none;} .slider { position: absolute; cursor: pointer; top: 0; left: 0; right: 0; bottom: 0; background-color: #ccc; -webkit-transition: .4s; transition: .4s; } .slider:before { position: absolute; content: ''; height: 26px; width: 26px; left: 4px; bottom: 4px; background-color: white; -webkit-transition: .4s; transition: .4s; } input:checked + .slider { background-color: #03c46a; } input:focus + .slider { box-shadow: 0 0 1px #03c46a; } input:checked + .slider:before { -webkit-transform: translateX(26px); -ms-transform: translateX(26px); transform: translateX(26px); } .slider.round { border-radius: 34px; } .slider.round:before { border-radius: 50%; } #foot1 { position: absolute; font-size: 1em; color: #000000; top: 88%; } #foot2 { position: absolute; top: 90%; font-size: 2em; }", true);
}



