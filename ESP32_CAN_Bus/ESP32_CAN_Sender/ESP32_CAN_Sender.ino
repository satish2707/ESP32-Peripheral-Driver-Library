/**********************************************************************************************************************
 * @file        ESP32_CAN_Sender.ino
 * @brief       Sends text data over CAN bus from ESP32.
 * @details     Configures ESP32 CAN pins, starts the CAN bus at 500 kbps, splits a text message into 8-byte CAN frames,
 *              and transmits the frames with a standard CAN identifier.
 * @author      Satish Kanawade
 * @date        20-May-2026
 * @version     1.0.0
 * @copyright : Satish Kanawade. All rights reserved.
 *********************************************************************************************************************/

#include <CAN.h>
#include <string.h>

const int CAN_TX_GPIO = 21;                   // Connect to CAN transceiver TX/CTX pin.
const int CAN_RX_GPIO = 22;                   // Connect to CAN transceiver RX/CRX pin.
const long CAN_BAUD_RATE = 500000;            // CAN bus speed in bits per second.
const uint32_t CAN_PACKET_ID = 0x12;          // Standard CAN identifier used for demo packets.
const char CAN_MESSAGE[] = "ESP32 CAN TEST";  // Message sent to the receiver, including the string terminator.

// Initializes CAN pins and starts the CAN peripheral.
bool initializeCanBus() {
  CAN.setPins(CAN_RX_GPIO, CAN_TX_GPIO);

  if (!CAN.begin(CAN_BAUD_RATE)) {
    Serial.println("CAN initialization failed.");
    return false;
  }

  Serial.println("CAN initialized successfully.");
  return true;
}

// Sends the configured message over CAN in 8-byte frames.
void sendCanMessage() {
  const size_t messageLength = strlen(CAN_MESSAGE) + 1;

  Serial.print("Sending CAN message: ");
  Serial.println(CAN_MESSAGE);

  for (size_t i = 0; i < messageLength; i += 8) {
    CAN.beginPacket(CAN_PACKET_ID);

    for (size_t j = i; j < i + 8 && j < messageLength; j++) {
      CAN.write(CAN_MESSAGE[j]);
    }

    CAN.endPacket();
    delay(10);
  }

  Serial.println("CAN message sent.");
}

// Initializes serial and CAN bus.
void setup() {
  Serial.begin(115200);
  delay(1000);

  if (!initializeCanBus()) {
    while (true) {
      delay(1000);
    }
  }
}

// Sends the CAN message periodically.
void loop() {
  sendCanMessage();
  delay(5000);
}
