/**
 * @brief GPIO driver
 * 
 * @author marcin.ryzewskii@gmail.com
 * @date 2023-11-22
*/

#include "gpio.h"


void gpio_init(gpio_init_t hgpio) {
    // pins =  (1 << 1) | (1 << 3) | (1 << 14)
    for (uint16_t pin_ofs = 0; pin_ofs < 16; pin_ofs++) {
        if ((1 << pin_ofs) == (hgpio.pins & (1 << pin_ofs))) {
            hgpio.GPIOx->MODER |= (hgpio.mode << pin_ofs*2);
            hgpio.GPIOx->OTYPER |= (hgpio.type << pin_ofs);
            hgpio.GPIOx->OSPEEDR |= (hgpio.speed << pin_ofs*2);
            hgpio.GPIOx->PUPDR |= (hgpio.pupd << pin_ofs*2);
        }
    }
}


void gpio_togle(GPIO_TypeDef *hgpio, GPIO_PINS pins) {
    hgpio->ODR ^= pins;
}


void gpio_write(GPIO_TypeDef *hgpio, GPIO_PINS pins, GPIO_STATE state) {
    if (state == 1) {
        hgpio->BSRR |= pins;
    }
    if (state == 0) {
        hgpio->BSRR |= pins << 16;
    }
}


uint16_t gpio_read(GPIO_TypeDef hgpio, GPIO_PINS pins) {
    return (hgpio.IDR & pins);
}


GPIO_STATE gpio_read_state(GPIO_TypeDef hgpio, GPIO_PINS pins) {
    switch (pins) {
        case GPIO_PIN00:
            return (hgpio.IDR & GPIO_PIN00);
            break;
        
        case GPIO_PIN01:
            return (hgpio.IDR & GPIO_PIN01) >> 1;
            break;

        case GPIO_PIN02:
            return (hgpio.IDR & GPIO_PIN02) >> 2;
            break;

        case GPIO_PIN03:
            return (hgpio.IDR & GPIO_PIN03) >> 3;
            break;
        
        case GPIO_PIN04:
            return (hgpio.IDR & GPIO_PIN04) >> 4;
            break; 
        
        case GPIO_PIN05:
            return (hgpio.IDR & GPIO_PIN05) >> 5;
            break;
        
        case GPIO_PIN06:
            return (hgpio.IDR & GPIO_PIN06) >> 6;
            break;
        
        case GPIO_PIN07:
            return (hgpio.IDR & GPIO_PIN07) >> 7;
            break;
        
        case GPIO_PIN08:
            return (hgpio.IDR & GPIO_PIN08) >> 8;
            break;
        
        case GPIO_PIN09:
            return (hgpio.IDR & GPIO_PIN09) >> 9;
            break;
        
        case GPIO_PIN10:
            return (hgpio.IDR & GPIO_PIN10) >> 10;
            break;
        
        case GPIO_PIN11:
            return (hgpio.IDR & GPIO_PIN11) >> 11;
            break;
        
        case GPIO_PIN12:
            return (hgpio.IDR & GPIO_PIN12) >> 12;
            break;
        
        case GPIO_PIN13:
            return (hgpio.IDR & GPIO_PIN13) >> 13;
            break;
        
        case GPIO_PIN14:
            return (hgpio.IDR & GPIO_PIN14) >> 14;
            break;
        
        case GPIO_PIN15:
            return (hgpio.IDR & GPIO_PIN15) >> 15;
            break;
        
        default:
            return 0;
            break;
    }
    return 0;
}




