#ifndef _CD4514_H
#define _CD4514_H

#include "main.h"

#define CD4514_CH0_GROUP            (GPIOB)
#define CD4514_CH1_GROUP            (GPIOB)
#define CD4514_CH2_GROUP            (GPIOB)
#define CD4514_CH3_GROUP            (GPIOA)
#define CD4514_INH_GROUP            (GPIOA)
#define CD4514_STB_GROUP            (GPIOA)

#define CD4514_CH0_PIN              (GPIO_PIN_13)
#define CD4514_CH1_PIN              (GPIO_PIN_14)
#define CD4514_CH2_PIN              (GPIO_PIN_15)
#define CD4514_CH3_PIN              (GPIO_PIN_2)
#define CD4514_INH_PIN              (GPIO_PIN_3)
#define CD4514_STB_PIN              (GPIO_PIN_5)

#define CD4514_OUTPUT_CH0           (0)
#define CD4514_OUTPUT_CH1           (1)
#define CD4514_OUTPUT_CH2           (2)
#define CD4514_OUTPUT_CH3           (3)
#define CD4514_OUTPUT_CH4           (4)
#define CD4514_OUTPUT_CH5           (5)
#define CD4514_OUTPUT_CH6           (6)
#define CD4514_OUTPUT_CH7           (7)
#define CD4514_OUTPUT_CH8           (8)
#define CD4514_OUTPUT_CH9           (9)
#define CD4514_OUTPUT_CH10          (10)
#define CD4514_OUTPUT_CH11          (11)
#define CD4514_OUTPUT_CH12          (12)
#define CD4514_OUTPUT_CH13          (13)
#define CD4514_OUTPUT_CH14          (14)
#define CD4514_OUTPUT_CH15          (15)

#define CD4514_OUTPUT_ON            (GPIO_PIN_SET)
#define CD4514_OUTPUT_OFF           (GPIO_PIN_RESET)

extern void CD4514_Output(void);

#endif