#include "MQTTUtil.h"

#define XSTR(x) #x
#define STR(x) XSTR(x)

MQTTUtil::MQTTUtil()
{
}

void MQTTUtil::setup(std::function<void(char*, uint8_t*, unsigned int)> callback)
{
    espClient.setFingerprint(STR(BROKER_FINGERPRINT));
    client.setClient(espClient);
    client.setServer(STR(BROKER_HOST), 8883);
    client.setCallback(callback);
}

void MQTTUtil::reconnectToBroker()
{
    while (!client.connected())
    {
        Serial.println("Attempting MQTT connection...");

        if (client.connect(STR(CLIENT_ID), STR(BROKER_USERNAME), STR(BROKER_PASSWORD)))
        {
            Serial.println("connected ");
            Serial.print(STR(CLIENT_ID));

            client.subscribe(topic);
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

void MQTTUtil::listen()
{
    if (!client.connected())
    {
        reconnectToBroker();
        
    }
    client.loop();
}