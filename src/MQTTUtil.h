#ifndef MQTTUtil_h
#define MQTTUtil_h

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

class MQTTUtil
{
public:
    MQTTUtil();
    void setup();
    void listen();
    void reconnectToBroker();

private:
    const char *topic = "tvroom/ac";

    WiFiClientSecure espClient;
    PubSubClient client;
};

#endif