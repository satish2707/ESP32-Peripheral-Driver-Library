# ESP32 HTTP File Download

This sketch downloads a file from an HTTP URL and saves it to an SD card connected to ESP32.

## Hardware

- ESP32 development board
- SD card module
- FAT32 formatted SD card
- Wi-Fi network

## Modify Before Upload

Update these constants in `ESP32_HTTP_File_Download.ino`:

| Constant | Description |
| --- | --- |
| `WIFI_SSID` | Your Wi-Fi network name. |
| `WIFI_PASSWORD` | Your Wi-Fi password. |
| `DOWNLOAD_URL` | HTTP URL of the file to download. |
| `DOWNLOAD_DIRECTORY` | Folder created on the SD card. |
| `DOWNLOAD_FILE_PATH` | Destination path and file name on the SD card. |
| `SD_CHIP_SELECT_PIN` | SD module chip select pin. |

## Libraries

- Built-in ESP32 `WiFi`
- Built-in ESP32 `HTTPClient`
- Built-in Arduino `SD`
- Built-in Arduino `SPI`

## How To Use

1. Wire the SD module to ESP32 SPI pins.
2. Update Wi-Fi and download URL constants.
3. Insert a FAT32 formatted SD card.
4. Upload the sketch.
5. Open Serial Monitor at `115200` baud.

@copyright : Satish Kanawade. All rights reserved.
