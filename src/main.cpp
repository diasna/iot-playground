#include <Arduino.h>
#include "WiFiUtil.h"
#include "MQTTUtil.h"

WiFiUtil wiFiUtil;
MQTTUtil mqttUtil;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  delay(10);

  Serial.println("Initializing helper...");

  wiFiUtil.setup();
  mqttUtil.setup();

  Serial.println("Done setup, turning led off...");
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop()
{
  mqttUtil.listen();
}