#include "fusionmusiccontroller.h"
#include "requestmapper.h"
#include "template.h"

#include <QJsonObject>
#include <QJsonDocument>
FusionMusicController::FusionMusicController (QObject* parent) : HttpRequestHandler(parent)
{
    // Empty
}

void FusionMusicController::service(HttpRequest &request, HttpResponse &response)
{


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

      response.write("<select class='comboBox centerElements' id='choiceBox'>"); 
        response.write("<option value='AUX'>AUX</option>");
        response.write("<option value='FM'>FM</option>");
        response.write("<option value='AM'>AM</option>");
        response.write("<option value='Bluetooth'>Bluetooth</option>");
      response.write("</select>");

      response.write("<h2 class='dName centerElements' id='sourceTitle'>Source Type:<h2>");

      response.write("<label class='switch centerElements' id='powerSwitch' >");
        response.write("<input type='checkbox' id='switch' onclick='powerState();'/>");
        response.write("<span class='slider round'></span>");
      response.write("</label>");

      response.write("<h3 class='centerElements' id='onLabel'>OFF</h3>");

      response.write("<h3 class='dName centerElements' id='foot1'>Powered by </h3><h2 class='dName centerElements' id='foot2' style='color: #03c46a'>Fusion Entertainment</h2>");

    response.write("</div>");



    response.write("</body>");

    response.write("</html>");

}

void FusionMusicController::returnJson(HttpRequest &request, HttpResponse &response)
{

}


void FusionMusicController::returnJs(HttpRequest &request, HttpResponse &response)
{

//    response.write("", true);

    response.write("function changeName() { document.getElementById('setDeviceName').value = document.getElementById('name').innerHTML; document.getElementById('name').style.visibility = 'hidden'; document.getElementById('setDeviceName').style.visibility = 'visible'; document.getElementById('changeButton').innerHTML = 'DONE'; document.getElementById('changeButton').onclick = doneName; document.getElementById('setDeviceName').focus(); document.getElementById('setDeviceName').select(); } function doneName() { var name = document.getElementById('setDeviceName').value; if (name.length > 10) { document.getElementById('warningLabel').innerHTML = 'Warning! Name cannot be longer than 10 characters.'; document.getElementById('warningLabel').style.visibility = 'visible'; } else if (name.length == 0) { document.getElementById('warningLabel').innerHTML = 'Warning! Name must be at least one character long.'; document.getElementById('warningLabel').style.visibility = 'visible'; } else { document.getElementById('warningLabel').style.visibility = 'hidden'; document.getElementById('name').innerHTML = name; document.getElementById('setDeviceName').value = ''; document.getElementById('name').style.visibility = 'visible'; document.getElementById('setDeviceName').style.visibility = 'hidden'; document.getElementById('changeButton').innerHTML = 'CHANGE'; document.getElementById('changeButton').onclick = changeName; var formData = new FormData(); formData.append('deviceName', name); var request = new XMLHttpRequest(); request.open('POST', '/fusionMusic'); request.send(formData); } } function playPause() { var songState; if (document.getElementById('playPauseButton').innerHTML == 'Play') { songState = 'PLAYING...'; document.getElementById('playPauseButton').innerHTML = 'Pause'; } else { songState = 'PAUSED'; document.getElementById('playPauseButton').innerHTML = 'Play'; } console.log(songState); var formData = new FormData(); formData.append('songState', songState); var request = new XMLHttpRequest(); request.open('POST', '/fusionMusic'); request.send(formData); } function powerState(checkbox) { if (checkbox.checked) { document.getElementById('').innerHTML = 'OFF'; } else { document.getElementById('').innerHTML = 'ON'; } } function powerState() { if (document.getElementById('switch').checked) { document.getElementById('onLabel').innerHTML = 'ON'; document.getElementById('onLabel').style.color = '#03c46a'; } else { document.getElementById('onLabel').innerHTML = 'OFF'; document.getElementById('onLabel').style.color = '#ba3728'; } }", true);

}

void FusionMusicController::returnCSS(HttpRequest &request, HttpResponse &response)
{
    response.write("body { background-color: #7a7a7a; font-family: 'Helvetica Neue', Helvetica, Arial, sans-serif; } button, .comboBox { background-color: #03c46a; /* Green */ border: none; color: white; padding: 10px 25px; text-align: center; text-decoration: none; display: inline-block; font-size: 16px; position:absolute; top:0; right:0; } .centerElements { top: 0%; position: absolute !important; left: 0 !important; right: 0 !important; margin-left: auto !important; margin-right: auto !important; } .dName { color: #03c46a; text-align: center; font-size: 3em; width: 350px; /* Need a specific value to work */ } #moreInfoButton { width: 200px; height: 30px; color: #ffffff; font-size: 1em; text-align: center; } #setDeviceName { position: absolute; width: 250px; height: 40px; font-size: 1em; top: 13%; visibility: hidden; } #name { top: 7%; color: #ffffff; } #changeButton { top: 22%; color: #ffffff; text-align: center; width: 120px; height: 35px; } #doneButton { top: 22%; color: #ffffff; text-align: center; width: 120px; height: 35px; visibility: hidden; background-color: #03c46a; /* Green */ border: none; padding: 10px 25px; text-decoration: none; display: inline-block; font-size: 16px; } #warningLabel { top: 27%; color: #ad3c2e; text-align: center; width: 200px; height: 30px; font-size: 0.5em; visibility: hidden; } #playPauseButton { top: 35%; color: #ffffff; text-align: center; width: 150px; height: 80px; } #sourceTitle { top: 45%; } #choiceBox { top: 60%; width: 200px; height: 50px; text-align: center; /* turn it off completely */ select:active, select:hover { outline: none } /* make it red instead (with with same width and style) */ select:active, select:hover { outline-color: #03c46a; } } #powerSwitch { top: 70%; } #onLabel { top: 70%; color: #ba3728; text-align: center; font-size: 3em; width: 350px; /* Need a specific value to work */ } /* The switch - the box around the slider */ .switch { position: relative; display: inline-block; width: 60px; height: 34px; } /* Hide default HTML checkbox */ .switch input {display:none;} /* The slider */ .slider { position: absolute; cursor: pointer; top: 0; left: 0; right: 0; bottom: 0; background-color: #ccc; -webkit-transition: .4s; transition: .4s; } .slider:before { position: absolute; content: ''; height: 26px; width: 26px; left: 4px; bottom: 4px; background-color: white; -webkit-transition: .4s; transition: .4s; } input:checked + .slider { background-color: #03c46a; } input:focus + .slider { box-shadow: 0 0 1px #03c46a; } input:checked + .slider:before { -webkit-transform: translateX(26px); -ms-transform: translateX(26px); transform: translateX(26px); } /* Rounded sliders */ .slider.round { border-radius: 34px; } .slider.round:before { border-radius: 50%; } #foot1 { position: absolute; font-size: 1em; color: #000000; top: 88%; } #foot2 { position: absolute; top: 90%; font-size: 2em; }", true);
}

