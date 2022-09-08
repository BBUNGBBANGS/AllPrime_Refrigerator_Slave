#ifndef _OLED_H
#define _OLED_H

#include "main.h"

#define OLED_MODULE             (hi2c2)
#define OLED_ADDRESS            (0x78)

/* OLED width in pixels */
#define OLED_WIDTH            128
/* OLED height in pixels */
#define OLED_HEIGHT           64

typedef enum 
{
    OLED_COLOR_BLACK = 0x00, /*!< Black color, no pixel */
    OLED_COLOR_WHITE = 0x01  /*!< Pixel is set. Color depends on LCD */
} OLED_COLOR_t;

typedef struct 
{
    uint16_t X_point;
    uint16_t Y_point;
} OLED_t;
typedef struct 
{
    uint8_t FontWidth;    /*!< Font width in pixels */
    uint8_t FontHeight;   /*!< Font height in pixels */
    const uint16_t *data; /*!< Pointer to data font data array */
} OLED_Font_t;

extern void OLED_Spi_Init(void);
extern void OLED_Reg_Init(void);
extern void OLED_Print(void);
#endif