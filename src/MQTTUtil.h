#ifndef MQTTUtil_h
#define MQTTUtil_h

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

class MQTTUtil
{
public:
    MQTTUtil();
    void setup(std::function<void(char*, uint8_t*, unsigned int)> callback);
    void listen();
    void reconnectToBroker();

private:
    const char *topic = "tvroom/ac";

    WiFiClientSecure espClient;
    PubSubClient client;
};

#endif