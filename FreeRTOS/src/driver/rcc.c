/*
 * File: rcc.c
 * Author: <marcin.ryzewskii@gmail.com>
 * Date: <12.2023>
 *
 * This file contains the RCC_Init function which configures the system clock to 100MHz using the High Speed External (HSE) clock and the Phase Locked Loop (PLL).
 *
 * Note: This function assumes that the HSE clock is 8MHz. If the HSE clock is a different speed, the PLL multiplication factor should be adjusted accordingly.
 */

#include "rcc.h"
#include "../cmsis/stm32f411xe.h"
#include "../cmsis/system_stm32f4xx.h"


void RCC_Init_100MHz(void) {
    // ensure for HSI is rdy
    RCC->CR |= RCC_CR_HSION;
    while (((RCC->CR & RCC_CR_HSIRDY) >> 1) != 1) { }
    
    // enable HSE
    RCC->CR |= RCC_CR_HSEON;
    while (((RCC->CR & RCC_CR_HSERDY) >> 17) != 1) { }
    
    RCC->PLLCFGR = (1 << 22) | (8 << 0) | (100 << 6) | (0 << 16);

    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));
    FLASH->ACR = FLASH_ACR_LATENCY_3WS;
    
    RCC->CFGR &= ~(0b1111 << 4);

    RCC->CFGR &= ~RCC_CFGR_PPRE1; // Clear the APB1 prescaler bits
    RCC->CFGR &= ~RCC_CFGR_PPRE2; // Clear the APB2 prescaler bits
                                  
    RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_SW_Msk) | RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_PLL);

    SystemCoreClockUpdate();
}

