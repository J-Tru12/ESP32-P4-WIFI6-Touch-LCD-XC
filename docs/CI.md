# Continuous Integration

This repository uses GitHub Actions to run a lightweight repository self-check
and to build ESP-IDF projects when relevant files change.

## Workflow

The workflow is defined in
[.github/workflows/esp-idf-projects.yml](../.github/workflows/esp-idf-projects.yml).

It runs on:

- Pull requests that change ESP-IDF projects, documentation, or CI helpers.
- Pushes to `main` that touch the same paths.
- Manual runs from the GitHub Actions page.

## Self-Check

The self-check runs:

```bash
python .github/scripts/repo_self_check.py
```

It verifies that repository-level documentation exists, generated ESP-IDF
outputs are ignored, CI helper files are present, and every discovered ESP-IDF
project has the minimum expected project structure.

## ESP-IDF Build Discovery

The discovery helper runs:

```bash
python .github/scripts/discover_esp_idf_projects.py
```

It treats directories as buildable ESP-IDF projects when they contain both:

- `CMakeLists.txt`
- `main/`

The current project roots are:

- `examples/esp-idf/`
- `firmware/`

For pull requests and pushes, the workflow builds only changed projects. When
the workflow or discovery script changes, it builds all discovered ESP-IDF
projects. Manual workflow runs accept one input:

| Input | Value |
| --- | --- |
| `project` | `all`, a directory name such as `02_HelloWorld`, or a full path such as `examples/esp-idf/02_HelloWorld` |

The build job currently uses:

- ESP-IDF version: `v5.5.4`
- Target: `esp32p4`
- GitHub Action: `espressif/esp-idf-ci-action@v1`

Arduino sketches are not built by this workflow yet.
