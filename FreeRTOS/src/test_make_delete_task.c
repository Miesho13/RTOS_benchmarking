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

// RTOS
#include "FreeRTOSConfig.h"
#include "FreeRTOS/org/Source/include/FreeRTOS.h"
#include "FreeRTOS/org/Source/include/task.h"
#include "driver/usart.h"

#define TASK_PRIORITY 1

TaskHandle_t xmainTask = NULL;
TaskHandle_t xneverTask = NULL;
TaskHandle_t xinterupTask = NULL;
TaskHandle_t xblockTask = NULL;

trace_time_t trace[100] = {0};

volatile uint32_t trace_counter = 0;


int __io_putchar(int ch)
{
    usart_write(USART2, (uint8_t*)&ch, 1);
    return 1;
}


// Task function for the second and third tests
TaskHandle_t xTaskA = NULL;
void taskA(void *pvParameters) {   

    while (1) {
        vTaskDelete(NULL);
    }
}

TaskHandle_t xTaskB = NULL;
void taskB(void *pvParameters) {
    

    START_TRACE(trace[0], TIM4);
    STOP_TRACE(trace[0], TIM4);
    
    printf("trace overtake = %d\r\n", trace[0].t2 - trace[0].t1);

    vTaskDelete(NULL);
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

    //xTaskCreate(taskA, "a", configMINIMAL_STACK_SIZE, NULL, 5, &xTaskA);
    xTaskCreate(taskB, "b", configMINIMAL_STACK_SIZE, NULL, 5, &xTaskB);

    trace_tim_reset(TIM4);
    vTaskStartScheduler();
    while(1) { }
}

