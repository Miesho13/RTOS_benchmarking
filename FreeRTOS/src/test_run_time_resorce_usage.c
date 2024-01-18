
// platform
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

// c4
#include "cmsis/stm32f4xx.h"
#include "cmsis/system_stm32f4xx.h"

// driver
#include "driver/rcc.h"
#include "system/system.h"
#include "driver/gpio.h"
#include "driver/timers.h"
#include "c_util/tester.h"
#include "driver/usart.h"


// Define the macros for run time stats

// RTOS
#include "FreeRTOSConfig.h"
#include "FreeRTOS/org/Source/include/FreeRTOS.h"
#include "FreeRTOS/org/Source/include/task.h"





#define TASK_PRIORITY 1


trace_time_t trace[100] = {0};
volatile uint32_t trace_counter = 0;

static char runTimeStatsBuffer[1024];



int __io_putchar(int ch)
{
    usart_write(USART2, (uint8_t*)&ch, 1);
    return 1;
}

TaskHandle_t xTaskAHandle = NULL;
void vTaskA(void *pvParameters) {
    (void)pvParameters;
    TickType_t xLastWeakTime;
    const TickType_t xFrequency = 1000;
    xLastWeakTime = xTaskGetTickCount();

    for (;;) {
        xTaskDelayUntil(&xLastWeakTime, xFrequency);


        vTaskGetRunTimeStats(runTimeStatsBuffer);


        printf("%s\n", runTimeStatsBuffer);

        vTaskDelay(1000);
    }


}

TaskHandle_t xTaskBHandle = NULL;
void vTaskB(void *pvParameters) {
    (void)pvParameters;
    static uint32_t i = 0;

    for (;;) {
        i++; 
        vTaskDelay(1);
    }
}

void system_init() {
    SystemInit(); 
    RCC_Init_100MHz();
    SystemCoreClockUpdate();

    usart2_init();

    RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
    trace_init(TIM4);
                
    for (volatile int i = 0; i < 100000 ; i++) { }
}

int main(void) {
    system_init();
    
    uint32_t h1 = xPortGetFreeHeapSize();
    xTaskCreate(vTaskA, "TaskA", configMINIMAL_STACK_SIZE, NULL, TASK_PRIORITY, &xTaskAHandle);
    xTaskCreate(vTaskB, "TaskB", configMINIMAL_STACK_SIZE, NULL, TASK_PRIORITY, &xTaskBHandle);
    //xTaskCreate(vTaskC, "TaskC", configMINIMAL_STACK_SIZE, NULL, TASK_PRIORITY, &xTaskCHandle);
    uint32_t h2 = xPortGetFreeHeapSize();
    
    printf("HEAP = %d\r\n", h2 - h1);

    vTaskStartScheduler();
    while(1) { }
}

