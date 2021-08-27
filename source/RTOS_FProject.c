
#include "RTOS_FProject.h"

SemaphoreHandle_t minutes_semaphore;
SemaphoreHandle_t hours_semaphore;
EventGroupHandle_t xEventGroup;
QueueHandle_t time_queue;
SemaphoreHandle_t xMutex;

const uint8_t cinves_Bitmap[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xfc, 0xfc, 0x3e, 0x1e, 0x9e, 0x9f, 0x8f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x9f, 0x8f, 0x9f, 0x9e, 0x9e, 0xfe, 0x7c, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0xfc, 0xfe, 0x7e, 0x1e, 0x0e, 0xcc, 0xf8, 0xf8, 0x78, 0xfc, 0x9e, 0x0f, 0x0f, 0x3f, 0x77, 0x63, 0x73, 0xfe, 0xf0, 0x30, 0x30, 0xfe, 0xf7, 0x73, 0x33, 0x1f, 0x0f, 0x07, 0xcf, 0xde, 0x3c, 0x7c, 0xfc, 0xf6, 0xc7, 0x07, 0x1f, 0x3f, 0xff, 0xfc, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x07, 0x01, 0x80, 0xc0, 0xc0, 0xc3, 0x43, 0xc5, 0xfc, 0xfe, 0x9f, 0x97, 0x18, 0x0e, 0x06, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x06, 0x0e, 0x89, 0xcf, 0x5f, 0xfe, 0xfa, 0xe3, 0x21, 0x60, 0xe0, 0xe0, 0xc0, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0f, 0x1f, 0x1f, 0x1f, 0x18, 0x08, 0x0f, 0x7f, 0xff, 0xfc, 0xcc, 0x87, 0xc7, 0xc3, 0xe0, 0xcf, 0x9f, 0xf0, 0x60, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x30, 0xfe, 0xcf, 0xe1, 0xe1, 0x43, 0x43, 0xc6, 0xf6, 0xff, 0xff, 0x0f, 0x04, 0x06, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xfc, 0xfe, 0xf6, 0xe3, 0xc3, 0x8f, 0x0f, 0x1e, 0x0c, 0x05, 0x03, 0x07, 0xc7, 0xfe, 0xce, 0xdf, 0x9d, 0xf9, 0x83, 0x83, 0x81, 0xdd, 0xfd, 0xcf, 0xce, 0xff, 0xe7, 0x03, 0x01, 0x02, 0x06, 0x0f, 0x87, 0xc7, 0xe1, 0xf1, 0xff, 0xff, 0x7e, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x1f, 0x3e, 0x3e, 0x7c, 0x78, 0x78, 0xf8, 0xf1, 0xf1, 0xfb, 0x7f, 0x03, 0x03, 0x03, 0x03, 0x03, 0x17, 0x7f, 0x79, 0xf9, 0x78, 0x7c, 0x7c, 0x3e, 0x3e, 0x1f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void taskLCDInit (void* pvParameters)
{
	uint32_t number = 0;
	for (;;)
	{
		nokiaLCD_initialise();

		nokiaLCD_clearDisplay(0);

		nokiaLCD_setBitmap(&cinves_Bitmap);

		nokiaLCD_updateDisplay();

		vTaskDelay(pdMS_TO_TICKS(2000));

//		volatile uint32_t i = 0;
//		for(i = 0; i < 100000; i++)
//		{
//			number ++;
//		}
//		number = 0;

		vTaskDelay(portMAX_DELAY);
	}
}

void seconds_task (void* pvParameters)
{
	alarm_time_t alarm = *((alarm_time_t*) pvParameters);

	TickType_t xLastWakeTime;
//	BaseType_t xWasDelayed;

	uint8_t seconds = INIT_SEC;
	time_msg_t secondsMsg = {.time_type = seconds_type, .value = 0U};
	time_msg_t *sMsg;

	secondsMsg.value = seconds;
	sMsg = pvPortMalloc(sizeof(time_msg_t));
	*sMsg = secondsMsg;
	xQueueSend(time_queue, &sMsg, portMAX_DELAY);

	for(;;)
	{
		xLastWakeTime = xTaskGetTickCount();

		if(alarm.second == seconds)
		{
			xEventGroupSetBits(xEventGroup, secondBIT);
		}

		secondsMsg.time_type = seconds_type;

		if(seconds >= 59)
		{
			seconds = 0;
			xSemaphoreGive(minutes_semaphore);
		}
		else
		{
			seconds++;
		}

		secondsMsg.value = seconds;
		sMsg = pvPortMalloc(sizeof(time_msg_t));
		*sMsg = secondsMsg;
		xQueueSend(time_queue, &sMsg, portMAX_DELAY);

		// Perform action here. xWasDelayed value can be used to determine
		// whether a deadline was missed if the code here took too long.
//		xWasDelayed = xTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(1000));
		xTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(1000));
	}
}

void minutes_task (void* pvParameters)
{
	alarm_time_t alarm = *((alarm_time_t*) pvParameters);

	uint8_t minutes = INIT_MIN;
	time_msg_t minutesMsg = {.time_type = minutes_type, .value = 0U};
	time_msg_t *mMsg;

	minutesMsg.value = minutes;
	mMsg = pvPortMalloc(sizeof(time_msg_t));
	*mMsg = minutesMsg;
	xQueueSend(time_queue, &mMsg, portMAX_DELAY);

	for(;;)
	{
		if(alarm.minute == minutes)
		{
			xEventGroupSetBits(xEventGroup, minuteBIT);
		}

		if (pdTRUE == xSemaphoreTake(minutes_semaphore, portMAX_DELAY))
		{
			minutesMsg.time_type = minutes_type;

			if(minutes >= 59)
			{
				minutes = 0;
				xSemaphoreGive(hours_semaphore);
			}
			else
			{
				minutes++;
			}
			minutesMsg.value = minutes;
			mMsg = pvPortMalloc(sizeof(time_msg_t));
			*mMsg = minutesMsg;
			xQueueSend(time_queue, &mMsg, portMAX_DELAY);
		}
	}
}

void hours_task (void* pvParameters)
{
	alarm_time_t alarm = *((alarm_time_t*) pvParameters);

	uint8_t hours = INIT_HOUR;
	time_msg_t hoursMsg = {.time_type = hours_type, .value = 0U};
	time_msg_t *hMsg;

	hoursMsg.value = hours;
	hMsg = pvPortMalloc(sizeof(time_msg_t));
	*hMsg = hoursMsg;
	xQueueSend(time_queue, &hMsg, portMAX_DELAY);

	for(;;)
	{
		if(alarm.hour == hours)
		{
			xEventGroupSetBits(xEventGroup, hourBIT);
		}

		if (pdTRUE == xSemaphoreTake(hours_semaphore, portMAX_DELAY))
		{
			hoursMsg.time_type = hours_type;

			if(hours >= 23)
			{
				hours = 0;
			}
			else
			{
				hours++;
			}
			hoursMsg.value = hours;
			hMsg = pvPortMalloc(sizeof(time_msg_t));
			*hMsg = hoursMsg;
			xQueueSend(time_queue, &hMsg, portMAX_DELAY);
		}
	}
}

void alarm_task (void* pvParameters)
{
	TickType_t xLastWakeTime;
	//	BaseType_t xWasDelayed;

	const EventBits_t xBitsToWaitFor = (secondBIT | minuteBIT | hourBIT);
	EventBits_t xEventGroupValue;
	uint8_t backlightFlag = 0;
	uint8_t alarmCounter = 0;
	uint8_t alarmString [] = "ALARM!";
	uint8_t alarmClear [] =  "      ";

	for(;;)
	{
		xLastWakeTime = xTaskGetTickCount();
		/*
		 * xEventGroupWaitBits(
		 * 		Event group to read,
		 * 		Bits to test,
		 * 		Clear bits if unblock,
		 * 		Wait for all bits?,
		 * 		Time out
		 * 		);
		 */
		xEventGroupValue = xEventGroupWaitBits(xEventGroup, xBitsToWaitFor, pdFALSE, pdTRUE, portMAX_DELAY);

		if ((xEventGroupValue & hourBIT) != 0)
		{
			if ((xEventGroupValue & minuteBIT) != 0)
			{
				if ((xEventGroupValue & secondBIT) != 0)
				{
					xSemaphoreTake(xMutex, portMAX_DELAY);
					// Encender Backlight
					// IMPRIMIR ALARM EN LCD
					nokiaLCD_setStr(alarmString, 25, 24, 1);
					nokiaLCD_updateDisplay();
//					PRINTF("\n\r ALARM!");

					if (!backlightFlag)
					{
						nokiaLCD_backlight(backlightFlag);
						backlightFlag = 1;
					}
					else
					{
						nokiaLCD_backlight(backlightFlag);
						backlightFlag = 0;
					}

					xSemaphoreGive(xMutex);

					if (ALARM_COUNTER == alarmCounter)
					{
						alarmCounter = 0;
						xEventGroupClearBits(xEventGroup, xBitsToWaitFor);
						xSemaphoreTake(xMutex, portMAX_DELAY);
						nokiaLCD_backlight(1);
						nokiaLCD_setStr(alarmClear, 25, 24, 1);
						nokiaLCD_updateDisplay();
						xSemaphoreGive(xMutex);
					}
					else
					{
						alarmCounter++;
					}
					xTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(1000));
				}
			}
		}
	}
}

void print_task (void* pvParameters)
{
	time_msg_t *tmsg;
	time_msg_t queueRec;
	alarm_time_t screenTime;
	screenTime.second = 0;
	screenTime.minute = 0;
	screenTime.hour = 0;

	uint8_t charTime[9] = {0};
	charTime[8] = 0x00;
	uint8_t uintTime[3] = {0};
	nokiaLCD_clearDisplay(0);

	for(;;)
	{
		xQueueReceive(time_queue, &tmsg, portMAX_DELAY);
		queueRec = *tmsg;
		vPortFree(tmsg);

		if(seconds_type == queueRec.time_type)
		{
			screenTime.second = queueRec.value;
			uintTime[0] = screenTime.second;

			timeBack2Char (charTime, uintTime);
			xSemaphoreTake(xMutex, portMAX_DELAY);

			nokiaLCD_setStr(charTime, 20, 16, 1);
			nokiaLCD_updateDisplay();
//			PRINTF("\n\r%2d:%2d:%2d", screenTime.hour, screenTime.minute, screenTime.second);

			xSemaphoreGive(xMutex);
		}
		else if(minutes_type == queueRec.time_type)
		{
			screenTime.minute = queueRec.value;
			uintTime[1] = screenTime.minute;
		}
		else if(hours_type == queueRec.time_type)
		{
			screenTime.hour = queueRec.value;
			uintTime[2] = screenTime.hour;
		}
	}
}

void timeBack2Char (uint8_t *timeData, uint8_t *intValues){
	uint8_t seg = 0, min = 0, hr = 0;
	uint8_t bcdLS = 0, bcdMS = 0;
	seg = intValues[0];
	min = intValues[1];
	hr 	= intValues[2];

	bcdLS = hr % 10;
	bcdMS = hr / 10;
	timeData[0] = bcdMS + 48;
	timeData[1] = bcdLS + 48;
	timeData[2] = (uint8_t) ':';
	bcdLS = min % 10;
	bcdMS = min / 10;
	timeData[3] = bcdMS + 48;
	timeData[4] = bcdLS + 48;
	timeData[5] = (uint8_t) ':';
	bcdLS = seg % 10;
	bcdMS = seg / 10;
	timeData[6] = bcdMS + 48;
	timeData[7] = bcdLS + 48;
}


