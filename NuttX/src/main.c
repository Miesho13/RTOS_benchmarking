/*
  This is the main file for the project.

  @author Marcin Ryzewski
  @date 11/2023
*/


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



void gpio_startup() {
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
}

void system_init() {
    SystemInit();
    rcc_init();
    system_function_init();
    gpio_startup();
    
    // DUMMY LOOP
    for (volatile int i = 0; i < 100000; i++) { }
}


int main(int argc, char const *argv[]) {
    (void)argc;
    (void)argv;

    system_init();

    // main loop
    while (true) {
        gpio_togle(GPIOD, GPIO_PIN15 | 
                          GPIO_PIN14 |
                          GPIO_PIN13 |
                          GPIO_PIN12 );
        system_delay_ms(1000);
    }

}
