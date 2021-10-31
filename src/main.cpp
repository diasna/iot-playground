#include <Arduino.h>
#include "WiFiUtil.h"
#include "MQTTUtil.h"

WiFiUtil wiFiUtil;
MQTTUtil mqttUtil;

uint8_t PINOUT_LED_WHITE = 4;
uint8_t PINOUT_LED_YELLOW = 5;

char state;

std::function<void(char *, uint8_t *, unsigned int)> onMessageReceived = [](char *topic, byte *payload, unsigned int length)
{
  if ((char)payload[0] == '+')
  {
    // ON
    digitalWrite(PINOUT_LED_WHITE, LOW);
    digitalWrite(PINOUT_LED_YELLOW, HIGH);
    state = 'y';
  }
  else if ((char)payload[0] == '-')
  {
    // OFF
    digitalWrite(PINOUT_LED_WHITE, LOW);
    digitalWrite(PINOUT_LED_YELLOW, LOW);
    state = 'y';
  }
  else if ((char)payload[0] == 'y')
  {
    // YELLOW
    digitalWrite(PINOUT_LED_WHITE, LOW);
    digitalWrite(PINOUT_LED_YELLOW, HIGH);
    state = 'y';
  }
  else if ((char)payload[0] == 'w')
  {
    // WHITE
    digitalWrite(PINOUT_LED_WHITE, HIGH);
    digitalWrite(PINOUT_LED_YELLOW, LOW);
    state = 'w';
  }
  else
  {
    int val = ((char)payload[0]);
    if (state == 'y')
    {
      analogWrite(PINOUT_LED_YELLOW, val);
    }
    else
    {
      analogWrite(PINOUT_LED_WHITE, val);
    }
  }
};

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PINOUT_LED_WHITE, OUTPUT);
  pinMode(PINOUT_LED_YELLOW, OUTPUT);

  Serial.begin(115200);
  delay(10);

  Serial.println("Initializing helper...");

  wiFiUtil.setup();
  mqttUtil.setup(onMessageReceived);

  Serial.println("Done setup, turning led off...");
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);

  digitalWrite(PINOUT_LED_WHITE, HIGH);
  digitalWrite(PINOUT_LED_YELLOW, HIGH);
}

void loop()
{
  mqttUtil.listen();
}