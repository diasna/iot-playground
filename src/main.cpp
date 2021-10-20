#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <AR05TGHQ.cpp>
#include <PubSubClient.h>
#include <properties.cpp>

WiFiClientSecure espClient;
PubSubClient client(espClient);

// AR05TGHQ ac;

void wifi_setup()
{
    delay(10);

    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    randomSeed(micros());

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void onMessageReceived(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    for (int i = 0; i < length; i++)
    {
        Serial.print((char)payload[i]);
    }
    Serial.println();

    if ((char)payload[0] == '1')
    {
        digitalWrite(LED_BUILTIN, LOW);
    }
    else
    {
        digitalWrite(LED_BUILTIN, HIGH);
    }
}

void reconnectToBroker()
{
    while (!client.connected())
    {
        Serial.println("Attempting MQTT connection...");

        if (client.connect(mqtt_client_id, mqtt_username, mqtt_password))
        {
            Serial.println("connected ");
            Serial.print(mqtt_client_id);

            client.subscribe(mqtt_topic);
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

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(115200);

    wifi_setup();

    espClient.setFingerprint(fingerprint);

    client.setServer(mqtt_server, 8883);
    client.setCallback(onMessageReceived);

    Serial.println("Done setup, turning off led...");

    digitalWrite(LED_BUILTIN, HIGH);

    // ac = AR05TGHQ();
}

void loop()
{
    if (!client.connected())
    {
        reconnectToBroker();
    }
    client.loop();

    // ac.set(Mode::AUTO, 22);
}