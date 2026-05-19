# ESP32 SD OTA Update

This sketch updates ESP32 firmware from a `firmware.bin` file stored on an SD card.

## Modify Before Upload

Update these constants in `ESP32_SD_OTA_Update.ino`:

| Constant | Description |
| --- | --- |
| `LED_PIN` | Status LED GPIO. |
| `SD_CHIP_SELECT_PIN` | SD module chip select pin. |
| `FIRMWARE_FILE_PATH` | Firmware binary path on SD card. |

## How To Use

1. Build your new firmware binary as `firmware.bin`.
2. Copy `firmware.bin` to the SD card root directory.
3. Insert the SD card into the ESP32 SD module.
4. Upload this OTA update sketch to ESP32.
5. Restart ESP32 and watch Serial Monitor at `115200` baud.

## Important Notes

- The firmware file is removed after a successful update.
- Keep stable power connected during the update process.
- Ensure the new binary is built for the same ESP32 target.

@copyright : Satish Kanawade. All rights reserved.
