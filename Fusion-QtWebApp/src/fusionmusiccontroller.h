#ifndef FUSIONMUSICCONTROLLER_H
#define FUSIONMUSICCONTROLLER_H

#include "httprequesthandler.h"
#include <QByteArray>

using namespace stefanfrings;

class FusionMusicController : public HttpRequestHandler
{
    Q_OBJECT
public:
    FusionMusicController(QObject* parent=0);
    void service(HttpRequest &request, HttpResponse &response);
    void returnJson(HttpRequest &request, HttpResponse &response);
    void returnJs(HttpRequest &request, HttpResponse &response);
    void returnCSS(HttpRequest &request, HttpResponse &response);
    void setDeviceName(HttpRequest &request, HttpResponse &response);

    void byteMerger(QByteArray &command, QByteArray &message);
    QByteArray commandEncode(QByteArray &command);

    QByteArray fapiSetSourceType(QByteArray &sourceID);
    QByteArray fapiSetDeviceName(QByteArray &deviceName);
    QByteArray fapiSetPowerState(QByteArray &state);
    QByteArray fapiSetMediaState(QByteArray &songState);

    QByteArray sizeHexBytes(int size);

    QByteArray checkSumXor(QByteArray &input);

    int messageSizeMapping(QByteArray &command, QByteArray &message);

    void printTcpPacket(QByteArray &input);
private:

};

#endif // FUSIONMUSICCONTROLLER_H
