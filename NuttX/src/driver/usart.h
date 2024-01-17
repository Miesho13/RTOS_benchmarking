#ifndef __USART__
#define __USART__


#include <stdint.h>
#include "../cmsis/stm32f4xx.h"
#include "gpio.h"

typedef enum {
    USART_ID_1,
    USART_ID_2,
    USART_ID_6,

} USART_ID;

typedef enum {
    USART_9600BAUD = 9600,
    USART_115200BAUD = 115200,

} USART_BAUD_RATE;

typedef enum {
    USART_DATA_SIZE_8,
    USART_DATA_SIZE_9,

} USART_DATA_SIZE;

typedef enum {
    USART_PAR_NONE,
    USART_PAR_ODD,
    USART_PAR_EAVEN,

} USART_PARITY;

typedef enum {
    USART_STOP_1b,
    USART_STOP_2b,

} USART_STOP_BITS; 

typedef enum {
    USART_FLOW_NONE,
    
} USART_FLOW_CONTROL;

typedef struct{
    USART_ID id;
    USART_TypeDef instance;    
    uint8_t pin_tx;
    uint8_t pin_rx;
    USART_BAUD_RATE speed;
    USART_DATA_SIZE sizie;
    USART_PARITY parity;
    USART_STOP_BITS stop_bits;
    USART_FLOW_CONTROL flow_control;
    
} usart_config_t;


void usart_init(usart_config_t *husacfg);
int32_t usart_read(USART_TypeDef *husart, void *read_buffer, 
                   uint32_t recv_buff_len, uint32_t dleay);
int32_t usart_write(USART_TypeDef *husart, void *write_buffer, 
                    uint32_t write_buff_len, uint32_t dleay);
int32_t usart_read_iq(USART_TypeDef *husart, void *read_buffer, 
                      uint32_t recv_buff_len);
int32_t usart_write_iq(USART_TypeDef *husart, void *write_buffer, 
                       uint32_t write_buff_len);

 

#endif

