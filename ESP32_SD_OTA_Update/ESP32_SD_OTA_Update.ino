/**********************************************************************************************************************
 * @file        ESP32_SD_OTA_Update.ino
 * @brief       Updates ESP32 firmware from a binary file stored on an SD card.
 * @details     Looks for `firmware.bin` on the SD card, writes the binary to flash using the Update library, removes
 *              the firmware file after a successful update, and restarts the ESP32.
 * @author      Satish Kanawade
 * @date        20-May-2026
 * @version     1.0.0
 * @copyright : Satish Kanawade. All rights reserved.
 *********************************************************************************************************************/

#include <SD.h>
#include <SPI.h>
#include <Update.h>

const uint8_t LED_PIN = 2;                         // On-board LED pin for ESP32 development boards.
const uint8_t SD_CHIP_SELECT_PIN = SS;             // Update if your SD module uses a custom CS pin.
const char *FIRMWARE_FILE_PATH = "/firmware.bin";  // Firmware binary expected on the SD card.

// Prints OTA update progress on the serial monitor.
void progressCallback(size_t currentSize, size_t totalSize) {
  Serial.printf("OTA progress: %u of %u bytes\r\n", currentSize, totalSize);
}

// Performs the SD-card firmware update when a firmware file is available.
void performFirmwareUpdate() {
  File firmware = SD.open(FIRMWARE_FILE_PATH, FILE_READ);
  if (!firmware) {
    Serial.println("No firmware file found on SD card.");
    return;
  }

  Serial.println("Firmware file found. Starting OTA update.");
  Update.onProgress(progressCallback);

  const size_t firmwareSize = firmware.size();

  if (!Update.begin(firmwareSize, U_FLASH)) {
    Serial.println("Unable to start OTA update.");
    firmware.close();
    return;
  }

  const size_t writtenBytes = Update.writeStream(firmware);
  firmware.close();

  if (writtenBytes != firmwareSize) {
    Serial.println("OTA write size mismatch.");
    return;
  }

  if (!Update.end()) {
    Serial.print("OTA update error: ");
    Serial.println(Update.getError());
    return;
  }

  Serial.println("OTA update completed successfully.");

  if (SD.remove(FIRMWARE_FILE_PATH)) {
    Serial.println("Firmware file removed from SD card.");
  } else {
    Serial.println("Firmware file removal failed.");
  }

  delay(1000);
  ESP.restart();
}

// Initializes serial, LED GPIO, SD card, and starts the firmware update check.
void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  if (!SD.begin(SD_CHIP_SELECT_PIN)) {
    Serial.println("SD card initialization failed.");
    return;
  }

  Serial.println("SD card initialized successfully.");
  performFirmwareUpdate();
}

// Blinks the LED when no update is available or after the update check finishes.
void loop() {
  Serial.println("Application running.");
  digitalWrite(LED_PIN, HIGH);
  delay(2000);
  digitalWrite(LED_PIN, LOW);
  delay(2000);
}
