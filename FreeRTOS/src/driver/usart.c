
#include <stdint.h>
#include <stdlib.h>

#include "usart.h"
#include "../cmsis/stm32f4xx.h"

void usart2_init(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;  // Enable GPIOA clock
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN; // Enable USART2 clock

    // Configure PA2 (USART2 TX) and PA3 (USART2 RX) in alternate function mode
    GPIOA->MODER &= ~(GPIO_MODER_MODER2 | GPIO_MODER_MODER3); // Clear mode bits
    GPIOA->MODER |= (GPIO_MODER_MODER2_1 | GPIO_MODER_MODER3_1); // Set to alternate function mode

    // Set alternate functions for PA2 and PA3 to be USART2 TX and RX
    GPIOA->AFR[0] |= (7 << (4 * (2 % 8))) | (7 << (4 * (3 % 8))); // USART2 is AF7
    
    // Assuming USART2 is connected to APB1
    uint32_t usart2_clk_freq = 50e6; // APB1 clock frequency

    // Calculate the USARTDIV value
    float usartdiv = (float)usart2_clk_freq / (16 * 115200);

    // Calculate the Mantissa part
    uint16_t mantissa = (uint16_t)usartdiv;

    // Calculate the Fraction part
    uint16_t fraction = (uint16_t)((usartdiv - mantissa) * 16);
    

    // Configure USART2
    USART2->BRR =  (mantissa << 4) | (fraction & 0x0F); // Set baud rate to 9600 [BRR = f_Clock / BaudRate]
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
