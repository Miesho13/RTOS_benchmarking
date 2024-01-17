/**
 * @file tester.c
 * @author Your Name
 * @date Date Created
 * @brief This file contains the implementation for testing functionality.
 *
 * @details More details about the file, if necessary.
 *
 * This file is part of a project, and is used for testing various
 * components of the project. It contains several test functions
 * and helper functions to facilitate testing.
 */

#include "tester.h"


void trace_init(TIM_TypeDef *htim, uint32_t psc) {
    htim->PSC = psc;
    htim->ARR = 0xffffffff - 1;
    htim->CR1 |= TIM_CR1_CEN;
}

void trace_tim_reset(TIM_TypeDef *htim) {
    htim->CNT = 0;
}
