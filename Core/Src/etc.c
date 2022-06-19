#include "etc.h"

uint8 Switch_stOnOff;
uint8 Switch_stDIP;

uint8 LED_OnOff_Timer;

void Switch_Scan(void)
{
	Switch_stOnOff = HAL_GPIO_ReadPin(SWITCH_ONOFF_GROUP,SWITCH_ONOFF_PIN);
	Switch_stDIP = HAL_GPIO_ReadPin(SWITCH_DIP_GROUP,SWITCH_DIP_PIN_0) |
	               HAL_GPIO_ReadPin(SWITCH_DIP_GROUP,SWITCH_DIP_PIN_1)<<1 |
				   HAL_GPIO_ReadPin(SWITCH_DIP_GROUP,SWITCH_DIP_PIN_2)<<2;
	return;
}

void LED_Output(void)
{
	LED_OnOff_Timer++;
	if(LED_OnOff_Timer>=10)
	{
		HAL_GPIO_WritePin(LED_GROUP,LED_PIN,LED_ON);
	}
	else
	{
		HAL_GPIO_WritePin(LED_GROUP,LED_PIN,LED_OFF);
	}

	if(LED_OnOff_Timer>=20)
	{
		LED_OnOff_Timer = 0;
	}
}
