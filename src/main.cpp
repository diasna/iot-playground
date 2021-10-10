#include <main.h>

BlynkTimer timer;

void timerEvent()
{
    Blynk.virtualWrite(V2, millis() / 1000);
}

void setup()
{
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);
    timer.setInterval(1000L, timerEvent);
}

void loop()
{
    Blynk.run();
    timer.run();
}