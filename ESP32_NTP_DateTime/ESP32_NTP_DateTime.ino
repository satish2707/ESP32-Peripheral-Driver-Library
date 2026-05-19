/**********************************************************************************************************************
 * @file        ESP32_NTP_DateTime.ino
 * @brief       Reads date and time from an NTP server using ESP32.
 * @details     Connects ESP32 to Wi-Fi, synchronizes with an NTP server, and prints formatted date, time, and date-time
 *              values on the serial monitor.
 * @author      Satish Kanawade
 * @date        20-May-2026
 * @version     1.0.0
 * @copyright : Satish Kanawade. All rights reserved.
 *********************************************************************************************************************/

#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <time.h>

const char *WIFI_SSID = "YOUR_WIFI_SSID";             // Replace with your Wi-Fi SSID.
const char *WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";     // Replace with your Wi-Fi password.
const char *NTP_SERVER = "asia.pool.ntp.org";         // Replace with another NTP server if required.
const long GMT_OFFSET_SECONDS = 19800;                // India Standard Time offset: UTC +05:30.
const uint32_t UPDATE_INTERVAL_MS = 1000;             // Date/time print interval.

WiFiUDP ntpUdp;
NTPClient timeClient(ntpUdp, NTP_SERVER, GMT_OFFSET_SECONDS);
uint32_t previousUpdateMs = 0;

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

// Returns current NTP time in HH:MM:SS format.
String getCurrentTime() {
  return timeClient.getFormattedTime();
}

// Returns current NTP date in YYYY-MM-DD format.
String getCurrentDate() {
  const unsigned long epochTime = timeClient.getEpochTime();
  const time_t rawTime = (time_t)epochTime;
  struct tm *timeInfo = gmtime(&rawTime);

  char dateBuffer[11];
  snprintf(dateBuffer, sizeof(dateBuffer), "%04d-%02d-%02d", timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday);
  return String(dateBuffer);
}

// Returns current NTP date and time in YYYY-MM-DD HH:MM:SS format.
String getCurrentDateTime() {
  return getCurrentDate() + " " + getCurrentTime();
}

// Updates the NTP client and prints formatted date/time values at the configured interval.
void updateDateTime() {
  const uint32_t currentMs = millis();
  if (currentMs - previousUpdateMs < UPDATE_INTERVAL_MS) {
    return;
  }

  previousUpdateMs = currentMs;
  timeClient.update();

  Serial.print("Current date and time: ");
  Serial.println(getCurrentDateTime());
  Serial.print("Current time: ");
  Serial.println(getCurrentTime());
  Serial.print("Current date: ");
  Serial.println(getCurrentDate());
}

// Initializes serial, Wi-Fi, and the NTP client.
void setup() {
  Serial.begin(115200);
  connectToWiFi();
  timeClient.begin();
}

// Keeps the NTP date/time values updated.
void loop() {
  updateDateTime();
}
