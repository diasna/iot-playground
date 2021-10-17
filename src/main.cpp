#define BLYNK_TEMPLATE_ID "TMPLhJqGuRzx"
#define BLYNK_DEVICE_NAME "AC"
#define BLYNK_AUTH_TOKEN "ziNP2lWMNVVgau6bkVhHI3ehVK2PGBAx"

#define BLYNK_PRINT Serial

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <AR05TGHQ.cpp>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Dias";
char pass[] = "diaspinter123";

AR05TGHQ ac;

BLYNK_WRITE(V0)
{
    int value = param.asInt();
    Blynk.virtualWrite(V1, value);
    if (value == 0) {
        digitalWrite(LED_BUILTIN, HIGH);
    } else {
        digitalWrite(LED_BUILTIN, LOW);
    }
}

BLYNK_CONNECTED()
{
    Serial.println("Blynk Connected");
}

void setup()
{
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);

    Blynk.begin(auth, ssid, pass);

    ac = AR05TGHQ();
}

void loop()
{
    Blynk.run();
    ac.set(Mode::AUTO, 22);
}