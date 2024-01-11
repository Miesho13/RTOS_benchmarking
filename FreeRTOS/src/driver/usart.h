#ifndef __USART__
#define __USART__

#include <stdint.h>
#include "../cmsis/stm32f4xx.h"


typedef struct {
    USART_TypeDef *instance;
     
} usart_init_t;

void usart2_init(void);
int32_t usart_read();
int32_t usart_write(USART_TypeDef* husart, uint8_t* buffer, uint32_t len);

#endif
