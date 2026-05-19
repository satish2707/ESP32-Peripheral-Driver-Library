# ESP32 NTP Date Time

This sketch reads date and time from an NTP server and prints formatted values on the serial monitor.

## Modify Before Upload

Update these constants in `ESP32_NTP_DateTime.ino`:

| Constant | Description |
| --- | --- |
| `WIFI_SSID` | Your Wi-Fi network name. |
| `WIFI_PASSWORD` | Your Wi-Fi password. |
| `NTP_SERVER` | NTP server hostname. |
| `GMT_OFFSET_SECONDS` | Time zone offset in seconds. India is `19800`. |
| `UPDATE_INTERVAL_MS` | Date/time refresh interval. |

## Library

Install `NTPClient` from the Arduino Library Manager.

## How To Use

1. Update Wi-Fi constants.
2. Confirm the time zone offset for your country.
3. Upload the sketch to ESP32.
4. Open Serial Monitor at `115200` baud.

@copyright : Satish Kanawade. All rights reserved.
