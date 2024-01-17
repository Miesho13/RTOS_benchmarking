/**
 * @file timers.c
 * @brief Timer driver for STM32F4xx
 * @date 2023-11-15
*/

#include "timers.h"



/// @brief Initialize timer
/// @param tid Timer ID 
/// @param prescaler Prescaler value
/// @param period Period value 
void timers_init(timer_init_t *htim) {
    htim->instance->CR1 |= htim->CR1; 
    htim->instance->CR2 |= htim->CR2; 
    htim->instance->ARR = htim->period;
    htim->instance->PSC = htim->prescaler;

    htim->instance->CR1 |= TIM_CR1_CEN;
}


void timers_init_iqr(timer_init_t *htim, IRQn_Type timer_type, uint8_t prio) {
    htim->instance->CR1 |= htim->CR1; 
    htim->instance->CR2 |= htim->CR2; 
    htim->instance->ARR = htim->period;
    htim->instance->PSC = htim->prescaler;
    
    NVIC_EnableIRQ(timer_type);
    htim->instance->DIER |= TIM_DIER_UIE;

    htim->instance->CR1 |= TIM_CR1_CEN; 
}


void timers_start(TIM_TypeDef *htim) {
    htim->CR1 |= TIM_CR1_CEN;
}

void timers_stop(TIM_TypeDef *htim) {
    htim->CR1 &= ~TIM_CR1_CEN;
}

void timers_reset(TIM_TypeDef *htim) {
    htim->CNT = 0;
    htim->CR1 |= TIM_CR1_CEN; 
}

uint32_t timers_elapsed(TIM_TypeDef *htim) {
    return (uint32_t)htim->CNT; 
}

