#ifndef __TIMERS_H__
#define __TIMERS_H__

#include <stdint.h>
#include <stdlib.h>

#include "../cmsis/stm32f4xx.h"
#include "../cmsis/system_stm32f4xx.h"

// ----- TIMER FAST MAKRO -----
#define TIMER_ELAPSED(TIMx) TIMx->CNT



typedef struct {
  TIM_TypeDef *instance;
  uint32_t CR1;
  uint32_t CR2;
  uint32_t period;
  uint16_t prescaler;

} timer_init_t;

/* Initializes the specified timer. Configuration is passed as a 'timer_init_t'. */
void timers_init(timer_init_t *htim);

/* Initializes the timer and its interrupt. Configuration is passed as a 
   'timer_init_t'. 'timer_type' specifies the interrupt type, 'prio' sets 
   the interrupt priority. */
void timers_init_iqr(timer_init_t *htim, IRQn_Type timer_type, uint8_t prio);

/* Starts the specified timer. */
void timers_start(TIM_TypeDef *htim);

/* Stops the specified timer. */
void timers_stop(TIM_TypeDef *htim);

/* Resets the specified timer. */
void timers_reset(TIM_TypeDef *htim);

/* Returns the elapsed time (in ticks) since the specified timer was started. */
uint32_t timers_elapsed(TIM_TypeDef *htim);


/*   These are weakly linked interrupt handler declarations for various Timer 
 *   (TIM) interrupts in STM32. The '__attribute__((weak))' tells the linker 
 *   that the following function definitions are weak, meaning they can be 
 *   overridden by other functions with the same name. If no other definition 
 *   is provided in other files, these weak definitions will be used. This is 
 *   useful when you want to provide default interrupt handlers which can be 
 *   optionally overridden.
 */
void __attribute__((weak)) TIM1_BRK_TIM9_IRQHandler(void);
void __attribute__((weak)) TIM1_UP_TIM10_IRQHandler(void);
void __attribute__((weak)) TIM1_TRG_COM_TIM11_IRQHandler(void);
void __attribute__((weak)) TIM1_CC_IRQHandler(void);
void __attribute__((weak)) TIM2_IRQHandler(void);
void __attribute__((weak)) TIM3_IRQHandler(void);
void __attribute__((weak)) TIM4_IRQHandler(void);

#endif
