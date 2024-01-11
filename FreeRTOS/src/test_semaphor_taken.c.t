#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

// Deklaracja semafora
SemaphoreHandle_t xSemaphore = NULL;

void vTask1(void *pvParameters)
{
    while(1)
    {
        // Próba uzyskania semafora
        START_TRACE();
        if(xSemaphoreTake(xSemaphore, portMAX_DELAY) == pdTRUE)
        {
            STOP_TRACE();
            // Sekcja krytyczna
            // ...
            // Zwolnienie semafora
            xSemaphoreGive(xSemaphore);
        }
    }
}

void vTask2(void *pvParameters)
{
    while(1)
    {
        // Próba uzyskania semafora
        START_TRACE();
        if(xSemaphoreTake(xSemaphore, portMAX_DELAY) == pdTRUE)
        {
            STOP_TRACE();
            // Sekcja krytyczna
            // ...
            // Zwolnienie semafora
            xSemaphoreGive(xSemaphore);
        }
    }
}

int main(void)
{
    // Utworzenie semafora
    xSemaphore = xSemaphoreCreateMutex();

    if(xSemaphore != NULL)
    {
        // Utworzenie zadań
        xTaskCreate(vTask1, "Task 1", 1000, NULL, 1, NULL);
        xTaskCreate(vTask2, "Task 2", 1000, NULL, 2, NULL);

        // Uruchomienie planisty
        vTaskStartScheduler();
    }

    for(;;);
    return 0;
}
