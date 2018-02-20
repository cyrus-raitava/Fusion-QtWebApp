#ifndef FUSIONHEXENCODE_H
#define FUSIONHEXENCODE_H

#include "httprequesthandler.h"
#include <QByteArray>
#include <iostream>

using namespace stefanfrings;

class FusionHexEncode : public HttpRequestHandler
{
    Q_OBJECT
public:
    FusionHexEncode(QObject* parent=0);


    // Function that uses smaller functions below, to construct tcp packet in desired format, off of interaction from webpage (e.g packet for setDeviceName, etc)
    static void byteMerger(QByteArray &command, QByteArray &message);

    // Function to provide mapping of command from webpage, to corresponding command bytes
    static QByteArray commandEncode(QByteArray &command);

    // Function that sort out size of the inner Fusion-Link message, and appends the 'size' bytes onto the header byte.
    static QByteArray sizeHexBytes(int size);

    // Function that maps a command and it's message, to a corresponding definitive size, which may need to be calculated depending on input message size, or can be logically deduced from specifications
    static int messageSizeMapping(QByteArray &command, QByteArray &message);


    // Functions that map the webpage interaction, to a corresponding byte array, representing that interaction (e.g fapiSetDeviceName, when user changes device name on display).
    static QByteArray fapiGetState();
    static QByteArray fapiSetSourceType(QByteArray &sourceID);
    static QByteArray fapiSetDeviceName(QByteArray &deviceName);
    static QByteArray fapiSetPowerState(QByteArray &state);
    static QByteArray fapiSetMediaState(QByteArray &songState);

    // Calculates XOR checksum byte of inner Fusion-Link message, and appends it onto the rest of the message
    static QByteArray checkSumXor(QByteArray &input);

    // Function to print tcp packet, for interaction with terminal interface
    static void printTcpPacket(QByteArray &input);

    // Hex Byte Array validator (checks structure of input message), for input from terminal interface
    static void hexDecoderCheck();
    static void sizeCheck(QByteArray &sizeBytes);




};

#endif // FUSIONHEXENCODE_H
