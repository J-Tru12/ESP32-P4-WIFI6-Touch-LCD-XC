# Waveshare ESP32-P4-WIFI6-Touch-LCD-XC

Open-source examples, board bring-up notes, and factory firmware references for
the Waveshare ESP32-P4-WIFI6-Touch-LCD-XC development board.

This repository follows the documentation and CI organization used by
[waveshareteam/ESP32-P4-Platform](https://github.com/waveshareteam/ESP32-P4-Platform),
scoped to this single ESP32-P4 touch LCD board.

## Repository Layout

```text
.
|-- examples/
|   |-- esp-idf/      ESP-IDF examples, one project per directory
|   `-- arduino/      Arduino notes and bundled example libraries
|-- firmware/         Board firmware projects and factory application sources
|-- hardware/         Board schematic and hardware reference files
|-- docs/             Repository-level usage and maintenance notes
`-- .github/          GitHub Actions workflows and CI helper scripts
```

## Documentation

| Document | Purpose |
| --- | --- |
| [Getting Started](docs/GETTING_STARTED.md) | First ESP-IDF build, flash, and monitor workflow |
| [Examples Guide](examples/README.md) | ESP-IDF, Arduino, firmware, and test project index |
| [Project Structure](docs/PROJECT_STRUCTURE.md) | Where new examples, firmware, tests, and docs should live |
| [Continuous Integration](docs/CI.md) | CI discovery, self-check, and ESP-IDF build coverage |
| [Troubleshooting](docs/TROUBLESHOOTING.md) | Build, flash, display, touch, storage, and Wi-Fi checks |

## Quick Start

ESP-IDF v5.5.x is recommended for parity with the CI workflow.

```bash
cd examples/esp-idf/02_HelloWorld
idf.py set-target esp32p4
idf.py build
idf.py -p PORT flash monitor
```

Replace `PORT` with the serial port for the board. Run `idf.py menuconfig`
before building examples that require Wi-Fi credentials, media filenames,
display options, or other board-specific settings.

The Arduino notes are under [examples/arduino](examples/arduino/README.md).

## CI And Self-Checks

The GitHub Actions workflow under
[.github/workflows/esp-idf-projects.yml](.github/workflows/esp-idf-projects.yml)
runs a repository self-check on documentation and project structure. It also
builds changed ESP-IDF projects with ESP-IDF v5.5.4 and target `esp32p4`.

To run the lightweight structure check locally:

```bash
python .github/scripts/repo_self_check.py
```

To list projects selected for a manual CI build:

```bash
python .github/scripts/discover_esp_idf_projects.py --project all
```

## Contributing

Contributions are welcome. Please keep new examples self-contained, document
required hardware and configuration, and avoid committing generated ESP-IDF
directories such as `build/`, `managed_components/`, `dependencies.lock`, and
local `sdkconfig` files.

## Issues And Support

If you encounter any issues:

- Check the [Issues](../../issues) section.
- Create a new issue with board revision, ESP-IDF version, example path, and
  serial log details.
- Refer to the documentation for troubleshooting tips.
- Contact the Waveshare team and provide the order number to obtain technical
  support.

## License

This repository is licensed under the Apache License. See the `LICENSE` file
for details.

## Acknowledgments

- Waveshare for the hardware platforms and software support.
- The Espressif Team for ESP32-P4, ESP-IDF, and related components.
- Open-source contributors who make these projects possible.
