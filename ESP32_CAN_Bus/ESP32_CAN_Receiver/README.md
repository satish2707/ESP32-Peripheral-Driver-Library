# ESP32 CAN Receiver

This sketch receives CAN frames on ESP32 and rebuilds a null-terminated text message sent by the CAN sender example.

## Modify Before Upload

Update these constants in `ESP32_CAN_Receiver.ino`:

| Constant | Description |
| --- | --- |
| `CAN_TX_GPIO` | ESP32 GPIO connected to CAN transceiver TX/CTX. |
| `CAN_RX_GPIO` | ESP32 GPIO connected to CAN transceiver RX/CRX. |
| `CAN_BAUD_RATE` | CAN bus speed. Must match the sender. |
| `MAX_MESSAGE_LENGTH` | Receive buffer size for reconstructed messages. |

## How To Use

1. Wire ESP32 to a CAN transceiver.
2. Connect CANH and CANL to the sender node.
3. Install the Arduino `CAN` library.
4. Open and upload `ESP32_CAN_Receiver.ino`.
5. Open Serial Monitor at `115200` baud.

## Expected Output

The serial monitor prints packet ID, packet length, and the reconstructed message.

@copyright : Satish Kanawade. All rights reserved.
