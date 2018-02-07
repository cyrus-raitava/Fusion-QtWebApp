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

## For further development of the project

Accessing the URL http://localhost:8080/fusionMusic will take you to the final form of the project: that is, the HTML webpage that is generated entirely from within the webserver, with all resources (e.g JS, CSS) being held and returned internally.

It is not sensible to carry out development of the webpage and it's subsequent resources from within C++ code, within Qt Creator. Thus, for me, the only logical iterative process has been to carry out development of HTML5/JS/CSS through the creation of external files, coded from within a better suited IDE (in this case Atom). This development could then be tested and refined through the ability of the QtWebApp httpserver to serve up static webpages.

To test and view this development, edit/create files within the /docroot/files/ folder, and make pathnames for included resources relative to that position. When you are wanting to view the webpage, build and run the webserver from within Qt Creator, then access the webpage via the following URL:

http://localhost:8080/files/<\put path name relative to files folder here>

Once development of the webpage is to an accepted standard, moving of the HTML/JS/CSS to within the webserver is trivial:

1. Ensure no double quotation marks (") or comments of the form /**/ or // exist in HTML/JS/CSS resources, when copying over into within webserver. If double-quotation marks do exist, simply replace them with single quotation marks (').

2. Change relative pathnames to fit request mapping of webserver: at the top of the HTML webpage, in your src='' statement, put in the URL corresponding to the method you plan to put the CSS/JS code (e.g '/fusionMusic/fusion.js' would become the new pathname in my html, if I were to put my javascript code within a method that were called when /fusionMusic/fusion.js was requested).

3. Ensure you are pasting the relevant JS/CSS files within the right returning methods. E.g for the Fusion Music Application, paste the css code within the returnCSS() method of the FusionMusicController cpp file (and the same with the JS method). 

Once again, for questions/queries regarding the project, you can email me at:

_**cyrus.raitava@gmail.com**_

In bocca al lupo!


