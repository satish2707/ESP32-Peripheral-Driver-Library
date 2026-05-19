# ESP32 CAN Sender

This sketch sends a configured text message from ESP32 over CAN bus.

## Modify Before Upload

Update these constants in `ESP32_CAN_Sender.ino`:

| Constant | Description |
| --- | --- |
| `CAN_TX_GPIO` | ESP32 GPIO connected to CAN transceiver TX/CTX. |
| `CAN_RX_GPIO` | ESP32 GPIO connected to CAN transceiver RX/CRX. |
| `CAN_BAUD_RATE` | CAN bus speed. Default is `500E3`. |
| `CAN_PACKET_ID` | CAN standard packet ID. |
| `CAN_MESSAGE` | Text payload sent to the receiver. |

## How To Use

1. Wire ESP32 to a CAN transceiver.
2. Connect CANH and CANL to the receiver node.
3. Install the Arduino `CAN` library.
4. Open and upload `ESP32_CAN_Sender.ino`.
5. Open Serial Monitor at `115200` baud.

## Expected Output

The serial monitor prints the message before each transmission and confirms that the CAN message was sent.

@copyright : Satish Kanawade. All rights reserved.
