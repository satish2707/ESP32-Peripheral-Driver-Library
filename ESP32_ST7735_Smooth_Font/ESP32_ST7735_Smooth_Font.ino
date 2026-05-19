/**********************************************************************************************************************
 * @file        ESP32_ST7735_Smooth_Font.ino
 * @brief       Displays smooth custom fonts on an ST7735 TFT display using ESP32.
 * @details     Demonstrates TFT_eSPI smooth font loading with converted font header files stored in the sketch folder.
 * @author      Satish Kanawade
 * @date        20-May-2026
 * @version     1.0.0
 * @copyright : Satish Kanawade. All rights reserved.
 *********************************************************************************************************************/

#include <SPI.h>
#include <TFT_eSPI.h>

#include "NotoSansBold15.h"
#include "NotoSansBold36.h"

#define AA_FONT_SMALL NotoSansBold15
#define AA_FONT_LARGE NotoSansBold36

TFT_eSPI tft = TFT_eSPI();

// Initializes serial and prepares the TFT display.
void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
}

// Draws sample text using the converted anti-aliased fonts.
void drawSmoothFontDemo() {
  tft.fillScreen(TFT_BLACK);

  tft.loadFont(AA_FONT_LARGE);
  tft.setTextColor(TFT_CYAN, TFT_BLACK);
  tft.setCursor(8, 8);
  tft.println("ESP32");
  tft.unloadFont();

  tft.loadFont(AA_FONT_SMALL);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setCursor(8, 58);
  tft.println("Smooth Font Demo");
  tft.unloadFont();
}

// Refreshes the smooth font demo screen.
void loop() {
  drawSmoothFontDemo();
  delay(2000);
}
