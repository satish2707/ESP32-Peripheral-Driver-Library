# ESP32 SD Card CRC32

This sketch calculates the CRC32 checksum of a file stored on an SD card.

## Modify Before Upload

Update these constants in `ESP32_SD_Card_CRC32.ino`:

| Constant | Description |
| --- | --- |
| `SD_CHIP_SELECT_PIN` | SD module chip select pin. |
| `CRC_FILE_PATH` | Path of the file used for CRC32 calculation. |

## Library

Install a compatible `CRC32` library from the Arduino Library Manager.

## How To Use

1. Copy the target file to the SD card.
2. Update `CRC_FILE_PATH` if the file name is different.
3. Insert the SD card into the module.
4. Upload the sketch to ESP32.
5. Open Serial Monitor at `115200` baud to read the CRC32 value.

@copyright : Satish Kanawade. All rights reserved.
