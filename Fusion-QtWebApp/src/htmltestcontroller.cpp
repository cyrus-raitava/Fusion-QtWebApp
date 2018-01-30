#include "htmltestcontroller.h"

htmlTestController::htmlTestController(QObject* parent) : HttpRequestHandler(parent)
{
    //Empty
}

void htmlTestController::service(HttpRequest &request, HttpResponse &response)
{
    response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");
    response.write("<html><body>");

    response.write("<h1>Congratulations! This Qt Webserver is serving some damn good HTML webpages.");
    response.write("<br>");
    response.write("<h2>Good on you! You're a star.</h2>");

    response.write("</body></html>", true);
}
