/**********************************************************************************************************************
 * @file        ESP32_HTTP_File_Download.ino
 * @brief       Downloads a file from an HTTP server and stores it on an SD card.
 * @details     Connects ESP32 to Wi-Fi, opens an HTTP URL, streams the response body to an SD card file, and blinks
 *              the status LED after a successful download.
 * @author      Satish Kanawade
 * @date        20-May-2026
 * @version     1.0.0
 * @copyright : Satish Kanawade. All rights reserved.
 *********************************************************************************************************************/

#include <HTTPClient.h>
#include <SD.h>
#include <SPI.h>
#include <WiFi.h>

const char *WIFI_SSID = "YOUR_WIFI_SSID";                 // Replace with your Wi-Fi SSID.
const char *WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";         // Replace with your Wi-Fi password.
const char *DOWNLOAD_URL = "http://example.com/file.bin"; // Replace with your HTTP file URL.
const char *DOWNLOAD_DIRECTORY = "/Download";             // SD card folder used for downloaded files.
const char *DOWNLOAD_FILE_PATH = "/Download/file.bin";    // SD card destination file path.

const uint8_t LED_PIN = 2;                                // On-board LED pin for ESP32 development boards.
const uint8_t SD_CHIP_SELECT_PIN = SS;                    // Update if your SD module uses a custom CS pin.

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

// Creates the download directory on the SD card when it does not already exist.
bool ensureDownloadDirectory() {
  if (SD.exists(DOWNLOAD_DIRECTORY)) {
    return true;
  }

  Serial.println("Creating download directory on SD card.");
  return SD.mkdir(DOWNLOAD_DIRECTORY);
}

// Downloads the configured HTTP file and writes it to the SD card.
void downloadFile() {
  if (!ensureDownloadDirectory()) {
    Serial.println("Failed to create SD card download directory.");
    return;
  }

  HTTPClient http;
  Serial.print("Downloading file from: ");
  Serial.println(DOWNLOAD_URL);

  http.begin(DOWNLOAD_URL);
  http.addHeader("User-Agent", "ESP32");
  http.addHeader("Accept", "*/*");

  const int httpCode = http.GET();
  if (httpCode != HTTP_CODE_OK) {
    Serial.print("HTTP download failed, code: ");
    Serial.println(httpCode);
    http.end();
    return;
  }

  File file = SD.open(DOWNLOAD_FILE_PATH, FILE_WRITE);
  if (!file) {
    Serial.println("Failed to open destination file on SD card.");
    http.end();
    return;
  }

  WiFiClient *stream = http.getStreamPtr();
  const int contentLength = http.getSize();
  int remainingBytes = contentLength;
  size_t totalWritten = 0;
  uint8_t buffer[512];

  while (http.connected() && (remainingBytes > 0 || remainingBytes == -1)) {
    size_t availableBytes = stream->available();
    if (availableBytes > 0) {
      if (availableBytes > sizeof(buffer)) {
        availableBytes = sizeof(buffer);
      }

      const int bytesRead = stream->readBytes(buffer, availableBytes);
      if (bytesRead <= 0) {
        break;
      }

      file.write(buffer, bytesRead);
      totalWritten += bytesRead;

      if (remainingBytes > 0) {
        remainingBytes -= bytesRead;
      }
    }

    delay(1);
  }

  file.close();
  http.end();

  Serial.print("Downloaded bytes: ");
  Serial.println(totalWritten);

  if (contentLength > 0 && totalWritten != (size_t)contentLength) {
    SD.remove(DOWNLOAD_FILE_PATH);
    Serial.println("Download incomplete. Partial file removed.");
    return;
  }

  Serial.println("File downloaded and saved successfully.");
}

// Initializes serial, Wi-Fi, SD card, and starts the HTTP file download.
void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  connectToWiFi();

  if (!SD.begin(SD_CHIP_SELECT_PIN)) {
    Serial.println("SD card initialization failed.");
    return;
  }

  Serial.println("SD card initialized successfully.");
  downloadFile();
}

// Blinks the LED after the download workflow finishes.
void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
