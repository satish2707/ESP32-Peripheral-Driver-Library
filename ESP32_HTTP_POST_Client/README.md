# ESP32 HTTP POST Client

This sketch sends a JSON HTTP POST request from ESP32 to a configured server endpoint.

## Modify Before Upload

Update these constants in `ESP32_HTTP_POST_Client.ino`:

| Constant | Description |
| --- | --- |
| `WIFI_SSID` | Your Wi-Fi network name. |
| `WIFI_PASSWORD` | Your Wi-Fi password. |
| `SERVER_HOST` | Server domain name or IP address. |
| `SERVER_PORT` | HTTP port. Default is `80`. |
| `POST_ENDPOINT` | API path that receives the JSON payload. |
| `JSON_PAYLOAD` | JSON body sent by ESP32. |

## How To Use

1. Update Wi-Fi, server, endpoint, and JSON payload constants.
2. Upload the sketch to ESP32.
3. Open Serial Monitor at `115200` baud.
4. Confirm the server response is printed.

@copyright : Satish Kanawade. All rights reserved.
