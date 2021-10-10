#include <main.h>

BlynkTimer timer;

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
    Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
    Blynk.setProperty(V3, "onImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
    Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

void timerEvent()
{
    Blynk.virtualWrite(V2, millis() / 1000);
}

void setup()
{
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);
    timer.setInterval(1000L, timerEvent);

    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    Blynk.run();
    timer.run();
}