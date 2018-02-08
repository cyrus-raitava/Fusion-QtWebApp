#include "fusionlinktcpmessage.h"

FusionLinkTcpMessage::FusionLinkTcpMessage()
{
    // Empty
}

QByteArray FusionLinkTcpMessage::commandEncode(QByteArray &command)
{
    QByteArray output;

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


QByteArray FusionLinkTcpMessage::checkSumCalc(QByteArray &message)
{

}

void FusionLinkTcpMessage::byteMerger(QByteArray &command, QByteArray &message)
{

    QByteArray outputPacket;

    // Set header byte
    outputPacket[0] = 0xff;



    QByteArray messageLength[4];




}


