#include "system.h"
#include "../driver/timers.h"
#include "../cmsis/stm32f4xx.h"



void system_function_init(void) {
    // reserv tim3 for system_delay_ms
    // div = ClockSRC / out -> out = 1000 
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    TIM3->PSC = 50000000 / 1000;
    TIM3->ARR = 0xffff;
    TIM3->CR1 |= TIM_CR1_CEN;
}

// DELAY BASE ON TIM3 COUNTER
void  system_delay_ms(uint32_t ms) {
    uint32_t ticks = ms;
    TIM3->CNT = 0;
    while ((TIM3->CNT) < ticks) { }

}
