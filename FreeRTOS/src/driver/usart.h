#ifndef __USART__
#define __USART__

#include <stdint.h>
#include "../cmsis/stm32f4xx.h"


typedef struct {
    USART_TypeDef *instance;
     
} usart_init_t;

void usart_init(usart_init_t *husart);
int32_t usart_read();
int32_t usart_write();

#endif
