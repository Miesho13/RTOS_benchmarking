#ifndef __GPIO_H__
#define __GPIO_H__

#include "../cmsis/stm32f4xx.h"
#include "../cmsis/system_stm32f4xx.h"


typedef enum {
    GPIO_PIN00 = (1 << 0),
    GPIO_PIN01 = (1 << 1),
    GPIO_PIN02 = (1 << 2),
    GPIO_PIN03 = (1 << 3),
    GPIO_PIN04 = (1 << 4),
    GPIO_PIN05 = (1 << 5),
    GPIO_PIN06 = (1 << 6),
    GPIO_PIN07 = (1 << 7),
    GPIO_PIN08 = (1 << 8),
    GPIO_PIN09 = (1 << 9),
    GPIO_PIN10 = (1 << 10),
    GPIO_PIN11 = (1 << 11),
    GPIO_PIN12 = (1 << 12),
    GPIO_PIN13 = (1 << 13),
    GPIO_PIN14 = (1 << 14),
    GPIO_PIN15 = (1 << 15),

} GPIO_PINS;

typedef enum {
    GPIO_L,
    GPIO_H,

} GPIO_STATE;

typedef enum {
    GPIO_MODE_INPUT = 0,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_ALT,
    GPIO_MODE_ANALOG,

} GPIO_MODE;


typedef enum {
    GPIO_TYPE_PUSH_PULL = 0,
    GPIO_TYPE_OPEN_DRAIN,

} GPIO_TYPE;


typedef enum {
    GPIO_PUPD_NO = 0,
    GPIO_PUPD_UP,
    GPIO_PUPD_DOWN,

} GPIO_PUPD;


typedef enum {
    GPIO_SPEED_LOW = 0,
    GPIO_SPEED_MID,
    GPIO_SPEED_FAST,
    GPIO_SPEED_HIGH,

} GPIO_SPEED;


typedef struct {
    GPIO_TypeDef *GPIOx;
    GPIO_MODE mode;
    GPIO_SPEED speed;
    GPIO_PUPD pupd;
    uint16_t pins;
    GPIO_TYPE type;

} gpio_init_t;

void gpio_init(gpio_init_t hgpio);
void gpio_togle(GPIO_TypeDef *hgpio, GPIO_PINS pins);
void gpio_write(GPIO_TypeDef *hgpio, GPIO_PINS pins, GPIO_STATE state); 
uint16_t gpio_read(GPIO_TypeDef hgpio, GPIO_PINS pins); 
GPIO_STATE gpio_read_state(GPIO_TypeDef hgpio, GPIO_PINS pins);

#endif // __GPIO_H__
