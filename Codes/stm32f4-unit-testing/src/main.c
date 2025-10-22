#include "main.h"

// Prototype for LED GPIO initialization
void LED_Init(void);

int main(void)
{
    // Initialize the HAL library (configures SysTick, NVIC priority grouping, etc.)
    HAL_Init();
    // Initialize LED GPIO pin(s)
    LED_Init();

    // Main loop: toggle the LED every 1000 ms
    while(1)
    {
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);
        HAL_Delay(1000);
    }
}

// Configure the GPIO used for the on-board LED
void LED_Init(void)
{
    // Enable the GPIO peripheral clock for the LED port
    LED_GPIO_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct;
    // Select the LED pin
    GPIO_InitStruct.Pin = LED_PIN;
    // Set as push-pull output
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    // Enable internal pull-up
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    // Set output speed (can be adjusted to application needs)
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;

    // Initialize the GPIO port with the above settings
    HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);
}

/**
 * SysTick interrupt handler
 *
 * This function is invoked on each SysTick interrupt (configured by HAL_Init).
 * It increments the HAL millisecond tick used by HAL_Delay and other HAL timing
 * utilities. Keep processing here minimal to avoid delaying interrupt handling.
 */
void SysTick_Handler(void)
{
    HAL_IncTick();
}