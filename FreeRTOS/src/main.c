
#include <stdio.h>
#include <string.h>

#include "./cmsis/stm32f4xx.h"
#include "./cmsis/stm32f411xe.h"

#include "./driver/rcc.h"
#include "./driver/usart.h"
#include "./driver/gpio.h"
#include "./system/system.h"
#include "./c_util/tester.h"

#include "FreeRTOSConfig.h"
#include "FreeRTOS/org/Source/include/FreeRTOS.h"
#include "FreeRTOS/org/Source/include/task.h"
#include "FreeRTOS/org/Source/include/semphr.h"
#include "FreeRTOS/org/Source/include/queue.h"

#define MAIN_PRIO 5
#define USART_QUEUE_LENGTH 128






trace_time_t trace = {0};
void system_init();
TaskHandle_t Task1Handle = NULL;
void task_1(void *pvParameters);
TaskHandle_t Task2Handle = NULL;
void task_2(void *pvParameters);
TaskHandle_t Task3Handle = NULL;
void task_3(void *pvParameters);
TaskHandle_t Task4Handle = NULL;
void task_4(void *pvParameters);

TaskHandle_t TaskUsartHandle = NULL;
void task_usart(void *pvParameters);



QueueHandle_t usartQueue;
static uint32_t shared_var = 0;

SemaphoreHandle_t hsemaphore;

int main() {
    system_init();
    // ON DEVIDE 
    trace_tim_reset(TIM5);

    usartQueue = xQueueCreate(USART_QUEUE_LENGTH, sizeof(char));

    xTaskCreate(task_1, "task 1", 1024, NULL, MAIN_PRIO, &Task1Handle);
//    xTaskCreate(task_A, "task A", 1000, NULL, MAIN_PRIO, &TaskAHandle);
//    xTaskCreate(task_usart, "usart task", configMINIMAL_STACK_SIZE, NULL, 15, &TaskUsartHandle);
//    xTaskCreate(task_C, "task C", configMINIMAL_STACK_SIZE, NULL, MAIN_PRIO , &TaskCHandle);
    

    
    printf("** SYSTEM RUNING **\r\n\r\n");
    vTaskStartScheduler();
    while (1) { }
}

void task_usart(void *pvParameters) {
    char ch;
    while(1)
    {
        if(xQueueReceive(usartQueue, &ch, portMAX_DELAY) == pdTRUE)
        {
            // Assuming usart_write is your function to send data over USART
            usart_write(USART2, (uint8_t*)&ch, 1); 
        }
    }
}

char tab[12] = {0};

void task_1(void *pvParameters) {
    memset(tab, 'A', 12);
    tab[0] = '0';
    hsemaphore = xSemaphoreCreateCounting(10, 0);

    tab[1] = '1';
    xTaskCreate(task_2, "task 2", 1024, NULL, MAIN_PRIO + 4, &Task2Handle);

    tab[2] = '2';
    xTaskCreate(task_3, "task 3", 1024, NULL, MAIN_PRIO + 2, &Task3Handle);
    taskYIELD();

    tab[5] = '5';
    xSemaphoreGive(hsemaphore);

    tab[7] = '7';
    xSemaphoreGive(hsemaphore);
    
    tab[9] = '9';
    tab[10] = '\r';
    tab[11] = '\n';
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000)); 
    }
}

void task_2(void *pvParameters) {
    gpio_togle(GPIOD, GPIO_PIN15);
    tab[3] = '3';
    while(1) {
        xSemaphoreTake(hsemaphore, portMAX_DELAY);
        tab[6] = '6';
        gpio_togle(GPIOD, GPIO_PIN15);
        vTaskDelete(Task2Handle);
        vTaskDelay(1);
    }
}

void task_3(void *pvParameters) {
    tab[4] = '4';
    gpio_togle(GPIOD, GPIO_PIN14);
    while(1) {
        xSemaphoreTake(hsemaphore, portMAX_DELAY);
        tab[8] = '8';
        vTaskDelete(Task3Handle);
        vTaskDelay(1); 
    }
}

void task_4(void *pvParameters) {
    printf("[4] start \r\n");

    while(1) {
        printf("[4] step \r\n");
        vTaskDelay(pdMS_TO_TICKS(10000)); 
    }
}

void system_init() {
    SystemInit();
    RCC_Init_100MHz();
    SystemCoreClockUpdate();
     
    usart2_init();
    system_function_init();
    
    RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
    trace_init(TIM5);

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    gpio_init_t device_on_led = {
        .GPIOx = GPIOD,
        .mode = GPIO_MODE_OUTPUT,
        .pins = GPIO_PIN15 | GPIO_PIN14,
        .pupd = GPIO_PUPD_DOWN,
        .type = GPIO_TYPE_PUSH_PULL,
        .speed = GPIO_SPEED_FAST,
    };
    gpio_init(device_on_led);

    // dump wait 
    for (volatile int i = 0; i < 1000000; i++) { }
}

int __io_putchar(int ch) {
    char c = (char)ch;
    xQueueSend(usartQueue, &c, portMAX_DELAY);
    return ch;
}
