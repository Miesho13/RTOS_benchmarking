/**
 * @file tester.h
 * @author Your Name
 * @date Date Created
 * @brief This header file contains the declarations for testing functionality.
 *
 * @details More details about the file, if necessary.
 *
 * This file is part of a project, and is used for declaring various
 * components for testing. It contains several function prototypes
 * and type definitions to facilitate testing.
 */


#ifndef __TESTER__
#define __TESTER__


#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include "../cmsis/stm32f4xx.h"

#define NOT_IMPLEMENTED() assert(false)

#define START_TRACE(trace_time, TIMx) trace_time.t1 = TIMx->CNT
#define STOP_TRACE(trace_time, TIMx)  trace_time.t2 = TIMx->CNT

typedef struct {
    volatile uint32_t t1; 
    volatile uint32_t t2;

} trace_time_t;


void trace_init(TIM_TypeDef *htim);
void trace_tim_reset(TIM_TypeDef *htim);

#endif

