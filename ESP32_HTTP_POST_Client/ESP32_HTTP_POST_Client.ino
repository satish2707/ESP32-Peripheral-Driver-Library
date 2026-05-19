/**********************************************************************************************************************
 * @file        ESP32_HTTP_POST_Client.ino
 * @brief       Sends an HTTP POST request from ESP32.
 * @details     Connects to Wi-Fi, opens a TCP connection to a configured HTTP server, sends a JSON POST payload, and
 *              prints the server response on the serial monitor.
 * @author      Satish Kanawade
 * @date        20-May-2026
 * @version     1.0.0
 * @copyright : Satish Kanawade. All rights reserved.
 *********************************************************************************************************************/

#include <WiFi.h>
#include <string.h>

const char *WIFI_SSID = "YOUR_WIFI_SSID";             // Replace with your Wi-Fi SSID.
const char *WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";     // Replace with your Wi-Fi password.
const char *SERVER_HOST = "example.com";              // Replace with your HTTP server host.
const uint16_t SERVER_PORT = 80;                      // Replace if your server uses another HTTP port.
const char *POST_ENDPOINT = "/data/student";          // Replace with your POST endpoint.
const char *JSON_PAYLOAD = "{\"name\":\"esp32\",\"age\":\"1\"}";

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

// Sends one HTTP POST request and prints the complete server response.
void sendHttpPostRequest() {
  WiFiClient client;

  if (!client.connect(SERVER_HOST, SERVER_PORT)) {
    Serial.println("Connection to HTTP server failed.");
    return;
  }

  Serial.println("Connected to HTTP server.");
  client.print("POST ");
  client.print(POST_ENDPOINT);
  client.println(" HTTP/1.1");
  client.print("Host: ");
  client.println(SERVER_HOST);
  client.println("Content-Type: application/json");
  client.print("Content-Length: ");
  client.println(strlen(JSON_PAYLOAD));
  client.println("Connection: close");
  client.println();
  client.println(JSON_PAYLOAD);

  while (client.connected() || client.available()) {
    if (client.available()) {
      Serial.println(client.readStringUntil('\n'));
    }
  }

  client.stop();
  Serial.println("Disconnected from HTTP server.");
}

// Initializes serial and Wi-Fi.
void setup() {
  Serial.begin(115200);
  connectToWiFi();
}

// Sends the POST request periodically.
void loop() {
  sendHttpPostRequest();
  delay(5000);
}
