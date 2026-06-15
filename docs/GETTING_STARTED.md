# Getting Started

This guide describes the shortest path from a fresh checkout to a running
ESP-IDF example on the ESP32-P4-WIFI6-Touch-LCD-XC board.

## Requirements

- ESP-IDF v5.5.x, or a newer version that is compatible with ESP32-P4.
- Python and Git as required by ESP-IDF.
- USB-C cable connected to the board USB-UART port.
- Optional peripherals required by the selected example, such as an SD card or
  camera module.

## Build An ESP-IDF Example

Start with the basic hello world example:

```bash
cd examples/esp-idf/02_HelloWorld
idf.py set-target esp32p4
idf.py build
```

Flash and monitor the board:

```bash
idf.py -p PORT flash monitor
```

Replace `PORT` with your serial port. Use `Ctrl-]` to exit the ESP-IDF serial
monitor.

## Build Other Projects

Every ESP-IDF project in this repository has its own `CMakeLists.txt` and
`main/` directory. Typical project roots are:

- `examples/esp-idf/<example>`
- `firmware/<application>`

Use the same commands from inside the project directory, or use ESP-IDF's
project path option:

```bash
idf.py -C examples/esp-idf/08_lvgl_demo_v9 set-target esp32p4 build
```

## Configure Examples

Run `idf.py menuconfig` before building examples that require:

- Wi-Fi SSID and password.
- SD card filenames or media playback options.
- Display, touch, LVGL, camera, USB, or audio settings.
- Board-specific hardware options.

Commit shared defaults in `sdkconfig.defaults` or `sdkconfig.ci*` files. Do not
commit local `sdkconfig`, `build/`, `managed_components/`, or
`dependencies.lock` outputs.

## Arduino Notes

Arduino information is maintained in
[examples/arduino/README.md](../examples/arduino/README.md), including the
recommended Arduino-ESP32 core, bundled LVGL library, Arduino_GFX dependency,
and I2C driver compatibility note.
