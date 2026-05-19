# ESP32 Peripheral Driver Library

Professional ESP32 driver examples and reusable reference projects for common embedded features such as CAN bus, SD card firmware update, CRC32 validation, HTTP client communication, MQTT, NTP date/time, RGB LED control, and TFT smooth fonts.

## Author

**Satish Kanawade**

Embedded Software Developer

## Repository Contents

| Driver / Example | Description | Main Sketch |
| --- | --- | --- |
| ESP32 CAN Bus Sender | Sends segmented CAN frames using ESP32 and an external CAN transceiver. | `ESP32_CAN_Bus/ESP32_CAN_Sender/ESP32_CAN_Sender.ino` |
| ESP32 CAN Bus Receiver | Receives CAN frames and reconstructs the transmitted message. | `ESP32_CAN_Bus/ESP32_CAN_Receiver/ESP32_CAN_Receiver.ino` |
| ESP32 HTTP File Download | Downloads a binary file from an HTTP URL and stores it on an SD card. | `ESP32_HTTP_File_Download/ESP32_HTTP_File_Download.ino` |
| ESP32 HTTP GET Client | Sends a GET request to a configured HTTP server endpoint. | `ESP32_HTTP_GET_Client/ESP32_HTTP_GET_Client.ino` |
| ESP32 HTTP POST Client | Sends a JSON POST request to a configured HTTP server endpoint. | `ESP32_HTTP_POST_Client/ESP32_HTTP_POST_Client.ino` |
| ESP32 MQTT Client | Connects ESP32 to Wi-Fi and an MQTT broker using PubSubClient. | `ESP32_MQTT_Client/ESP32_MQTT_Client.ino` |
| ESP32 NTP Date Time | Reads network date and time from an NTP server. | `ESP32_NTP_DateTime/ESP32_NTP_DateTime.ino` |
| ESP32 RGB LED | Controls an active-low RGB LED using simple color commands. | `ESP32_RGB_LED/ESP32_RGB_LED.ino` |
| ESP32 SD Card CRC32 | Calculates CRC32 for a file stored on SD card. | `ESP32_SD_Card_CRC32/ESP32_SD_Card_CRC32.ino` |
| ESP32 SD OTA Update | Updates ESP32 firmware from `firmware.bin` stored on SD card. | `ESP32_SD_OTA_Update/ESP32_SD_OTA_Update.ino` |
| ESP32 ST7735 Smooth Font | Displays converted smooth fonts on an ST7735 TFT display using TFT_eSPI. | `ESP32_ST7735_Smooth_Font/ESP32_ST7735_Smooth_Font.ino` |

## Quick Start

1. Install the Arduino IDE or PlatformIO.
2. Install ESP32 board support from Espressif.
3. Open the required project folder.
4. Open the `.ino` file inside that folder.
5. Update the configuration constants at the top of the sketch, such as Wi-Fi SSID, password, server address, MQTT broker, SD file path, or GPIO pins.
6. Install the required libraries listed in the project README.
7. Select the correct ESP32 board and COM port.
8. Build and upload the sketch.
9. Open Serial Monitor at `115200` baud to view logs.

## Documentation

Each driver/example folder contains its own `README.md` with:

- Feature overview
- Required hardware
- Required Arduino libraries
- Configuration values to modify
- Build and upload steps
- Expected serial output or behavior

## Coding Standard

- Every source and header file includes a professional file header.
- Every function in the Arduino sketches has a single-line function comment.
- Credentials and server values are kept as placeholders so users can safely modify them before uploading.

## Copyright

@copyright : Satish Kanawade. All rights reserved.
