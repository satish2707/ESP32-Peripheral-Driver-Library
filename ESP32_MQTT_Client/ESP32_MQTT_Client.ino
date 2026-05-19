/**********************************************************************************************************************
 * @file        ESP32_MQTT_Client.ino
 * @brief       Connects ESP32 to Wi-Fi and an MQTT broker.
 * @details     Uses the PubSubClient library to connect to an MQTT broker, subscribe to a topic, and print received
 *              payload data on the serial monitor.
 * @author      Satish Kanawade
 * @date        20-May-2026
 * @version     1.0.0
 * @copyright : Satish Kanawade. All rights reserved.
 *********************************************************************************************************************/

#include <PubSubClient.h>
#include <WiFi.h>

const char *WIFI_SSID = "YOUR_WIFI_SSID";               // Replace with your Wi-Fi SSID.
const char *WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";       // Replace with your Wi-Fi password.

const char *MQTT_SERVER = "broker.example.com";         // Replace with your MQTT broker host or IP address.
const uint16_t MQTT_PORT = 1883;                        // Replace if your broker uses another port.
const char *MQTT_USERNAME = "YOUR_MQTT_USERNAME";       // Replace with your MQTT username.
const char *MQTT_PASSWORD = "YOUR_MQTT_PASSWORD";       // Replace with your MQTT password.
const char *MQTT_CLIENT_ID = "ESP32Client";             // Replace with a unique client ID if required.
const char *MQTT_TOPIC = "esp32/demo";                  // Replace with your publish/subscribe topic.

WiFiClient espClient;
PubSubClient mqttClient(espClient);

// Connects ESP32 to the configured Wi-Fi network.
void connectToWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Wi-Fi connected, IP address: ");
  Serial.println(WiFi.localIP());
}

// Reconnects to the MQTT broker and subscribes to the configured topic.
void reconnectToMqtt() {
  while (!mqttClient.connected()) {
    Serial.print("Connecting to MQTT broker...");

    if (mqttClient.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
      Serial.println("connected.");
      mqttClient.subscribe(MQTT_TOPIC);
      Serial.print("Subscribed topic: ");
      Serial.println(MQTT_TOPIC);
    } else {
      Serial.print("failed, state=");
      Serial.print(mqttClient.state());
      Serial.println(". Retrying in 5 seconds.");
      delay(5000);
    }
  }
}

// Handles incoming MQTT payload data from subscribed topics.
void mqttCallback(char *topic, byte *payload, unsigned int length) {
  Serial.print("MQTT message from ");
  Serial.print(topic);
  Serial.print(": ");

  for (unsigned int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }

  Serial.println();
}

// Initializes serial, Wi-Fi, and the MQTT client.
void setup() {
  Serial.begin(115200);
  connectToWiFi();

  mqttClient.setServer(MQTT_SERVER, MQTT_PORT);
  mqttClient.setCallback(mqttCallback);
}

// Keeps the MQTT client connected and processes incoming packets.
void loop() {
  if (!mqttClient.connected()) {
    reconnectToMqtt();
  }

  mqttClient.loop();
}
