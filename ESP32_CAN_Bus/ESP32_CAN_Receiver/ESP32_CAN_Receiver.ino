/**********************************************************************************************************************
 * @file        ESP32_CAN_Receiver.ino
 * @brief       Receives text data over CAN bus on ESP32.
 * @details     Configures ESP32 CAN pins, starts the CAN bus at 500 kbps, reads incoming CAN frames, reconstructs a
 *              null-terminated text message, and prints it on the serial monitor.
 * @author      Satish Kanawade
 * @date        20-May-2026
 * @version     1.0.0
 * @copyright : Satish Kanawade. All rights reserved.
 *********************************************************************************************************************/

#include <CAN.h>

const int CAN_TX_GPIO = 21;               // Connect to CAN transceiver TX/CTX pin.
const int CAN_RX_GPIO = 22;               // Connect to CAN transceiver RX/CRX pin.
const long CAN_BAUD_RATE = 500000;        // CAN bus speed in bits per second.
const size_t MAX_MESSAGE_LENGTH = 256;    // Maximum reconstructed CAN message length.

char receivedMessage[MAX_MESSAGE_LENGTH];
size_t messageIndex = 0;

// Initializes CAN pins and starts the CAN peripheral.
bool initializeCanBus() {
  CAN.setPins(CAN_RX_GPIO, CAN_TX_GPIO);

  if (!CAN.begin(CAN_BAUD_RATE)) {
    Serial.println("CAN receiver initialization failed.");
    return false;
  }

  Serial.println("CAN receiver initialized successfully.");
  return true;
}

// Clears the receive buffer for the next CAN message.
void resetReceiveBuffer() {
  messageIndex = 0;
  receivedMessage[0] = '\0';
}

// Reads available CAN packets and prints a completed null-terminated message.
void receiveCanMessage() {
  const int packetSize = CAN.parsePacket();
  if (!packetSize) {
    return;
  }

  Serial.print("Received packet ID: 0x");
  Serial.println(CAN.packetId(), HEX);
  Serial.print("Received packet length: ");
  Serial.println(packetSize);

  while (CAN.available()) {
    const char receivedChar = (char)CAN.read();

    if (messageIndex < MAX_MESSAGE_LENGTH - 1) {
      receivedMessage[messageIndex++] = receivedChar;
      receivedMessage[messageIndex] = '\0';
    }

    if (receivedChar == '\0') {
      Serial.print("Received message: ");
      Serial.println(receivedMessage);
      resetReceiveBuffer();
      break;
    }
  }
}

// Initializes serial and CAN bus.
void setup() {
  Serial.begin(115200);
  delay(1000);

  resetReceiveBuffer();

  if (!initializeCanBus()) {
    while (true) {
      delay(1000);
    }
  }
}

// Polls the CAN bus for incoming packets.
void loop() {
  receiveCanMessage();
}
