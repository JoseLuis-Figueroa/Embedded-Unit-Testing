# Embedded Unit Testing.

This repository demonstrates **embedded unit testing techniques** using VS Code with different platforms like [PlatformIO](https://platformio.org/) and a custom building process (Makefile).  
It includes two example projects showcasing how to implement and execute tests in both **hosted (PC)** and **embedded (STM32)** environments.

Developed in **C and C++**, these examples are based on **industry best practices for firmware verification**, focusing on reusable test patterns, modular design, and structured validation.

---

## Table of Contents

1. [About the Project](#about-the-project)  
2. [Project Status](#project-status)  
3. [Getting Started](#getting-started)  
   1. [Dependencies](#dependencies)  
   2. [Getting the Source](#getting-the-source)  
   3. [Building](#building)  
   4. [Running Tests](#running-tests)  
4. [Usage](#usage)  
5. [Release Process](#release-process)  
6. [How to Get Help](#how-to-get-help)  
7. [Contributing](#contributing)  
8. [Further Reading](#further-reading)  
9. [License](#license)  
10. [Authors](#authors)  
11. [Acknowledgments](#acknowledgments)

---

## About the Project

This repository contains two examples that demonstrate **different approaches to embedded unit testing**:

1. **Circular Buffer Test (Host Environment)** – A desktop simulation of a buffer data structure validated through unit tests.  
2. **STM32 Unit Testing Example (Target Environment)** – A hardware-in-the-loop test running on a real STM32 target board (Nucleo-F401RE).

Each project follows the **PlatformIO testing framework** and integrates seamlessly with the **Unity test engine** for structured testing and result reporting.

### Key Features

- Portable, hardware-independent unit test setup.  
- Integration with the [Unity](https://github.com/ThrowTheSwitch/Unity) testing framework.  
- Host and embedded testing examples using PlatformIO and Makefile.  
- Follows **MISRA-C** and clean coding standards.  

### Technical Details

- **Environment:** PlatformIO (VS Code) / Makefile
- **Languages:** C / C++  
- **Framework:** Unity Test Framework 
- **Target Boards:**  
  - Circular Buffer – Host (native)  
  - STM32 Unit Test – Nucleo-F401RE (ARM Cortex-M4)  
- **Toolchain:** GNU ARM Embedded / GCC  
- **Debugging:** PlatformIO Test Console, Serial Monitor  

---

## Project Status

![Build Status](https://img.shields.io/badge/build-passing-brightgreen)

Current Version: `v1.0`  
Tested On:  
- 🖥️ Native (Windows/Linux)  
- ⚙️ STM32 Nucleo-F401RE  

---

## Getting Started

### Dependencies

Install the following tools:

- [Visual Studio Code](https://code.visualstudio.com/)  
- [PlatformIO IDE extension](https://platformio.org/install)  
- [GNU ARM Embedded Toolchain](https://developer.arm.com/downloads/-/gnu-rm)  
- [Unity Test Framework](https://github.com/ThrowTheSwitch/Unity) (bundled with PlatformIO)

---

### Getting the Source

Clone the GitHub repository:

```bash
git clone https://github.com/JoseLuis-Figueroa/Unit-Testing.git
cd Unit-Testing
```

### Building

You can build the project using either the **PlatformIO extension in Visual Studio Code** or the **PlatformIO CLI**.

- **Build using the PlatformIO Toolbar (GUI):** If you're using VS Code with the PlatformIO extension, simply click the "_Build_" button in the PlatformIO toolbar. This will compile your project using the selected environment in your `platformio.ini`.

- **Build using the PlatformIO CLI:** From the project's root directory, run the following command to build all environments defined in `platformio.ini`:

```
pio run
```

- **Build specific environments in CLI:** run the following command to build a specific environment:

```
pio run -e circular-buffer
pio run -e stm32f4-unit-testing
```

### Running Tests

You can test on the host or actual hardware by uploading the code using the **PlatformIO extension in Visual Studio Code** or the **PlatformIO CLI**:

- **Run the test using the PlatformIO Toolbar (GUI):** If you're using VS Code with the PlatformIO extension, simply click the "_PlatformIO Test_" button in the PlatformIO toolbar. This will test your project using the selected environment in your `platformio.ini`.

- **Build using the PlatformIO CLI:** From the project's root directory, run the following command to upload all environments defined in `platformio.ini`:

```
pio test
```
- **Test specific environments in CLI:** run the following command to build a specific environment:
```
pio test -e circular-buffer
pio test -e stm32f4-unit-testing
```
---
## Usage

This repository contains **two PlatformIO-based unit testing examples** that demonstrate how to apply Unit Testing in both **native (PC)** and **embedded STM32** environments.

### 1. Circular Buffer Unit Testing (Native Environment)

This example showcases **firmware-independent unit testing** using the **Unity test framework** on a host machine (no hardware required).

It demonstrates how to verify data integrity, order preservation, and buffer overflow handling in a **circular buffer implementation**.

#### Purpose

The goal is to validate the core logic of a reusable data structure ensuring correctness before integrating it into embedded firmware.

#### Functions Under Test

| Function | Description |
|-----------|-------------|
| `cbuffer_init()`  | Initializes the circular buffer. |
| `cbuffer_add()`   | Adds an element to the buffer. |
| `cbuffer_clear()` | Clear all the buffer. |
| `cbuffer_full()`  | Checks if the buffer is full. |
| `cbuffer_empty()` | Checks if the buffer is empty. |

#### Example Test Case

```c
/* Test case 1*/
void test_circular_buffer_empty_after_init(void) 
{
    TEST_ASSERT_TRUE(cbuffer_empty(&buff));
}

/* Test case 2*/
void test_circular_buffer_not_empty_after_new_element_added(void) 
{
    cbuffer_add(&buff, 42);
    TEST_ASSERT_FALSE(cbuffer_empty(&buff));
}

/*Test case 3*/
void test_circular_buffer_read_element_successful(void)
{
    uint8_t value = 55;
    cbuffer_add(&buff, value);

    TEST_ASSERT_EQUAL(value, cbuffer_get(&buff));
}

/*Test case 4*/
void test_circular_buffer_cleaned_succesfully()
{
    for(uint8_t i=0; i<BUFFER_SIZE/2; i++)
    {
        cbuffer_add(&buff, i);
    }
    cbuffer_clear(&buff);
    TEST_ASSERT_TRUE(cbuffer_empty(&buff));
}
```
Tests are executed using the **PlatformIO “native”** environment, which runs on your host PC. No MCU hardware or peripheral setup is required. Results appear directly in the **VS Code terminal** or PlatformIO **test output console**.

#### Results Output
```c
Verbosity level can be increased via `-v, -vv, or -vvv` option
Collected 1 tests

Processing * in native environment
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Building...
Testing...
test\test_circular_buffer.c:66: test_circular_buffer_empty_after_init   [PASSED]
test\test_circular_buffer.c:67: test_circular_buffer_not_empty_after_new_element_added  [PASSED]
test\test_circular_buffer.c:68: test_circular_buffer_read_element_successful    [PASSED]
test\test_circular_buffer.c:69: test_circular_buffer_cleaned_succesfully        [PASSED]
---------------------------------------------------------------------------------- native:* [PASSED] Took 1.86 seconds ---------------------------------------------------------------------------------- 

================================================================================================ SUMMARY ================================================================================================ 
Environment    Test    Status    Duration
-------------  ------  --------  ------------
native         *       PASSED    00:00:01.860
=============================================================================== 4 test cases: 4 succeeded in 00:00:01.860 =============================================================================== 
```

### 2. STM32 Unit Testing (PlatformIO)

It demonstrates how to execute **hardware-level unit tests** directly on an STM32 target, combining **STM32Cube HAL** with the **Unity test** framework.

#### Purpose

Validate low-level embedded functionality (GPIO control, timing, hardware interaction) directly on the device, enabling **on-target verification** instead of pure simulation.

#### Example Features

| Function | Description |
|-----------|-------------|
| `HAL_GPIO_TogglePin()`  | Toggles an LED connected to GPIO pin. |
| `HAL_GPIO_ReadPin()`    | Reads pin state after toggling. |
| `HAL_Delay()`           | Adds timing between operations for visibility. |

#### Example Test Cases

```c
void led_builtin_pin_number()
{
    TEST_ASSERT_EQUAL(GPIO_PIN_5, LED_PIN);
}

/*
 * Test that writing a HIGH/SET to the LED pin results in a HAL read of SET.
 */
void test_led_state_high()
{
    HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN, GPIO_PIN_SET);
    TEST_ASSERT_EQUAL(GPIO_PIN_SET, HAL_GPIO_ReadPin(LED_GPIO_PORT, LED_PIN));
}

/*
 * Test that writing a LOW/RESET to the LED pin results in a HAL read of RESET.
 */
void test_led_state_low()
{
    HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN, GPIO_PIN_RESET);
    TEST_ASSERT_EQUAL(GPIO_PIN_RESET, HAL_GPIO_ReadPin(LED_GPIO_PORT, LED_PIN));
}
```

#### Test Main

```c
int main(void)
{
    // Initialize the HAL library (sets up SysTick, etc.)
    HAL_Init();
    // Short delay to allow HAL drivers/hardware to stabilise before tests
    HAL_Delay(2000);

    // Start Unity test framework
    UNITY_BEGIN();
    // Run simple static test to confirm LED pin macro
    RUN_TEST(led_builtin_pin_number);

    // Run toggle tests multiple times with delays to exercise GPIO read/write
    for (uint8_t i = 0; i < 5; i++)
    {
        RUN_TEST(test_led_state_high);
        HAL_Delay(500); // pause between tests
        RUN_TEST(test_led_state_low);
        HAL_Delay(500);
    }

    // Finish Unity test run (prints results via configured Unity output)
    UNITY_END();

    // Typical embedded pattern: prevent exit by looping forever
    while (1)
    {
    }
}
```

The test is compiled for the STM32 target (Nucleo-F401RE). When uploaded, it executes on the MCU using the ST-Link debugger. Results are visible in both the debug console and PlatformIO test output.

#### Results Output

```c
Testing...
If you don't see any output for the first 10 secs, please reset board (press reset button)

test\test_main.c:81: led_builtin_pin_number     [PASSED]
test\test_main.c:86: test_led_state_high        [PASSED]
test\test_main.c:88: test_led_state_low [PASSED]
test\test_main.c:86: test_led_state_high        [PASSED]
test\test_main.c:88: test_led_state_low [PASSED]
test\test_main.c:86: test_led_state_high        [PASSED]
test\test_main.c:88: test_led_state_low [PASSED]
test\test_main.c:86: test_led_state_high        [PASSED]
test\test_main.c:88: test_led_state_low [PASSED]
test\test_main.c:86: test_led_state_high        [PASSED]
test\test_main.c:88: test_led_state_low [PASSED]
--------------------------------------------------------- nucleo_f401re:* [PASSED] Took 10.48 seconds ---------------------------------------------------------

=========================================================================== SUMMARY ===========================================================================
Environment    Test    Status    Duration
-------------  ------  --------  ------------
nucleo_f401re  *       PASSED    00:00:10.484
========================================================= 11 test cases: 11 succeeded in 00:00:10.484 =========================================================
```
### Summary

| Example   | Target | Test Framework | Environment | Purpose |
|-----------|-------------|-------------|-------------|-------------|
| Circular Buffer    | Host (PC) | Unity       | Native   | Algorithmic/Logic Testing   |
| STM32 Unit Testing | STM32 MCU | Unity + HAL | Embedded | Hardware Integration Testing|

Both examples demonstrate a **scalable approach** to testing embedded software, where logic is verified in isolation before hardware validation, ensuring **reliability** and **maintainability**.

---
## Release Process

### Versioning

We use [Semantic Versioning](http://semver.org/).  
Latest release: **v1.0**

### Payload

-**v1.0**: Initial release including both Circular Buffer and STM32 examples.


**[Back to top](#table-of-contents)**

---

## How to Get Help

- [Open an issue](https://github.com/JoseLuis-Figueroa/Unit-Testing/issues)
- Message me via my GitHub profile.

---

## Contributing

Contributions are welcome!  
Please refer to [CONTRIBUTING.md](Documentation/CONTRIBUTING.md) for details.

**[Back to top](#table-of-contents)**

---

## Further Reading

- [MISRA-C Guidelines](https://www.misra.org.uk/)
- [Unit Testing: PlatformIO](https://docs.platformio.org/en/latest/advanced/unit-testing/introduction.html)

---

## License

Licensed under the MIT License – see [LICENSE.md](LICENSE) for details.

---

## Authors

**[JoseLuis-Figueroa](https://github.com/JoseLuis-Figueroa)** – Developer & Maintainer

---

## Acknowledgments

- [STM32F4 Reference Manual](https://www.st.com/resource/en/reference_manual/dm00031020.pdf)
