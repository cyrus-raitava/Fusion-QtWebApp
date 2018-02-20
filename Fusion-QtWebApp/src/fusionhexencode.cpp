#include "fusionhexencode.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QtEndian>
#include <iostream>
#include <QString>

FusionHexEncode::FusionHexEncode(QObject* parent) : HttpRequestHandler(parent)
{
    //Empty
}





/**
 * @brief function that maps fapiCommand to corresponding little Endian encoding of command bytes ID
 * @param command
 * @return two-bytes QByteArray, containing formatting of command
 */
QByteArray FusionHexEncode::commandEncode(QByteArray &command)
{
    QByteArray output(2, 0);

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



/**
 * @brief command that uses all the other individual formatting functions, to concatenate and print out the QByteArray, for the corresponding interaction with the webpage
 * @param command - the fapi Command, which determines how the QByteArray is formatted/written, and how the message variable is read
 * @param message - the actual content of the message itself, containing flags (e.g on/off, deviceName etc)
 */
void FusionHexEncode::byteMerger(QByteArray &command, QByteArray &message)
{

    QByteArray outputPacket;

    // Set header byte
    outputPacket[0] = 0xff;


    // Set message length bytes
    QByteArray messageLength;




    qDebug() << "THE SIZE OF THE MESSAGE FOR THE: " << command << "COMMAND, IS: " << messageSizeMapping(command, message) << endl;

    messageLength = sizeHexBytes(messageSizeMapping(command, message));

    outputPacket[1] = messageLength[0];
    outputPacket[2] = messageLength[1];


    // Set the fourth and fifth command bytes
    QByteArray commandCode = commandEncode(command);
    outputPacket[3] = commandCode[0];
    outputPacket[4] = commandCode[1];





    QByteArray encodedMessage;

    if (command == "fapiGetState") {

    } else if (command == "fapiSetDeviceName") {
        encodedMessage = fapiSetDeviceName(message);
    } else if (command == "fapiSetPowerState") {
        encodedMessage = fapiSetPowerState(message);
    } else if (command == "fapiSource") {

    } else if (command == "fapiSetSource") {

    } else if (command == "fapiSetMedia") {
        encodedMessage = fapiSetMediaState(message);
    } else {
        qDebug() << "NO VALID COMMAND IDENTIFIED" << endl;
    }

    outputPacket.insert(5, encodedMessage);




    // Create checksum byte, to append on end of outputPacket

    QByteArray checkSum;

    encodedMessage.prepend(commandCode);


    checkSum = checkSumXor(encodedMessage);

    outputPacket.append(checkSum);

    qDebug() << "YOUR CHOSEN ACTION CALLED THE COMMAND: " << command << "PRODUCING THE FOLLOWING TCP PACKET TO SEND TO THE FUSBUS:" << endl;

    printTcpPacket(outputPacket);


}


int FusionHexEncode::messageSizeMapping(QByteArray &command, QByteArray &message)
{
    int messageSize;

    if (command == "fapiGetState") {

    } else if (command == "fapiSetDeviceName") {
        // Size is input string, +1 for the leading byte for string size
        messageSize = message.size() + 1;
    } else if (command == "fapiSetPowerState") {
        // Size of the message here is always one flag, representing ON or OFF
        messageSize = 1;
    } else if (command == "fapiSource") {

    } else if (command == "fapiSetSource") {

    } else if (command == "fapiSetMedia") {
        // Message itself here consists of two uint8 flags
        messageSize = 2;
    } else {
        messageSize = -2;
    }

    // Add two to message length, to signify how message length includes command bytes as well
    return messageSize + 2;
}

/**
 * @brief function to find and return the size of the message itself, in the desired format
 * @param size takes in an int size of the message
 * @return two byte array, of the size in hex form
 */
QByteArray FusionHexEncode::sizeHexBytes(int size)
{
    QByteArray result(2, 0);

    QString hexNum = QString().number(size, 16);


    if (hexNum.size() == 1) {
        hexNum.prepend("000");
    } else if (hexNum.size() == 2) {
        hexNum.prepend("00");
    } else if (hexNum.size() == 3) {
        hexNum.prepend("0");
    } else {

    }

    QString temp = (QString)hexNum[0];
    temp.append(hexNum[1]);

    hexNum[0] = hexNum[2];
    hexNum[1] = hexNum[3];
    hexNum[2] = temp[0];
    hexNum[3] = temp[1];

    result = QByteArray::fromHex(hexNum.toLatin1());

    return result;
}

/**
 * @brief Function that maps input parameter of Source Type, to hex byte array to output
 * @param sourceID
 * @return hex QByteArray
 */
QByteArray FusionHexEncode::fapiSetSourceType(QByteArray &sourceID)
{
    QByteArray hexSourceType;

    if (sourceID == "AM") {

    } else if (sourceID == "FM") {

    } else if (sourceID == "AUX") {

    } else if (sourceID == "iPod") {

    } else if (sourceID == "Bluetooth") {

    } else {

    }

    return QByteArray("arbitrary returning array");


}

/**
 * @brief Function that returns hex QByteArray encoding of deviceName
 * @param deviceName
 * @return hex QByteArray
 */
QByteArray FusionHexEncode::fapiSetDeviceName(QByteArray &deviceName)
{

    // messageLength is nameLength + 1, to account for leading length byte; trailing null terminator is automatically accounted for by QByteArray
    int messageLength = deviceName.size() + 1;

    QByteArray message(messageLength, 0);

    message[0] = messageLength;

    for (int i = 0; i < deviceName.size(); i++)
    {
        message[i + 1] = deviceName[i];
    }

    return message;
}

/**
 * @brief FusionHexEncode::fapiSetMediaState
 * @param sourceID
 * @param songState
 * @return
 */
QByteArray FusionHexEncode::fapiSetMediaState(QByteArray &songState)
{

    QByteArray result;

    // For now, set Source ID to just be 1:
    result[0] = 0x01;

    if (songState == "PLAYING") {
        result[1] = 0x01;
    } else if (songState == "PAUSED") {
        result[1] = 0x02;
    } else {
        qDebug() << "fapiSetMediaState() ERROR: neither PAUSED/PLAYING ACKNOWLEDGED" << endl;
    }

    return result;

}


/**
 * @brief function that can be used to map 'ON'/'OFF' state of webpage UI, with corresponding on/off flag for fapiSetPowerState command
 * @param state
 * @return QByte Array of length 1, either 0x01, or 0x02
 */
QByteArray FusionHexEncode::fapiSetPowerState(QByteArray &state)
{
    // Note ternary operator could've been used here instead, but verboseness is to help with debugging
    QByteArray powerState(1, 0);

    if (state == "ON")
    {
        powerState[0] = 0x01;

    } else if (state == "OFF")
    {
        powerState[0] = 0x02;
    } else {
       qDebug() << "ERROR! Request is neither ON nor OFF." << endl;
    }



    return powerState;
}


/**
 * @brief function that runs through input QByteArray, reads each array element, and calculates a running XOR checksum, to append to the end of the over-arching TCP packet
 * @param input
 * @return QByteArray of length one, containing XOR checksum byte.
 */
QByteArray FusionHexEncode::checkSumXor(QByteArray &input)
{
    int XOR = 0;
    int i;

    QByteArray result;

    for (i = 0; i <= input.size(); i++)
    {
        XOR ^= input[i];

    }


    result[0] = XOR;

    return result;

}


/**
 * @brief function used to print the formed tcp packet. Replace this with send() function, once implemented (to send output packet to audio server).
 * @param input
 */
void FusionHexEncode::printTcpPacket(QByteArray &input)
{
    QByteArray hexInput = input.toHex();

    QByteArray output;

    int count = 0;


    for (int i = 0; i < hexInput.size(); i+=2)
    {
        qDebug() << "0x" << hexInput[i] << hexInput[i + 1] << endl;

    }

}






void FusionHexEncode::hexDecoderCheck()
{

    QByteArray qCommand;
    char command[256];

    qDebug() << "ENTER THE HEX CODE TO VALIDATE: " << endl;

    std::cin.getline(command,256);

    qCommand = QByteArray::fromHex(command);

    QByteArray sizeBytes;
    sizeBytes[0] = qCommand.toHex()[2];

    qDebug() << "qCommand is: " << qCommand << endl;

    qDebug() << "qCommand::toHex() is: " << qCommand.toHex() << endl;

    qDebug() << "qCommand::toHex()[0] is: " << qCommand.toHex()[0] << endl;

    qDebug() << "qCommand::toHex()[1] is: " << qCommand.toHex()[1] << endl;

    qDebug() << "qCommand::toHex()[2] is: " << qCommand.toHex()[2] << endl;


    qDebug() << "Length bytes from qCommand are: " << command[2] << command[3] << endl;

    qDebug() << "The length of qCommand::toHex() is: " << qCommand.toHex().size() << endl;

    qDebug() << "The length of qCommand::toHex()/2 is: " << qCommand.toHex().size()/2 << endl;



    // validate header byte
//    if (qCommand[0] != 0xff) {
//        qDebug() << "INVALID COMMAND: HEADER BYTE WRONG" << endl;
//        return;
//    }


    // isolate message size info from packet, accounting for little-endian format
    QString hexLength;
    hexLength = QString::fromLatin1(qCommand.toHex().mid(2, 4));
    QString temp = hexLength.mid(2, 2);
    temp.append(hexLength.mid(0,2));
    hexLength = temp;
    qDebug() << "hexLength is: " << hexLength << endl;
    qDebug() << "temp is: " << temp << endl;
    bool ok;
    int size = hexLength.toInt(&ok, 16);

    //qDebug() << "size is: " << size << endl;

    if (size != (qCommand.size() - 4)) {
        qDebug() << "WARNING. SIZE BYTES DO NOT REPRESENT ACTUAL SIZE." << endl;
        qDebug() << "SIZE BYTES YIELD SIZE OF: " << size << endl;
        qDebug() << "ACTUAL SIZE FROM .size(): " << (qCommand.size() - 4) << endl;
    }


    QString hexCommand;
    //hexCommand = QString::fromLatin1(qCommand.toHex().mid());





}

void FusionHexEncode::sizeCheck(QByteArray &sizeBytes)
{

}

