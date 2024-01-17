
#include <stdint.h>
#include <stdlib.h>

#include "gpio.h"
#include "usart.h"
#include "../cmsis/stm32f4xx.h"




void usart_init(usart_config_t *hcfg) {
    // ENABLE GPIO  
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // FOR ENABLE RCC_USART   
    switch(hcfg->id) {
        case USART_ID_1:
            RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
            break;

        case USART_ID_2:
            RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
            break;

        case USART_ID_6:
            RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
            break;

        default:
            /* some error call if impl */
            break;
    }

    gpio_init_t usart_pin_cfg = {
        .GPIOx = GPIOA,
        .mode =  GPIO_MODE_ALT,
        .pins =  (1 << hcfg->pin_rx) | (1 << hcfg->pin_tx),
        .pupd =  GPIO_PUPD_NO, 
        .type =  GPIO_TYPE_PUSH_PULL,
        .speed = GPIO_SPEED_FAST,
    }; gpio_init(usart_pin_cfg);
    
    uint64_t tmp = 0; 
    tmp |= ( << (hcfg->pin_rx * 4)) | ( << (hcfg->tx * 4));
    GPIOA->AFR[0]; 

}

void usart2_init(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;  // Enable GPIOA clock
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN; // Enable USART2 clock

    // Configure PA2 (USART2 TX) and PA3 (USART2 RX) in alternate function mode
    GPIOA->MODER &= ~(GPIO_MODER_MODER2 | GPIO_MODER_MODER3); // Clear mode bits
    GPIOA->MODER |= (GPIO_MODER_MODER2_1 | GPIO_MODER_MODER3_1); // Set to alternate function mode

    // Set alternate functions for PA2 and PA3 to be USART2 TX and RX
    GPIOA->AFR[0] |= (7 << (4 * (2 % 8))) | (7 << (4 * (3 % 8))); // USART2 is AF7

    // Configure USART2
    USART2->BRR = SystemCoreClock / 9600; // Set baud rate to 9600 [BRR = f_Clock / BaudRate]
    USART2->CR1 |= USART_CR1_TE | USART_CR1_RE; // Enable transmitter and receiver
    USART2->CR1 |= USART_CR1_UE; // Enable USART
}


int32_t usart_write(USART_TypeDef* husart, uint8_t* buffer, uint32_t len) {
    for(size_t i = 0; i < len; i++)
    {
        // Wait until TXE (Transmit data register empty) flag is set
        while(!(husart->SR & USART_SR_TXE));

        // Write data to DR
        husart->DR = buffer[i];
    }

    // Wait until TC (Transmission complete) flag is set
    while(!(husart->SR & USART_SR_TC));

    return len;
}
