#ifndef _I2C_H
#define _I2C_H

#include "main.h"

#define I2C_MODULE          (hi2c2)

#define I2C_LCD_ADDRESS     (0x3C)
#define I2C_CO2_ADDRESS     ()
#define I2C_HTU_ADDRESS     (0x64)
#define I2C_GY30_ADDRESS    ()
#define I2C_EEP_ADDRESS     (0x50)

extern void I2C_FindAddress(void);

#endif