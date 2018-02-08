#ifndef FUSIONLINKTCPMESSAGE_H
#define FUSIONLINKTCPMESSAGE_H

#include <QByteArray>


class FusionLinkTcpMessage
{
public:
    FusionLinkTcpMessage();

    QByteArray commandEncode(QByteArray &command);

    QByteArray checkSumCalc(QByteArray &message);

    void byteMerger(QByteArray &command, QByteArray &message);


};

#endif // FUSIONLINKTCPMESSAGE_H
