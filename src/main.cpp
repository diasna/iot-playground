#include <Arduino.h>
#include "WiFiUtil.h"
#include "MQTTUtil.h"

WiFiUtil wiFiUtil;
MQTTUtil mqttUtil;

std::function<void(char *, uint8_t *, unsigned int)> onMessageReceived = [](char *topic, byte *payload, unsigned int length)
{
  if ((char)payload[0] == '1')
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
  else
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
};

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  delay(10);

  Serial.println("Initializing helper...");

  wiFiUtil.setup();
  mqttUtil.setup(onMessageReceived);

  Serial.println("Done setup, turning led off...");
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop()
{
  mqttUtil.listen();
}