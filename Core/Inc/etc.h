#ifndef _ETC_H
#define _ETC_H

#include "main.h"

#define SWITCH_ONOFF_GROUP          (GPIOA)
#define SWITCH_DIP_GROUP            (GPIOB)

#define SWITCH_ONOFF_PIN            (GPIO_PIN_15)
#define SWITCH_DIP_PIN_0            (GPIO_PIN_0)
#define SWITCH_DIP_PIN_1            (GPIO_PIN_1)
#define SWITCH_DIP_PIN_2            (GPIO_PIN_2)

#define LED_GROUP                   (GPIOB)
#define LED_PIN                     (GPIO_PIN_8)
#define LED_OFF                     (GPIO_PIN_RESET)
#define LED_ON                      (GPIO_PIN_SET)

extern void Switch_Scan(void);
extern void LED_Output(void);

#endif