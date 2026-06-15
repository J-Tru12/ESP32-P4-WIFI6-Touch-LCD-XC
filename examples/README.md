# Examples Guide

This directory contains ESP-IDF projects, Arduino notes and bundled libraries,
firmware applications, and hardware validation tests for the
ESP32-P4-WIFI6-Touch-LCD-XC board.

## ESP-IDF Examples

| Path | Area |
| --- | --- |
| `examples/esp-idf/01_HowToCreateProject` | Minimal ESP-IDF project layout |
| `examples/esp-idf/02_HelloWorld` | Basic ESP-IDF application |
| `examples/esp-idf/03_i2c_tools` | I2C scan and command tools |
| `examples/esp-idf/04_wifistation` | Wi-Fi station connection |
| `examples/esp-idf/05_sdmmc` | SD card and SDMMC |
| `examples/esp-idf/06_I2SCodec` | I2S audio codec |
| `examples/esp-idf/07_Displaycolorbar` | LCD display color bar |
| `examples/esp-idf/08_lvgl_demo_v9` | LVGL v9 display demo |
| `examples/esp-idf/09_video_lcd_display` | Video display pipeline |
| `examples/esp-idf/10_mp4_player` | MP4/AVI playback |
| `examples/esp-idf/11_esp_brookesia_phone` | ESP-Brookesia phone UI |
| `examples/esp-idf/12_usb_extend_screen` | USB extended screen |

## Firmware

| Path | Area |
| --- | --- |
| `firmware/brookesia` | Board Brookesia firmware application |

## Arduino

Arduino notes are maintained in [arduino/README.md](arduino/README.md). The
Arduino tree includes bundled libraries used by the board examples, including
LVGL and Arduino_GFX.

## Adding A Project

New ESP-IDF projects should be self-contained and build independently with:

```bash
idf.py set-target esp32p4
idf.py build
```

Also update this index, add project-specific setup notes where appropriate, and
ensure generated ESP-IDF outputs are not committed.
