/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_wifi.h"

void hex_str(unsigned char *inchar, unsigned int len, unsigned char *outtxt)
{
        unsigned char hbit,lbit;
        unsigned int i;
  for(i=0;i<len;i++)
{
        hbit = (*(inchar+i)&0xf0)>>4;
      lbit = *(inchar+i)&0x0f;
        if (hbit>9) outtxt[2*i]='A'+hbit-10;
  else outtxt[2*i]='0'+hbit;
        if (lbit>9) outtxt[2*i+1]='A'+lbit-10;
  else    outtxt[2*i+1]='0'+lbit;
    }
outtxt[2*i] = 0;
}
void app_main()
{
    printf("Hello world!\n");
	uint8_t eth_mac[6];
	uint8_t mac[13];
	mac[12]='\0';
	esp_wifi_get_mac(WIFI_IF_STA, eth_mac);
	for(int i=0;i<6;i++)
		printf("%02x",eth_mac[i]);
	hex_str(eth_mac,6,mac);
	printf("the mac is %s\n",mac);
//    /* Print chip information */
//    esp_chip_info_t chip_info;
//    esp_chip_info(&chip_info);
//    printf("This is ESP32 chip with %d CPU cores, WiFi%s%s, ",
//            chip_info.cores,
//            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
//            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
//
//    printf("silicon revision %d, ", chip_info.revision);
//
//    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
//            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
//
//    for (int i = 10; i >= 0; i--) {
//        printf("Restarting in %d seconds...\n", i);
//        vTaskDelay(1000 / portTICK_PERIOD_MS);
//    }
//    printf("Restarting now.\n");
//    fflush(stdout);
//    esp_restart();
}
