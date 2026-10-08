# C Project Template

A reusable C17 project template for small C projects.

The template provides a basic project structure with separate source,
header, and test directories, along with automated formatting, static
analysis, testing, documentation, and Debug/Release build configurations.

## Features

- C17
- GCC
- GNU Make
- Debug and Release builds
- Unit test build and execution
- clang-format formatting checks
- clang-tidy static analysis
- Doxygen documentation generation
- Configurable console and file logging
- Status codes with warning/error severity

## Project Structure

    .vscode/    VS Code build and debug configuration
    include/    Public headers
    src/        Source files
    tests/      Unit tests
    build/      Generated build output
    docs/       Generated Doxygen documentation
    main.c      Application entry point
    Makefile    Build configuration
    Doxyfile    Doxygen configuration
    README.md   Project documentation

## Building

    make clean 
        - Deletes the `build/` and `docs/` folders
    make docs
        - Deletes the `docs/` folder and generates Doxygen documentation (outputs to `docs/`)
    make format
        - Runs clang-format on all source, header, and test files
    make format-check
        - Checks for clang formatting errors
    make tidy
        - Runs clang-tidy on all source and test source files
    make debug
        - Compiles the debug executable (outputs to `build/debug/`)
    make release
        - Compiles the release executable (outputs to `build/release/`)
    make test
        - Compiles and runs the unit test executable (outputs to `build/test/`)
    make test_execution
        - Runs the unit test executable
    make all
        - Runs format-check, tidy, debug, release, test (including test execution), and docs

### Logging Configuration

Debug and test builds enable console and file logging. Log files are written
to their respective build output directories.

Release builds enable console logging only.

Console and file logging can be adjusted in the `Makefile`.

## Requirements
The template requires a C17-compatible GCC toolchain, GNU Make, clang-format, clang-tidy, and Doxygen.

## Tested Environment
- VS Code               - ver 1.140.0
- MSYS2 UCRT64 Shell    - ver 3.6.10-6
- GCC                   - ver 16.2.0
- Make                  - ver 4.4.1
- clang-format          - ver 22.1.8
- clang-tidy            - ver 22.1.8
- Doxygen               - ver 1.18.0

## Using the Template

To start a new project:

1. Replace the template source, header, and test files with the new project's
   implementation.
2. Update `main.c`
3. Update `status_codes.c`, and `status_codes.h` with project-specific status codes.
4. Update the project/target names in the `Makefile` and VS Code configuration.
5. Update the Doxygen project information.
6. Update this README for the new project.
7. Run `make all` to verify formatting, static analysis, builds, tests, and
   documentation.
 