# Contributing to Embedded Unit Testing Repository

Thank you for considering contributing to the **Embedded Unit Testing** project!  
We welcome all contributions — from fixing bugs and improving documentation to adding new examples or test frameworks.

---

## Table of Contents

1. [Getting Started](#getting-started)  
2. [Code of Conduct](#code-of-conduct)  
3. [Ways to Contribute](#ways-to-contribute)  
4. [Development Setup](#development-setup)  
5. [Coding Standards](#coding-standards)  
6. [Writing Unit Tests](#writing-unit-tests)  
7. [Making a Pull Request](#making-a-pull-request)  
8. [Commit Message Guidelines](#commit-message-guidelines)  
10. [Need Help?](#need-help)

---

## Getting Started

To contribute:

1. **Fork** the repository.  
2. **Clone** your fork:
   ```bash
   git clone https://github.com/JoseLuis-Figueroa/Unit-Testing.git
   ```
3. **Create a new branch** for your work:
   ```bash
   git checkout -b your-feature-branch
   ```

---

## Code of Conduct

We are committed to maintaining a respectful, inclusive, and collaborative community.
Please treat others with professionalism and kindness.

---

## Ways to Contribute

You can contribute in many ways:

-Improve or correct documentation.
-Fix bugs in existing test examples.
-Add new unit tests (e.g., for peripheral drivers).
-Add or enhance PlatformIO configurations.
-Extend support to additional MCU families (e.g., STM32, NXP, or AVR).
-Improve test coverage for reusable driver components.

---

## Development Setup

Make sure you have the following installed:

- Visual Studio Code with PlatformIO extension.  
- GNU ARM Embedded Toolchain.  
- Unity Test Framework (bundled with PlatformIO).
- A supported microcontroller board such as:
   -Nucleo-F401RE (STM32F4 example)
   -Native environment for host-based testing (Circular Buffer example) 

To build the project using the VSCode PlatformIO toolbar:  
Click "Build" or "Run Tests" on the bottom toolbar.

Or use the CLI from the root directory:

```bash
pio run
pio test
```

Build for a specific environment:

```bash
pio test -e native
pio test -e nucleo_f401re
```

---

## Coding Standards

- Follow **MISRA-C** style guidelines wherever possible.  
- Keep code **clean**, **modular**, and **reusable** code.  
- Maintain clear separation between driver logic and test logic.
- Use meaningful names for functions, macros, and variables.
- Add comments and **document your code**.

---

## Writing Unit Tests

- Place your test files under the `test/` directory of each example.
- Follow the [PlatformIO Unit Testing Guide](https://docs.platformio.org/en/latest/advanced/unit-testing/introduction.html) 
- Use the Unity Test framework syntax.
- For STM32-based tests, mock hardware interactions or test logic in isolation when possible.
- Each test should be deterministic and reproducible.

---

## Making a Pull Request

1. Verify your code builds successfully.
2. Ensure all tests pass (pio test on all supported environments).
3. Push your branch:
   ```bash
   git push origin your-feature-branch
   ```
4. Open a Pull Request (PR) on GitHub and describe your contribution.
5. Link the relevant issue if applicable.

---

## Commit Message Guidelines

We follow [Conventional Commits](https://www.conventionalcommits.org/):

- `feat:` New feature  
- `fix:` Bug fix  
- `docs:` Documentation only changes  
- `style:` Formatting, missing semi colons, etc  
- `refactor:` Refactoring code  
- `test:` Adding missing tests  
- `chore:` Maintenance  

**Example:**

```
test(buffer): add write-read circular buffer test case
```

---

## Need Help?

Open an [issue](https://github.com/JoseLuis-Figueroa/Unit-Testing/issues) or ask a question in the repository if you're stuck.  
We're happy to help you get started!

---

Thank you for contributing to **Embedded Unit Testing**!
