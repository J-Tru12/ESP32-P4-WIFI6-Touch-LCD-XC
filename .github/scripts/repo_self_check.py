#!/usr/bin/env python3
"""Lightweight repository structure checks for CI."""

from __future__ import annotations

import sys
from pathlib import Path


PROJECT_ROOTS = (
    Path("examples/esp-idf"),
    Path("firmware"),
)

REQUIRED_FILES = (
    Path("README.md"),
    Path("docs/GETTING_STARTED.md"),
    Path("docs/PROJECT_STRUCTURE.md"),
    Path("docs/CI.md"),
    Path("docs/TROUBLESHOOTING.md"),
    Path("examples/README.md"),
    Path(".github/scripts/discover_esp_idf_projects.py"),
    Path(".github/scripts/repo_self_check.py"),
    Path(".github/workflows/esp-idf-projects.yml"),
)

REQUIRED_GITIGNORE_PATTERNS = {
    "**/build",
    "**/managed_components",
    "**/dependencies.lock",
    "**/sdkconfig",
}


def is_project(path: Path) -> bool:
    return (path / "CMakeLists.txt").is_file() and (path / "main").is_dir()


def list_projects() -> list[Path]:
    projects: list[Path] = []
    for root in PROJECT_ROOTS:
        if not root.exists():
            continue
        for path in root.iterdir():
            if path.is_dir() and is_project(path):
                projects.append(path)
    return sorted(projects, key=lambda item: item.as_posix())


def check_required_files(errors: list[str]) -> None:
    for path in REQUIRED_FILES:
        if not path.is_file():
            errors.append(f"Missing required file: {path.as_posix()}")


def check_gitignore(errors: list[str]) -> None:
    gitignore = Path(".gitignore")
    if not gitignore.is_file():
        errors.append("Missing .gitignore")
        return

    patterns = {
        line.strip()
        for line in gitignore.read_text(encoding="utf-8").splitlines()
        if line.strip() and not line.strip().startswith("#")
    }
    missing = sorted(REQUIRED_GITIGNORE_PATTERNS - patterns)
    for pattern in missing:
        errors.append(f".gitignore missing generated-output pattern: {pattern}")


def check_projects(errors: list[str]) -> list[Path]:
    projects = list_projects()
    if not projects:
        errors.append("No ESP-IDF projects discovered")
        return projects

    names: dict[str, Path] = {}
    for project in projects:
        name = project.name
        if name in names:
            errors.append(
                "Duplicate ESP-IDF project directory name: "
                f"{name} ({names[name].as_posix()} and {project.as_posix()})"
            )
        names[name] = project

        if not (project / "main" / "CMakeLists.txt").is_file():
            errors.append(f"Missing main/CMakeLists.txt: {project.as_posix()}")

    return projects


def check_example_index(projects: list[Path], errors: list[str]) -> None:
    index = Path("examples/README.md")
    if not index.is_file():
        return

    content = index.read_text(encoding="utf-8")
    for project in projects:
        project_text = project.as_posix()
        if project_text not in content:
            errors.append(f"examples/README.md does not mention {project_text}")


def main() -> int:
    errors: list[str] = []

    check_required_files(errors)
    check_gitignore(errors)
    projects = check_projects(errors)
    check_example_index(projects, errors)

    if errors:
        print("Repository self-check failed:", file=sys.stderr)
        for error in errors:
            print(f"- {error}", file=sys.stderr)
        return 1

    print(f"Repository self-check passed ({len(projects)} ESP-IDF projects).")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
