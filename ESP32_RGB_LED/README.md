# ESP32 RGB LED

This sketch controls an active-low RGB LED using ESP32 GPIO pins.

## Default Pins

| LED Channel | ESP32 GPIO |
| --- | --- |
| Red | GPIO 5 |
| Green | GPIO 18 |
| Blue | GPIO 19 |

Update `RED_PIN`, `GREEN_PIN`, and `BLUE_PIN` in `ESP32_RGB_LED.ino` if your wiring is different.

## Color Commands

| Command | Color |
| --- | --- |
| `R` | Red |
| `G` | Green |
| `B` | Blue |
| `W` | White |
| `Y` | Yellow |
| `P` | Pink |
| `C` | Cyan |

## How To Use

1. Wire the RGB LED module to ESP32.
2. Update GPIO constants if needed.
3. Upload the sketch.
4. The LED cycles through the configured color sequence.

@copyright : Satish Kanawade. All rights reserved.
