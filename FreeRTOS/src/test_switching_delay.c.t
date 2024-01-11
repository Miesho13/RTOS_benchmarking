
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
#include "c_util/tester.h"

// RTOS
#include "FreeRTOSConfig.h"
#include "FreeRTOS/org/Source/include/FreeRTOS.h"
#include "FreeRTOS/org/Source/include/task.h"


#define TASK_PRIORITY 1

TaskHandle_t xTaskAHandle = NULL;
TaskHandle_t xTaskBHandle = NULL;

trace_time_t trace[100] = {0};
volatile uint32_t trace_counter = 0;

void end_test(void)
{
    while(1) { }
}

void vTaskA(void *pvParameters)
{
    for(;;)
    {
        START_TRACE(trace[trace_counter], TIM4);

        taskYIELD();
    }
}

// Definiujemy funkcję, która implementuje zadanie Z2
void vTaskB(void *pvParameters)
{
    for(;;)
    {
        STOP_TRACE(trace[trace_counter], TIM4);
        trace_counter++;
        if (trace_counter == 99) {
            vTaskDelete(NULL);
        }
        taskYIELD();
    }
}


void system_init() {
    SystemInit(); 
    RCC_Init_100MHz();
    SystemCoreClockUpdate();

    RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
    trace_init(TIM4);
    
    for (volatile int i = 0; i < 100000 ; i++) { }
}

int main(void) {
    system_init();

    xTaskCreate(vTaskA, "TaskA", configMINIMAL_STACK_SIZE, NULL, TASK_PRIORITY, &xTaskAHandle);
    xTaskCreate(vTaskB, "TaskB", configMINIMAL_STACK_SIZE, NULL, TASK_PRIORITY, &xTaskBHandle);

    trace_tim_reset(TIM4);

    vTaskStartScheduler();
    while(1) { }
}

