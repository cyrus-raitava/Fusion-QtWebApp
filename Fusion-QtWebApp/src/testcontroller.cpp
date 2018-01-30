#include "testcontroller.h"

testcontroller::testcontroller(QObject* parent) : HttpRequestHandler(parent)
{
    // empty
}

void testcontroller::service(HttpRequest &request, HttpResponse &response) {
    response.write("Hello World!\nIt worked! This Qt WebServer is serving up fresh text (not quite HTML yet).\n\nGood on ya!", true);
}
