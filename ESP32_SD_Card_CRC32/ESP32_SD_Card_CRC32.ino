/**********************************************************************************************************************
 * @file        ESP32_SD_Card_CRC32.ino
 * @brief       Calculates CRC32 checksum for a file stored on an SD card.
 * @details     Opens a configured file from the SD card, streams the bytes through the CRC32 library, and prints the
 *              final checksum on the serial monitor.
 * @author      Satish Kanawade
 * @date        20-May-2026
 * @version     1.0.0
 * @copyright : Satish Kanawade. All rights reserved.
 *********************************************************************************************************************/

#include <CRC32.h>
#include <SD.h>
#include <SPI.h>

const uint8_t SD_CHIP_SELECT_PIN = SS;          // Update if your SD module uses a custom CS pin.
const char *CRC_FILE_PATH = "/firmware.bin";    // Update this path to calculate CRC for another file.

// Initializes serial, mounts the SD card, calculates the file CRC32, and prints the result.
void setup() {
  Serial.begin(115200);

  if (!SD.begin(SD_CHIP_SELECT_PIN)) {
    Serial.println("SD card initialization failed.");
    return;
  }

  Serial.println("SD card initialized successfully.");

  File file = SD.open(CRC_FILE_PATH, FILE_READ);
  if (!file) {
    Serial.println("Failed to open CRC input file.");
    return;
  }

  CRC32 crc;
  while (file.available()) {
    crc.update(file.read());
  }
  file.close();

  const uint32_t checksum = crc.finalize();

  Serial.print("CRC32 of ");
  Serial.print(CRC_FILE_PATH);
  Serial.print(": 0x");
  Serial.println(checksum, HEX);
}

// Keeps the sketch idle after the one-time CRC32 calculation.
void loop() {
}
