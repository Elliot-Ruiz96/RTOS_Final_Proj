/*
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*** INCLUDE FILES ***/
// Standard Libraries
#include <stdint.h>

// FRDM K64F Libraries
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"

// FreeRTOS Libraries
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "event_groups.h"
#include "queue.h"

// Project Libraries
#include "RTOS_FProject.h"
#include "nokiaLCD.h"

/*** DECLARATIONS ***/
extern SemaphoreHandle_t minutes_semaphore;
extern SemaphoreHandle_t hours_semaphore;
extern EventGroupHandle_t xEventGroup;
extern QueueHandle_t time_queue;
extern SemaphoreHandle_t xMutex;

int main(void) {
    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    PRINTF("\n\rHello World");

    xMutex = xSemaphoreCreateMutex();

    xEventGroup = xEventGroupCreate();

    time_queue = xQueueCreate(QUEUE_SIZE, sizeof(time_msg_t*));
    vQueueAddToRegistry(time_queue, "Time Queue");

    static const alarm_time_t alarm = {.second = ALARM_SEC, .minute = ALARM_MIN, .hour = ALARM_HOUR};

    minutes_semaphore = xSemaphoreCreateBinary();
    vQueueAddToRegistry(minutes_semaphore, "Sec2Min Semphr");

    hours_semaphore = xSemaphoreCreateBinary();
    vQueueAddToRegistry(hours_semaphore, "Min2Hrs Semphr");

    xTaskCreate(taskLCDInit, "InitLCD Task",  (configMINIMAL_STACK_SIZE*2), NULL, 		   (configMAX_PRIORITIES), NULL);

    xTaskCreate(seconds_task, "Seconds Task", (configMINIMAL_STACK_SIZE*3), (void*)&alarm, (configMAX_PRIORITIES-3), NULL);
    xTaskCreate(minutes_task, "Minutes Task", (configMINIMAL_STACK_SIZE*3), (void*)&alarm, (configMAX_PRIORITIES-2), NULL);
    xTaskCreate(hours_task, "Hours Task", 	  (configMINIMAL_STACK_SIZE*3), (void*)&alarm, (configMAX_PRIORITIES-1), NULL);
    xTaskCreate(alarm_task, "Alarm Task", 	  (configMINIMAL_STACK_SIZE*3), NULL, 		   (configMAX_PRIORITIES-4), NULL);
    xTaskCreate(print_task, "Print Task", 	  (configMINIMAL_STACK_SIZE*3), NULL, 		   (configMAX_PRIORITIES-4), NULL);

    vTaskStartScheduler();

    /* Force the counter to be placed into memory. */
    volatile static uint32_t i = 0 ;

    while(1)
    {
    	nokiaLCD_backlight(1);
		for(i = 0; i < 65535; i++){}
		nokiaLCD_backlight(0);
		for(i = 0; i < 65535; i++){}
    }
    return 0 ;
}
