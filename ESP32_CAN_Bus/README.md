# ESP32 CAN Bus

CAN bus examples for ESP32 using an external CAN transceiver module such as TJA1051, SN65HVD230, or a compatible module.

## Projects

| Project | Purpose |
| --- | --- |
| `ESP32_CAN_Sender` | Sends a text message as 8-byte CAN frames. |
| `ESP32_CAN_Receiver` | Receives CAN frames and reconstructs the text message. |

## Hardware

- ESP32 development board
- CAN transceiver module
- CANH/CANL wiring between sender and receiver nodes
- Common ground between ESP32 boards and CAN modules

## Default Pins

| Signal | ESP32 GPIO |
| --- | --- |
| CAN TX | GPIO 21 |
| CAN RX | GPIO 22 |

Update `CAN_TX_GPIO`, `CAN_RX_GPIO`, and `CAN_BAUD_RATE` in the sketches when your hardware uses different wiring or speed.

## Library

Install the `CAN` library from the Arduino Library Manager.

## Usage

1. Open `ESP32_CAN_Sender/ESP32_CAN_Sender.ino` on the transmitter ESP32.
2. Open `ESP32_CAN_Receiver/ESP32_CAN_Receiver.ino` on the receiver ESP32.
3. Confirm CAN pins and baud rate match on both boards.
4. Upload both sketches.
5. Open Serial Monitor at `115200` baud on both boards.

@copyright : Satish Kanawade. All rights reserved.
