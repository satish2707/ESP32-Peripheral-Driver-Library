# ESP32 ST7735 Smooth Font

This sketch displays converted anti-aliased smooth fonts on an ST7735 TFT display using the TFT_eSPI library.

## Files

| File | Purpose |
| --- | --- |
| `ESP32_ST7735_Smooth_Font.ino` | Main display demo sketch. |
| `NotoSansBold15.h` | 15 px converted smooth font data. |
| `NotoSansBold36.h` | 36 px converted smooth font data. |

## Libraries

- `TFT_eSPI`
- Built-in Arduino `SPI`

## How To Use

1. Install `TFT_eSPI`.
2. Configure TFT_eSPI user setup for your ST7735 wiring.
3. Keep the font header files in the same sketch folder.
4. Upload the sketch to ESP32.
5. The display shows sample smooth font text.

## Adding New Fonts

1. Download or install the required font on your computer.
2. Convert the font to a `.vlw` file using Processing.
3. Convert the `.vlw` file to a C byte array.
4. Save the array as a `.h` file in this sketch folder.
5. Include the header and update the font macro in the sketch.

@copyright : Satish Kanawade. All rights reserved.
