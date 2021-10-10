#define BLYNK_TEMPLATE_ID "TMPLhJqGuRzx"
#define BLYNK_DEVICE_NAME "Quickstart Device"
#define BLYNK_AUTH_TOKEN "ziNP2lWMNVVgau6bkVhHI3ehVK2PGBAx"

#define BLYNK_PRINT Serial

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Dias";
char pass[] = "diaspinter123";

BLYNK_WRITE(V0)
{
    int value = param.asInt();
    Blynk.virtualWrite(V1, value);
}

BLYNK_CONNECTED()
{
    Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
    Blynk.setProperty(V3, "onImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
    Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

const uint16_t kIrLed = 4;

//Turn off
uint16_t rawData[199] = {4430, 4354, 574, 1596, 552, 498, 576, 1598, 552, 1596, 552, 498, 576,
                         498, 576, 1596, 554, 498, 576, 496, 576, 1596, 554, 498, 576, 498, 576,
                         1596, 552, 1596, 552, 498, 576, 1596, 554, 1596, 554, 498, 576, 498, 576,
                         1596, 554, 1596, 552, 1596, 552, 1596, 552, 1596, 552, 498, 576, 1596, 554,
                         1596, 552, 498, 576, 498, 576, 498, 576, 498, 576, 498, 578, 1594, 554, 1596,
                         552, 498, 576, 1596, 552, 498, 576, 498, 576, 498, 576, 498, 576, 498, 578, 496,
                         576, 1596, 552, 498, 576, 1596, 552, 1596, 554, 1596, 552, 1596, 554, 5166, 4428,
                         4352, 576, 1596, 554, 496, 576, 1596, 554, 1594, 554, 498, 576, 498, 576, 1596,
                         552, 498, 576, 498, 576, 1596, 552, 498, 576, 498, 576, 1596, 554, 1596, 552,
                         498, 576, 1596, 552, 1596, 552, 498, 576, 498, 576, 1596, 552, 1598, 552,
                         1596, 554, 1594, 554, 1596, 552, 498, 576, 1596, 552, 1596, 552, 498, 576,
                         498, 576, 498, 576, 498, 576, 496, 578, 1598, 550, 1598, 550, 498, 576,
                         1600, 550, 496, 578, 496, 578, 496, 576, 496, 578, 496, 578,
                         498, 576, 1600, 548, 498, 576, 1600, 548, 1600, 550, 1600, 548, 1600, 548};