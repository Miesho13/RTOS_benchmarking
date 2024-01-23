/****************************************************************************
 * apps/examples/hello/hello_main.c
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

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/clock.h>
#include <nuttx/time.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include "./c_util/tracer.h"
#include <semaphore.h>
#include <signal.h>

#include "./cmsis/stm32f411xe.h"


#define STACKSIZE 1024
#define LOW_PRIORITY 100
#define MID_PRIORITY 150
#define HIGH_PRIORITY 200

static sem_t sem;

static void *high_priority_func(void *arg)
{
    printf("[T2] Start\n");

    printf("[T2] Try to acquire semaphore\n");
    sem_wait(&sem);

    printf("[T2] End\n");
    pthread_exit(NULL);
}

static void *mid_priority_func(void *arg)
{
    printf("[T3] Start\n");

    printf("[T3] Try to acquire semaphore\n");
    sem_wait(&sem);

    printf("[T3] End\n");
    pthread_exit(NULL);
}


int main(int argc, FAR char *argv[]) {

    RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
    trace_init(TIM5, 1);
    
    pthread_t thread2, thread3;
    pthread_attr_t attr;
    struct sched_param sparam;

    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, STACKSIZE);

    printf("[T1] Set priority to low\n");
    sparam.sched_priority = LOW_PRIORITY;
    pthread_setschedparam(pthread_self(), SCHED_OTHER, &sparam);

    printf("[T1] Create semaphore\n");
    sem_init(&sem, 0, 0);

    printf("[T1] Create T2\n");
    sparam.sched_priority = HIGH_PRIORITY;
    pthread_attr_setschedparam(&attr, &sparam);
    pthread_create(&thread2, &attr, high_priority_func, NULL);

    printf("[T1] Create T3\n");
    sparam.sched_priority = MID_PRIORITY;
    pthread_attr_setschedparam(&attr, &sparam);
    pthread_create(&thread3, &attr, mid_priority_func, NULL);

    printf("[T1] Release semaphore\n");
    sem_post(&sem);

    printf("[T1] Release semaphore again\n");    

    return 0;
}

