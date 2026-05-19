/**********************************************************************************************************************
 * @file        ESP32_RGB_LED.ino
 * @brief       Controls an active-low RGB LED from an ESP32.
 * @details     Demonstrates GPIO setup and simple color selection for RGB LED modules where LOW turns an LED channel on
 *              and HIGH turns the channel off.
 * @author      Satish Kanawade
 * @date        20-May-2026
 * @version     1.0.0
 * @copyright : Satish Kanawade. All rights reserved.
 *********************************************************************************************************************/

const uint8_t RED_PIN = 5;      // Connect to the red channel of the RGB LED.
const uint8_t GREEN_PIN = 18;   // Connect to the green channel of the RGB LED.
const uint8_t BLUE_PIN = 19;    // Connect to the blue channel of the RGB LED.

// Configures all RGB LED GPIO pins and keeps the LED off at startup.
void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  RGB_OFF();
}

// Turns on the selected RGB color using a single character command.
void RGB_ON(char colorCode) {
  RGB_OFF();

  switch (colorCode) {
    case 'R':
      digitalWrite(RED_PIN, LOW);
      break;

    case 'G':
      digitalWrite(GREEN_PIN, LOW);
      break;

    case 'B':
      digitalWrite(BLUE_PIN, LOW);
      break;

    case 'W':
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);
      break;

    case 'Y':
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      break;

    case 'P':
      digitalWrite(RED_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);
      break;

    case 'C':
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);
      break;

    default:
      RGB_OFF();
      break;
  }
}

// Turns off all RGB LED channels.
void RGB_OFF() {
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
}

// Runs the RGB LED color demo sequence continuously.
void loop() {
  const char colorSequence[] = {'R', 'G', 'B', 'W', 'Y', 'P', 'C'};

  for (uint8_t i = 0; i < sizeof(colorSequence); i++) {
    RGB_ON(colorSequence[i]);
    delay(1000);
  }
}
