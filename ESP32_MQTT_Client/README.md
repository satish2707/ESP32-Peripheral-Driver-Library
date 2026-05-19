# ESP32 MQTT Client

This sketch connects ESP32 to Wi-Fi, connects to an MQTT broker, subscribes to a topic, and prints incoming payloads.

## Modify Before Upload

Update these constants in `ESP32_MQTT_Client.ino`:

| Constant | Description |
| --- | --- |
| `WIFI_SSID` | Your Wi-Fi network name. |
| `WIFI_PASSWORD` | Your Wi-Fi password. |
| `MQTT_SERVER` | MQTT broker domain name or IP address. |
| `MQTT_PORT` | MQTT broker port. Default is `1883`. |
| `MQTT_USERNAME` | MQTT username. |
| `MQTT_PASSWORD` | MQTT password. |
| `MQTT_CLIENT_ID` | Unique client ID for this ESP32. |
| `MQTT_TOPIC` | Topic subscribed by ESP32. |

## Library

Install `PubSubClient` from the Arduino Library Manager.

## How To Use

1. Update Wi-Fi and MQTT broker constants.
2. Upload the sketch to ESP32.
3. Open Serial Monitor at `115200` baud.
4. Publish a message to the configured topic from your MQTT broker or test client.

@copyright : Satish Kanawade. All rights reserved.
