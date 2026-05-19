# ESP32 HTTP GET Client

This sketch sends a basic HTTP GET request from ESP32 to a configured server endpoint.

## Modify Before Upload

Update these constants in `ESP32_HTTP_GET_Client.ino`:

| Constant | Description |
| --- | --- |
| `WIFI_SSID` | Your Wi-Fi network name. |
| `WIFI_PASSWORD` | Your Wi-Fi password. |
| `SERVER_HOST` | Server domain name or IP address. |
| `SERVER_PORT` | HTTP port. Default is `80`. |
| `GET_ENDPOINT` | API path requested by ESP32. |

## How To Use

1. Update Wi-Fi and server constants.
2. Upload the sketch to ESP32.
3. Open Serial Monitor at `115200` baud.
4. Confirm the HTTP response is printed.

@copyright : Satish Kanawade. All rights reserved.
