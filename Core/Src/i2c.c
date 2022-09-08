
#include "i2c.h"

uint8 I2C_Address;

uint8 I2C_Tx_Data[100];

void I2C_FindAddress(void)
{
    I2C_Tx_Data[0] = 0x08;
    //HAL_I2C_Master_Transmit(&I2C_MODULE,0xE1,I2C_Tx_Data,1,100);
    #if 0
    if(HAL_OK == HAL_I2C_IsDeviceReady(&I2C_MODULE,I2C_Address,3,10))
    {
        /*do noThing*/
    }
    else
    {
        I2C_Address++;
    }
    #endif
}

void I2C_LCD_Transmit(void)
{
   //HAL_I2C_Master_Transmit(&I2C_MODULE,)
}