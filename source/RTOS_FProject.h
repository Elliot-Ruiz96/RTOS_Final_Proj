
#ifndef RTOS_FPROJECT_H_
#define RTOS_FPROJECT_H_

/*** INCLUDE FILES ***/
// Standard Libraries
#include <stdint.h>

// FRDM K64F Libraries
#include "fsl_debug_console.h"

// FreeRTOS Libraries
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "event_groups.h"
#include "queue.h"

// Project Libraries
#include "nokiaLCD.h"

/*** PROJECT MACROS ***/
// Event Group Macros
#define secondBIT (1U << 0U)
#define minuteBIT (1U << 1U)
#define hourBIT	  (1U << 2U)

// Alarm Macros
#define ALARM_SEC 	0U
#define ALARM_MIN 	0U
#define ALARM_HOUR 	0U
#define INIT_SEC 	55U
#define INIT_MIN 	59U
#define INIT_HOUR 	23U

#define ALARM_COUNTER 16U

// Other Macros
#define QUEUE_SIZE 9U


/*** PROJECT ENUMs & STRUCTs***/
typedef enum{seconds_type, minutes_type, hours_type} time_types_t;

typedef struct
{
	time_types_t time_type;
	uint8_t value;
}time_msg_t;

typedef struct
{
	uint8_t second;
	uint8_t minute;
	uint8_t hour;
} alarm_time_t;

/*** FUNCTION PROTOTYPES ***/
// For Tasks
void seconds_task (void* pvParameters);
void minutes_task (void* pvParameters);
void hours_task (void* pvParameters);
void alarm_task (void* pvParameters);
void print_task (void* pvParameters);
void taskLCDInit (void* pvParameters);

// Other prototypes
void timeBack2Char (uint8_t *timeData, uint8_t *intValues);

#endif /* RTOS_FPROJECT_H_ */
