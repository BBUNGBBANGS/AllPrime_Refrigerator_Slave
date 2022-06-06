#include "keypad.h"

uint8 keypadnum = KEYPAD_NUM_DEFAULT;
uint8 row , column;
uint32 debounce_counter;
uint32 debounce_counter1;
uint8 testread1,testread2,testread3,testread4;
void Key_Scan(void)
{
	//row = 0 ;
	switch(column)
	{

		case(0) :
		    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,GPIO_PIN_SET);
		break;
		case(1) :
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_7,GPIO_PIN_SET);
		break;
		case(2) :
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7,GPIO_PIN_SET);
		break;
		case(3) :
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6,GPIO_PIN_SET);
		break;
		default :
		break;
	}

	row =	HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_0)		|
		   (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_1)<<1)	|
		   (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_2)<<2)	|
		   (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_3)<<3);

	if(row != 0)
	{
		debounce_counter1++;
	}

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

uint8 Key_stDIP1,Key_stDIP2,Key_stDIP3;
uint8 Key_OnOff;
void Key_Input(void)
{
	static uint8 timer;
	Key_stDIP1 = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0);
	Key_stDIP2 = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1);
	Key_stDIP3 = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2);
	Key_OnOff = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15);

	timer++;
	if(timer > 20)
	{
		timer = 0;
	}

	if(timer<10)
	{
		//HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,0);
		//HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,0);
		//HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,0);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,0);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,0);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,0);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,0);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,0);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,0);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_10,0);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_11,0);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,0);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,0);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,0);
	}
	else
	{
		//HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,1);
		//HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,1);
		//HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,1);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,1);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,1);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,1);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,1);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_10,1);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_11,1);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,1);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,1);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,1);
	}
}