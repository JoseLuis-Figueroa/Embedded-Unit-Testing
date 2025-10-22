// ...existing code...
#include "../src/main.h"
#include <unity.h>

/*
 * setUp is executed before EACH test.
 * Here we enable the LED GPIO clock and initialize the LED pin
 * as a push-pull output with pull-up and high speed so tests can
 * read/write the pin state.
 */
void setUp(void)
{
    // Enable peripheral clock for the LED GPIO port
    LED_GPIO_CLK_ENABLE();

    // Configure GPIO settings for the LED pin
    GPIO_InitTypeDef  GPIO_InitStruct;
    GPIO_InitStruct.Pin = LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // Push-pull output
    GPIO_InitStruct.Pull = GPIO_PULLUP;         // Internal pull-up
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;    // High output speed

    // Initialize the GPIO port/pin with the configuration above
    HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);
}

/*
 * tearDown is executed after EACH test.
 * De-initialize the LED pin so each test starts with a clean state.
 */
void tearDown(void)
{
    HAL_GPIO_DeInit(LED_GPIO_PORT, LED_PIN);
}

/*
 * Verify the LED pin macro matches the on-board built-in LED pin.
 * This ensures the project is configured for the expected board pin.
 */
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

/*
 * Test runner main:
 * - Initialize HAL
 * - Start Unity
 * - Run a pin-number test once
 * - Repeatedly run the high/low state tests with delays (simulates toggling)
 * - End Unity and spin forever (typical for embedded test harness)
 */
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

/*
 * SysTick_IRQHandler:
 * - Called by hardware SysTick interrupt
 * - Increment HAL tick counter so HAL_Delay and time-based HAL functions work
 * Keep this handler minimal to avoid delaying interrupts.
 */
void SysTick_Handler(void)
{
    HAL_IncTick();
}
