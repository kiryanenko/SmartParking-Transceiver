#include "SerialConnection.h"
#include <QDataStream>

#include <QDebug>

SerialConnection::SerialConnection(QString portName, AbstractReceiveMessageHandler *handler) :
	Driver(handler)
{
    qInfo() << "Connect to serial port: " << portName;
    m_serial.setPortName(portName);
    m_serial.setBaudRate(QSerialPort::Baud9600);
    m_serial.open(QIODevice::ReadWrite);
}


SerialConnection::~SerialConnection()
{
    m_serial.close();
}


bool SerialConnection::send(const uint8_t* data, const uint8_t size)
{
    QByteArray dataToSend((char*) &size, sizeof(size));
    dataToSend.append((char*) data, size);

qDebug() << dataToSend;

    auto sendedCount = m_serial.write(dataToSend);
    return sendedCount == size;
}


bool SerialConnection::available()
{
    if (!m_serial.isOpen()) {
        qFatal("Serial port is closed.");
        exit(1);
        return false;
    }

    auto available = m_serial.bytesAvailable();

    if (available == 0) {
        return false;
    }

    uint8_t len;
    m_serial.peek((char *) &len, sizeof(len));

    if (len == '[') {
        if (m_serial.canReadLine()) {
            qDebug() << m_serial.readLine();
        }
        return false;
    }

    // Формат пакета: |size(data)|data|\r\n|
    auto pocketSize = len + sizeof(len) + POCKET_END.size();
    if (available >= pocketSize) {
        auto buf = m_serial.peek(pocketSize);
        if (!buf.endsWith(POCKET_END)) {
            qCritical() << "Bad serial pocket: " << buf;
            m_serial.clear();
            return false;
        }
    }

    return true;
}


QByteArray SerialConnection::recv()
{
    uint8_t len;
    m_serial.read((char *) &len, sizeof(len));
    auto data = m_serial.read(len);
    m_serial.read(POCKET_END.size());
    return data;
}
