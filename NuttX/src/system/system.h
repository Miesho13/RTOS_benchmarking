#ifndef __SYTSTEM__H__
#define __SYTSTEM__H__



#include <stdint.h>
#include "../driver/timers.h"
#include "../cmsis/stm32f4xx.h"
#include <assert.h>



void system_function_init(void);
void system_delay_ms(uint32_t ms);

#endif // __SYTSTEM__H__
