#include "LoRaConnection.h"

LoRaConnection::LoRaConnection(QList<quint64> &sensors, AbstractReceiveMessageHandler *handler, int frequency, uint16_t timeout) :
    m_rf95(RF_CS_PIN, RF_IRQ_PIN), Driver(sensors, handler)
{
    m_timeout = timeout;

    if (!bcm2835_init()) {
      qCritical() << "bcm2835_init() Failed";
    }

    pinMode(RF_IRQ_PIN, INPUT);
    bcm2835_gpio_set_pud(RF_IRQ_PIN, BCM2835_GPIO_PUD_DOWN);
    // Now we can enable Rising edge detection
    bcm2835_gpio_ren(RF_IRQ_PIN);

    pinMode(RF_RST_PIN, OUTPUT);
    digitalWrite(RF_RST_PIN, LOW );
    bcm2835_delay(150);
    digitalWrite(RF_RST_PIN, HIGH );
    bcm2835_delay(100);

    m_rf95.init();
    m_rf95.setFrequency(frequency);
    m_rf95.setTxPower(14, false);
    m_rf95.setPromiscuous(true);
}

LoRaConnection::~LoRaConnection()
{
}

bool LoRaConnection::send(const uint8_t *data, uint8_t size)
{
    m_rf95.send(data, size);
    const auto isSend = m_rf95.waitPacketSent();
    return isSend;
}

bool LoRaConnection::available()
{
    return m_rf95.available();
}

QByteArray LoRaConnection::recv()
{
    uint8_t *buf = new uint8_t[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = RH_RF95_MAX_MESSAGE_LEN;
    m_rf95.recv(buf, &len);
    return QByteArray((char *) buf, len);
}