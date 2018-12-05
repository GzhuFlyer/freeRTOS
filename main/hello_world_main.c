#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
//#include "esp_system.h"
//#include "esp_spi_flash.h"
//#include "esp_wifi.h"

#define DELAY_TIME 150000000

static const char *pcTextForTask1 = "Task 1 is running \r\n";
static const char *pcTextForTask2 = "Task 2 is running \r\n";
static const char *pcTextForTask3 = "Task 3 is running \r\n";
static const char *pcTextForTask4 = "Task 4 is running \r\n";


void vPrintfString(char* c)
{
	printf("%s\n",c);
}

void vTask1(void *pvParameters)
{
//	const char *pvTaskName = "Task 1 is running \r\n";
	volatile unsigned long u1;
	for(;;)
	{
		vPrintfString(pvParameters);
		vTaskDelay(500);
//		for(u1 = 0;u1 < DELAY_TIME;u1++)
//		{
//
//		}
	}
	vTaskDelete(NULL);
}
void vTask2(void *pvParameters)
{
//	const char *pvTaskName = "Task 2 is running \r\n";
	volatile unsigned long u1;
	for(;;)
	{
		vPrintfString(pvParameters);
		vTaskDelay(500);
//		for(u1 = 0;u1 < DELAY_TIME;u1++)
//		{
//
//		}
	}
	vTaskDelete(NULL);
}
void vTask3(void *pvParameters)
{
//	const char *pvTaskName = "Task 3 is running \r\n";
	volatile unsigned long u1;
	for(;;)
	{
		vPrintfString(pvParameters);
		vTaskDelay(500);
//		for(u1 = 0;u1 < DELAY_TIME;u1++)
//		{
//
//		}
	}
	vTaskDelete(NULL);
}
void vTask4(void *pvParameters)
{
//	const char *pvTaskName = "Task 4 is running \r\n";
	volatile unsigned long u1;
	for(;;)
	{
		vPrintfString(pvParameters);
		vTaskDelay(500);
//		for(u1 = 0;u1 < DELAY_TIME;u1++)
//		{
//
//		}
	}
	vTaskDelete(NULL);
}


void app_main()
{
    printf("Hello world!\n");
    xTaskCreate(vTask1,"Task 1",1000,pcTextForTask1,1,NULL);
	xTaskCreate(vTask2,"Task 2",1000,pcTextForTask2,2,NULL);
	xTaskCreate(vTask3,"Task 3",1000,pcTextForTask3,4,NULL);
	xTaskCreate(vTask4,"Task 4",1000,pcTextForTask4,4,NULL);

}
