#include "relay_74ls595.h"

uint8 Relay_Output_Time = 100;
uint16 Relay_Clock_Time;
uint8 Relay_Output_Flag = 1;
uint8 Relay_Counter;
void Relay_74LS595_Output(void)
{
    static uint8 stOutput;
    static uint8 stOutputOld;
    
    HAL_GPIO_WritePin(RELAY_74LS595_SRCLK_GROUP,RELAY_74LS595_SRCLK_PIN,stOutput);
    if(0 == Relay_Output_Flag)
    {
        HAL_GPIO_WritePin(RELAY_74LS595_RCLK_GROUP,RELAY_74LS595_RCLK_PIN,(~stOutput)&0x01);
        HAL_GPIO_WritePin(RELAY_74LS595_SER_GROUP,RELAY_74LS595_SER_PIN,GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(RELAY_74LS595_SER_GROUP,RELAY_74LS595_SER_PIN,GPIO_PIN_SET);
    }

    Relay_Clock_Time++;
    if(Relay_Clock_Time>=Relay_Output_Time)
    {
        stOutput = (~stOutput)&0x01;
        Relay_Clock_Time = 0;
        Relay_Counter++;
        if(Relay_Counter>8)
        {
            Relay_Counter = 0;
            Relay_Output_Flag = 1;
        }
    }

    if((stOutput == 0)&&(stOutputOld == 1))
    {
        Relay_Output_Flag = 0;
    }

    stOutputOld = stOutput;
}
