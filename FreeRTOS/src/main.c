/*
  This is the main file for the project.

  @author Marcin Ryzewski
  @date 11/2023
*/


// platform
#include <stdbool.h>
#include <stdint.h>

// c4
#include "cmsis/stm32f4xx.h"
#include "cmsis/system_stm32f4xx.h"

// driver
#include "driver/rcc.h"
#include "system/system.h"
#include "driver/gpio.h"
#include "driver/timers.h"

// RTOS
#include "FreeRTOSConfig.h"
#include "FreeRTOS/org/Source/include/FreeRTOS.h"
#include "FreeRTOS/org/Source/include/task.h"
volatile uint32_t elaps = 0;

void system_init() {
    SystemInit();
    RCC_Init_100MHz();
    SystemCoreClockUpdate();
    system_function_init();
    
    RCC->AHB1ENR  |= RCC_AHB1ENR_GPIODEN; 
    gpio_init_t gpio_out_d = {
        .GPIOx =  GPIOD,
        .mode = GPIO_MODE_OUTPUT,
        .speed = GPIO_SPEED_LOW,
        .type = GPIO_TYPE_PUSH_PULL,
        .pins = GPIO_PIN12 | GPIO_PIN13 | GPIO_PIN14 | GPIO_PIN15,
        .pupd = GPIO_PUPD_DOWN,
    };
    gpio_init(gpio_out_d);
    
    // wait for system init  
    for (volatile int i = 0; i < 100000; i++);
}


TaskHandle_t xTaskHandler1 = NULL;
void vTask1_Handler(void *pvParameters) {
    

    while (1) {
        gpio_togle(GPIOD, GPIO_PIN15);
        vTaskDelay(1000);
    }
}

TaskHandle_t xTaskHandler2 = NULL;
void vTask2_Handler(void *pvParameters) {

    while (1) {
        gpio_togle(GPIOD, GPIO_PIN14);
        vTaskDelay(200);
    }
}

int main(int argc, char const *argv[]) {
    (void)argc;
    (void)argv;

    system_init();
    gpio_write(GPIOD, GPIO_PIN12, 1);
    
    xTaskCreate(vTask1_Handler, "Task-1", configMINIMAL_STACK_SIZE, NULL, 1, &xTaskHandler1);
    xTaskCreate(vTask2_Handler, "Task-2", configMINIMAL_STACK_SIZE, NULL, 1, &xTaskHandler2);
    
    vTaskStartScheduler();
    for (;;);
}
