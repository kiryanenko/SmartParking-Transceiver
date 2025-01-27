#ifndef RECEIVEMESSAGEHANDLER_H
#define RECEIVEMESSAGEHANDLER_H

#include <QtCore>
#include <QByteArray>

class AbstractReceiveMessageHandler : public QObject
{
    Q_OBJECT

public:
    AbstractReceiveMessageHandler(QObject *parent = 0);
    virtual ~AbstractReceiveMessageHandler();

    virtual void onRecv(QByteArray data) {}
    virtual void onParkingStatus(quint32 id, quint8 place, bool isFree) {}
    virtual void onInit(quint32 id,
                        quint16 samplingPeriod,
                        quint16 sendingPeriod,
                        quint16 dayCost,
                        quint16 nightCost,
                        quint32 dayStartTime,
                        quint32 nightStartTime) {}
    virtual void onPayment(quint32 id, quint8 place, quint32 bookedTime, quint16 payment, quint16 totalCost) {}

    virtual void onBook(quint32 sensor, quint8 place, quint32 bookedTime) {}
    virtual void onSetSensorSettings(quint32 sensor,
                                     quint16 samplingPeriod,
                                     quint16 sendingPeriod,
                                     quint16 dayCost,
                                     quint16 nightCost,
                                     quint32 dayStartTime,
                                     quint32 nightStartTime) {}
};

#endif // RECEIVEMESSAGEHANDLER_H
