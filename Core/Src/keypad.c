#include "keypad.h"

uint8 keypadnum = KEYPAD_NUM_DEFAULT;
uint8 row , column;
uint32 debounce_counter;

void Key_Scan(void)
{
	switch(column)
	{
		case(0) :
		    HAL_GPIO_WritePin(KEYPAD_OUT_CH0_GROUP,KEYPAD_OUT_CH0_PIN,KEYPAD_OFF);
		    HAL_GPIO_WritePin(KEYPAD_OUT_CH1_GROUP,KEYPAD_OUT_CH1_PIN,KEYPAD_ON);
			HAL_GPIO_WritePin(KEYPAD_OUT_CH2_GROUP,KEYPAD_OUT_CH2_PIN,KEYPAD_ON);
		    HAL_GPIO_WritePin(KEYPAD_OUT_CH3_GROUP,KEYPAD_OUT_CH3_PIN,KEYPAD_ON);			
		break;
		case(1) :
		    HAL_GPIO_WritePin(KEYPAD_OUT_CH0_GROUP,KEYPAD_OUT_CH0_PIN,KEYPAD_ON);
		    HAL_GPIO_WritePin(KEYPAD_OUT_CH1_GROUP,KEYPAD_OUT_CH1_PIN,KEYPAD_OFF);
			HAL_GPIO_WritePin(KEYPAD_OUT_CH2_GROUP,KEYPAD_OUT_CH2_PIN,KEYPAD_ON);
		    HAL_GPIO_WritePin(KEYPAD_OUT_CH3_GROUP,KEYPAD_OUT_CH3_PIN,KEYPAD_ON);		
		break;
		case(2) :
		    HAL_GPIO_WritePin(KEYPAD_OUT_CH0_GROUP,KEYPAD_OUT_CH0_PIN,KEYPAD_ON);
		    HAL_GPIO_WritePin(KEYPAD_OUT_CH1_GROUP,KEYPAD_OUT_CH1_PIN,KEYPAD_ON);
			HAL_GPIO_WritePin(KEYPAD_OUT_CH2_GROUP,KEYPAD_OUT_CH2_PIN,KEYPAD_OFF);
		    HAL_GPIO_WritePin(KEYPAD_OUT_CH3_GROUP,KEYPAD_OUT_CH3_PIN,KEYPAD_ON);		
		break;
		case(3) :
		    HAL_GPIO_WritePin(KEYPAD_OUT_CH0_GROUP,KEYPAD_OUT_CH0_PIN,KEYPAD_ON);
		    HAL_GPIO_WritePin(KEYPAD_OUT_CH1_GROUP,KEYPAD_OUT_CH1_PIN,KEYPAD_ON);
			HAL_GPIO_WritePin(KEYPAD_OUT_CH2_GROUP,KEYPAD_OUT_CH2_PIN,KEYPAD_ON);
		    HAL_GPIO_WritePin(KEYPAD_OUT_CH3_GROUP,KEYPAD_OUT_CH3_PIN,KEYPAD_OFF);		
		break;
		default :
		break;
	}

	row =	HAL_GPIO_ReadPin(KEYPAD_IN_CH0_GROUP,KEYPAD_IN_CH0_PIN)		|
		   (HAL_GPIO_ReadPin(KEYPAD_IN_CH1_GROUP,KEYPAD_IN_CH1_PIN)<<1)	|
		   (HAL_GPIO_ReadPin(KEYPAD_IN_CH2_GROUP,KEYPAD_IN_CH2_PIN)<<2)	|
		   (HAL_GPIO_ReadPin(KEYPAD_IN_CH3_GROUP,KEYPAD_IN_CH3_PIN)<<3);

	if((column == 0) && (row != 0))
	{
		if(row == 7)
		{
			keypadnum = KEYPAD_NUM_1;
		}
		else if(row == 11)
		{
			keypadnum = KEYPAD_NUM_2;
		}
		else if(row == 13)
		{
			keypadnum = KEYPAD_NUM_3;
		}
		else if(row == 14)
		{
			keypadnum = KEYPAD_NUM_4;
		}
	}
	else if((column == 1) && (row != 0))
	{
		if(row == 7)
		{
			keypadnum = KEYPAD_NUM_5;
		}
		else if(row == 11)
		{
			keypadnum = KEYPAD_NUM_6;
		}
		else if(row == 13)
		{
			keypadnum = KEYPAD_NUM_7;
		}
		else if(row == 14)
		{
			keypadnum = KEYPAD_NUM_8;
		}
	}
	else if((column == 2) && (row != 0))
	{
		if(row == 7)
		{
			keypadnum = KEYPAD_NUM_9;
		}
		else if(row == 11)
		{
			keypadnum = KEYPAD_NUM_10;
		}
		else if(row == 13)
		{
			keypadnum = KEYPAD_NUM_11;
		}
		else if(row == 14)
		{
			keypadnum = KEYPAD_NUM_12;
		}
	}
	else if((column == 3) && (row != 0))
	{
		if(row == 7)
		{
			keypadnum = KEYPAD_NUM_13;
		}
		else if(row == 11)
		{
			keypadnum = KEYPAD_NUM_14;
		}
		else if(row == 13)
		{
			keypadnum = KEYPAD_NUM_15;
		}
		else if(row == 14)
		{
			keypadnum = KEYPAD_NUM_16;
		}
	}

	column++;

	if(column>3)
	{
		column=0;
	}
	if((row == 15))
	{
		debounce_counter++;
		if(debounce_counter >KEYPAD_DEBOUNCE)
		{
			keypadnum = KEYPAD_NUM_DEFAULT;
			debounce_counter = 0;
		}
	}
	else
	{
		debounce_counter = 0;
	}


	return;
}
