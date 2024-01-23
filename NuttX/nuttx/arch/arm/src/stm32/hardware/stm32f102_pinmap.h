/****************************************************************************
 * arch/arm/src/stm32/hardware/stm32f102_pinmap.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __ARCH_ARM_SRC_STM32_HARDWARE_STM32F102_PINMAP_H
#define __ARCH_ARM_SRC_STM32_HARDWARE_STM32F102_PINMAP_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Alternate Pin Functions: */

#define GPIO_ADC12_IN0_0        (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN0)
#define GPIO_ADC12_IN1_0        (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN1)
#define GPIO_ADC12_IN2_0        (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN2)
#define GPIO_ADC12_IN3_0        (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN3)
#define GPIO_ADC12_IN4_0        (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN4)
#define GPIO_ADC12_IN5_0        (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN5)
#define GPIO_ADC12_IN6_0        (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN6)
#define GPIO_ADC12_IN7_0        (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN7)
#define GPIO_ADC12_IN8_0        (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN0)
#define GPIO_ADC12_IN9_0        (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN1)
#define GPIO_ADC12_IN10_0       (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN0)
#define GPIO_ADC12_IN11_0       (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN1)
#define GPIO_ADC12_IN12_0       (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN2)
#define GPIO_ADC12_IN13_0       (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN3)
#define GPIO_ADC12_IN14_0       (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN4)
#define GPIO_ADC12_IN15_0       (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN5)

#if defined(CONFIG_STM32_I2C1_REMAP)
#  define GPIO_I2C1_SCL_0       (GPIO_ALT|GPIO_CNF_AFOD|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN8)
#  define GPIO_I2C1_SDA_0       (GPIO_ALT|GPIO_CNF_AFOD|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN9)
#else
#  define GPIO_I2C1_SCL_0       (GPIO_ALT|GPIO_CNF_AFOD|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN6)
#  define GPIO_I2C1_SDA_0       (GPIO_ALT|GPIO_CNF_AFOD|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN7)
#endif
#define GPIO_I2C1_SMBA_0        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN5)

#define GPIO_I2C2_SCL_0         (GPIO_ALT|GPIO_CNF_AFOD|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN10)
#define GPIO_I2C2_SDA_0         (GPIO_ALT|GPIO_CNF_AFOD|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN11)
#define GPIO_I2C2_SMBA_0        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN12)

#define GPIO_MCO_0              (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN8)

#if defined(CONFIG_STM32_SPI1_REMAP)
#  define GPIO_SPI1_NSS_0       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN15)
#  define GPIO_SPI1_SCK_0       (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN3)
#  define GPIO_SPI1_MISO_0      (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN4)
#  define GPIO_SPI1_MOSI_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN5)
#else
#  define GPIO_SPI1_NSS_0       (GPIO_INPUT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN4)
#  define GPIO_SPI1_SCK_0       (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN5)
#  define GPIO_SPI1_MISO_0      (GPIO_INPUT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN6)
#  define GPIO_SPI1_MOSI_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN7)
#endif

#define GPIO_SPI2_NSS_0         (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN12)
#define GPIO_SPI2_SCK_0         (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN13)
#define GPIO_SPI2_MISO_0        (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN14)
#define GPIO_SPI2_MOSI_0        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN15)

#if defined(CONFIG_STM32_TIM2_FULL_REMAP)
#  define GPIO_TIM2_ETR_0       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN15)
#  define GPIO_TIM2_CH1IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN15)
#  define GPIO_TIM2_CH1OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN15)
#  define GPIO_TIM2_CH2IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN3)
#  define GPIO_TIM2_CH2OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN3)
#  define GPIO_TIM2_CH3IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN10)
#  define GPIO_TIM2_CH3OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN10)
#  define GPIO_TIM2_CH4IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN11)
#  define GPIO_TIM2_CH4OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN11)
#elif defined(CONFIG_STM32_TIM2_PARTIAL_REMAP_1)
#  define GPIO_TIM2_ETR_0       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN15)
#  define GPIO_TIM2_CH1IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN15)
#  define GPIO_TIM2_CH1OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN15)
#  define GPIO_TIM2_CH2IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN3)
#  define GPIO_TIM2_CH2OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN3)
#  define GPIO_TIM2_CH3IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN2)
#  define GPIO_TIM2_CH3OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN2)
#  define GPIO_TIM2_CH4IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN3)
#  define GPIO_TIM2_CH4OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN3)
#elif defined(CONFIG_STM32_TIM2_PARTIAL_REMAP_2)
#  define GPIO_TIM2_ETR_0       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN0)
#  define GPIO_TIM2_CH1IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN0)
#  define GPIO_TIM2_CH1OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN0)
#  define GPIO_TIM2_CH2IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN1)
#  define GPIO_TIM2_CH2OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN1)
#  define GPIO_TIM2_CH3IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN10)
#  define GPIO_TIM2_CH3OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN10)
#  define GPIO_TIM2_CH4IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN11)
#  define GPIO_TIM2_CH4OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN11)
#else
#  define GPIO_TIM2_ETR_0       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN0)
#  define GPIO_TIM2_CH1IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN0)
#  define GPIO_TIM2_CH1OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN0)
#  define GPIO_TIM2_CH2IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN1)
#  define GPIO_TIM2_CH2OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN1)
#  define GPIO_TIM2_CH3IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN2)
#  define GPIO_TIM2_CH3OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN2)
#  define GPIO_TIM2_CH4IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN3)
#  define GPIO_TIM2_CH4OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN3)
#endif

#if defined(CONFIG_STM32_TIM3_FULL_REMAP)
#  define GPIO_TIM3_CH1IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN6)
#  define GPIO_TIM3_CH1OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTC|GPIO_PIN6)
#  define GPIO_TIM3_CH2IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN7)
#  define GPIO_TIM3_CH2OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTC|GPIO_PIN7)
#  define GPIO_TIM3_CH3IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN8)
#  define GPIO_TIM3_CH3OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTC|GPIO_PIN8)
#  define GPIO_TIM3_CH4IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN9)
#  define GPIO_TIM3_CH4OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTC|GPIO_PIN9)
#elif defined(CONFIG_STM32_TIM3_PARTIAL_REMAP)
#  define GPIO_TIM3_CH1IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN4)
#  define GPIO_TIM3_CH1OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN4)
#  define GPIO_TIM3_CH2IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN5)
#  define GPIO_TIM3_CH2OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN5)
#  define GPIO_TIM3_CH3IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN0)
#  define GPIO_TIM3_CH3OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN0)
#  define GPIO_TIM3_CH4IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN1)
#  define GPIO_TIM3_CH4OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN1)
#else
#  define GPIO_TIM3_CH1IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN6)
#  define GPIO_TIM3_CH1OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN6)
#  define GPIO_TIM3_CH2IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN7)
#  define GPIO_TIM3_CH2OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN7)
#  define GPIO_TIM3_CH3IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN0)
#  define GPIO_TIM3_CH3OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN0)
#  define GPIO_TIM3_CH4IN_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN1)
#  define GPIO_TIM3_CH4OUT_0    (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN1)
#endif
#define GPIO_TIM3_ETR_0         (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN2)

#if defined(CONFIG_STM32_TIM4_FULL_REMAP)
#  define GPIO_TIM4_CH1IN_0       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN12)
#  define GPIO_TIM4_CH1OUT_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTD|GPIO_PIN12)
#  define GPIO_TIM4_CH2IN_0       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN13)
#  define GPIO_TIM4_CH2OUT_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTD|GPIO_PIN13)
#  define GPIO_TIM4_CH3IN_0       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN14)
#  define GPIO_TIM4_CH3OUT_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTD|GPIO_PIN14)
#  define GPIO_TIM4_CH4IN_0       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN15)
#  define GPIO_TIM4_CH4OUT_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTD|GPIO_PIN15)
#else
#  define GPIO_TIM4_CH1IN_0       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN6)
#  define GPIO_TIM4_CH1OUT_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN6)
#  define GPIO_TIM4_CH2IN_0       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN7)
#  define GPIO_TIM4_CH2OUT_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN7)
#  define GPIO_TIM4_CH3IN_0       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN8)
#  define GPIO_TIM4_CH3OUT_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN8)
#  define GPIO_TIM4_CH4IN_0       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN9)
#  define GPIO_TIM4_CH4OUT_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN9)
#endif

/* USARTS */

#define GPIO_USART1_CTS_0       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN11)
#define GPIO_USART1_RTS_0       (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN12)
#define GPIO_USART1_CK_0        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN8)
#if defined(CONFIG_STM32_USART1_REMAP)
#  define GPIO_USART1_TX_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN6)
#  define GPIO_USART1_RX_0      (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN7)
#else
#  define GPIO_USART1_TX_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN9)
#  define GPIO_USART1_RX_0      (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN10)
#endif

#if defined(CONFIG_STM32_USART2_REMAP)
#  define GPIO_USART2_CTS_0      (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN3)
#  define GPIO_USART2_RTS_0     (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTD|GPIO_PIN4)
#  define GPIO_USART2_TX_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTD|GPIO_PIN5)
#  define GPIO_USART2_RX_0      (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN6)
#  define GPIO_USART2_CK_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTD|GPIO_PIN7)
#else
#  define GPIO_USART2_CTS_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN0)
#  define GPIO_USART2_RTS_0     (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN1)
#  define GPIO_USART2_TX_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN2)
#  define GPIO_USART2_RX_0      (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN3)
#  define GPIO_USART2_CK_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN4)
#endif

#if defined(CONFIG_STM32_USART3_FULL_REMAP)
#  define GPIO_USART3_TX_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTD|GPIO_PIN8)
#  define GPIO_USART3_RX_0      (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN9)
#  define GPIO_USART3_CK_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTD|GPIO_PIN10)
#  define GPIO_USART3_CTS_0      (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN11)
#  define GPIO_USART3_RTS_0     (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTD|GPIO_PIN12)
#elif defined(CONFIG_STM32_USART3_PARTIAL_REMAP)
#  define GPIO_USART3_TX_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTC|GPIO_PIN10)
#  define GPIO_USART3_RX_0      (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN11)
#  define GPIO_USART3_CK_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTC|GPIO_PIN12)
#  define GPIO_USART3_CTS_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN13)
#  define GPIO_USART3_RTS_0     (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN14)
#else
#  define GPIO_USART3_TX_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN10)
#  define GPIO_USART3_RX_0      (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN11)
#  define GPIO_USART3_CK_0      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN12)
#  define GPIO_USART3_CTS_0     (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN13)
#  define GPIO_USART3_RTS_0     (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN14)
#endif

#define GPIO_WKUP_0             (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN0)

/* These GPIOs are shared with JTAG / SWD. */

#if defined(CONFIG_STM32_JTAG_DISABLE)
#  define GPIO_PA13_0             (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN13)
#  define GPIO_PA14_0             (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN14)
#endif
#if defined (CONFIG_STM32_JTAG_SW_ENABLE) || defined(CONFIG_STM32_JTAG_NOJNTRST_ENABLE) || defined(CONFIG_STM32_JTAG_DISABLE)
#    define GPIO_PB4_0            (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN4)
#    if defined (CONFIG_STM32_JTAG_SW_ENABLE) || defined(CONFIG_STM32_JTAG_DISABLE)
#      define GPIO_PA15_0          (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTA|GPIO_PIN15)
#      define GPIO_PB3_0           (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_2MHz|GPIO_PORTB|GPIO_PIN3)
#    endif
#endif

#endif /* __ARCH_ARM_SRC_STM32_HARDWARE_STM32F102_PINMAP_H */