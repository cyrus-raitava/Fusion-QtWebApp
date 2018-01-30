# Fusion-QtWebApp

My internship project for the summer of 2018.

## Description

This is a current version of the Software Engineering internship project I have been given to complete over the summer. 

The task is essentially to create an **embedded webserver/web-application, that is to communicate with a separate, locally-hosted server over TCP/IP, utilising a company-written API to request specific datasets**. 

The entire application is then to use this data to produce dynamic HTML5 webpages to be delivered to a client, with **real-time data being transmitted via a websocket** from the webserver to the browser. Whether the HTML5 webpage is generated more on the server-side, or more on the client-side, is yet to be decided.

The project is written primarily in C++ within the Qt Framework, alongside HTML and Javascript, with data possibly being temporarily stored in the widely-used JSON format. 


The QtWebApp library has been used within this project, developed by [Stefan Frings](http://stefanfrings.de/qtwebapp/index-en.html), in accordance with the LGPL license attached.

A tutorial for his QtWebApp library can be found [here](http://stefanfrings.de/qtwebapp/tutorial/index.html).

For questions/queries regarding the project, you can email me at:

_**cyrus.raitava@gmail.com**_

Hope you find it interesting!

## How to run the project in a local environment

This is for those of you who want to run the project in your own local environment! Note this setup process is known to work for Ubuntu, and other OS have not been tested yet.

To get started, first please ensure **Qt Creator (4.5.0)** is installed on your machine.

Following this, clone/download the repository, and load the .pro file in Qt Creator, allowing the IDE to configure the project for you. Once this has been done, re-build the project, and run it.

Open up a standard browser now (e.g Google Chrome/Mozilla Firefox), and type in the address bar any of the following, to test different aspects of the webserver are working:

http://localhost:8080/	-This tests that the webserver is actually working, and can serve things to a client.

http://localhost:8080/htmlTest	-This tests that the webserver can send html files, to be rendered by the client.

http://localhost:8080/templateExample	-This tests that the webserver can actually generate and send an html template to the client (you can edit the server code to fill in placeholders within the template, creating 'dynamic' html webpages, determined at run-time).

NOTE: if for any reason the project fails to build properly, perhaps try **copying the /etc folder** (found within the repository), and pasting it _within_ the build folder, generated after your first attempt at running the project. Re-build the project, and run again.




