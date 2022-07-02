#include "stdint.h"
#include "main.h"
#include "os.h"

extern uint32 _sidata;
extern uint32 _sdata;
extern uint32 _edata;
extern uint32 _sbss;
extern uint32 _ebss;
extern uint32 _estack;

extern void __libc_init_array();

void Reset_Handler()
{
    uint32 *dataInit = &_sidata;
    uint32 *data = &_sdata;
    while(data < &_edata)
    {
        *data++ = *dataInit++;
    }

    uint32 *bss = &_sbss;
    while(bss < &_ebss)
    {
        *bss++ = 0;
    }

    SystemInit(); 
    __libc_init_array();
    main();

    while (1);
}

void Default_Handler(void)
{
    while (1);
}
          
void TIM2_Handler(void)    
{
    HAL_TIM_IRQHandler(&htim2);
}

void TIM3_Handler(void)
{
    HAL_TIM_IRQHandler(&htim3);
}

void SystemTick_Handler(void)
{
    /* USER CODE BEGIN SysTick_IRQn 0 */

    /* USER CODE END SysTick_IRQn 0 */
    HAL_IncTick();
    /* USER CODE BEGIN SysTick_IRQn 1 */
    Os_Handler_1ms();
    /* USER CODE END SysTick_IRQn 1 */
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM2)
    {
        Os_Handler_10ms();
    }
    if(htim->Instance == TIM3)
    {
        Os_Time_Handler();
    }
}

__weak void NMI_Handler(void)                           {Default_Handler();}
__weak void HardFault_Handler(void)                     {Reset_Handler();}
__weak void SVC_Handler(void)                           {Default_Handler();}
__weak void PendSV_Handler(void)                        {Default_Handler();}
__weak void SysTick_Handler(void)                       {SystemTick_Handler();}
__weak void WWDG_IRQHandler(void)                       {Default_Handler();}                
__weak void PVD_VDDIO2_IRQHandler(void)                 {Default_Handler();}
__weak void RTC_IRQHandler(void)                        {Default_Handler();}
__weak void FLASH_IRQHandler(void)                      {Default_Handler();}
__weak void RCC_CRS_IRQHandler(void)                    {Default_Handler();}
__weak void EXTI0_1_IRQHandler(void)                    {Default_Handler();}
__weak void EXTI2_3_IRQHandler(void)                    {Default_Handler();}
__weak void EXTI4_15_IRQHandler(void)                   {Default_Handler();}
__weak void TSC_IRQHandler(void)                        {Default_Handler();}
__weak void DMA1_Channel1_IRQHandler(void)              {Default_Handler();}
__weak void DMA1_Channel2_3_IRQHandler(void)            {Default_Handler();}
__weak void DMA1_Channel4_5_6_7_IRQHandler(void)        {Default_Handler();}
__weak void ADC1_COMP_IRQHandler(void)                  {Default_Handler();}
__weak void TIM1_BRK_UP_TRG_COM_IRQHandler(void)        {Default_Handler();}
__weak void TIM1_CC_IRQHandler(void)                    {Default_Handler();}
__weak void TIM2_IRQHandler(void)                       {TIM2_Handler();}
__weak void TIM3_IRQHandler(void)                       {TIM3_Handler();}
__weak void TIM6_DAC_IRQHandler(void)                   {Default_Handler();}
__weak void TIM7_IRQHandler(void)                       {Default_Handler();}
__weak void TIM14_IRQHandler(void)                      {Default_Handler();}
__weak void TIM15_IRQHandler(void)                      {Default_Handler();}
__weak void TIM16_IRQHandler(void)                      {Default_Handler();}
__weak void TIM17_IRQHandler(void)                      {Default_Handler();}
__weak void I2C1_IRQHandler(void)                       {Default_Handler();}
__weak void I2C2_IRQHandler(void)                       {Default_Handler();}
__weak void SPI1_IRQHandler(void)                       {Default_Handler();}
__weak void SPI2_IRQHandler(void)                       {Default_Handler();}
__weak void USART1_IRQHandler(void)                     {Default_Handler();}
__weak void USART2_IRQHandler(void)                     {Default_Handler();}
__weak void USART3_4_IRQHandler(void)                   {Default_Handler();}
__weak void CEC_CAN_IRQHandler(void)                    {Default_Handler();}
__weak void USB_IRQHandler(void)                        {Default_Handler();}

__attribute__((section(".isr_vector")))

const void (*VectorTable[])(void) = 
{
    (const void (*)(void))&_estack,
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SVC_Handler,
    0,
    0,
    PendSV_Handler,
    SysTick_Handler,
    WWDG_IRQHandler,                   /* Window WatchDog              */
    PVD_VDDIO2_IRQHandler,             /* PVD and VDDIO2 through EXTI Line detect */
    RTC_IRQHandler,                    /* RTC through the EXTI line    */
    FLASH_IRQHandler,                  /* FLASH                        */
    RCC_CRS_IRQHandler,                /* RCC and CRS                  */
    EXTI0_1_IRQHandler,                /* EXTI Line 0 and 1            */
    EXTI2_3_IRQHandler,                /* EXTI Line 2 and 3            */
    EXTI4_15_IRQHandler,               /* EXTI Line 4 to 15            */
    TSC_IRQHandler,                    /* TSC                          */
    DMA1_Channel1_IRQHandler,          /* DMA1 Channel 1               */
    DMA1_Channel2_3_IRQHandler,        /* DMA1 Channel 2 and Channel 3 */
    DMA1_Channel4_5_6_7_IRQHandler,    /* DMA1 Channel 4, Channel 5, Channel 6 and Channel 7*/
    ADC1_COMP_IRQHandler,              /* ADC1, COMP1 and COMP2         */
    TIM1_BRK_UP_TRG_COM_IRQHandler,    /* TIM1 Break, Update, Trigger and Commutation */
    TIM1_CC_IRQHandler,                /* TIM1 Capture Compare         */
    TIM2_IRQHandler,                   /* TIM2                         */
    TIM3_IRQHandler,                   /* TIM3                         */
    TIM6_DAC_IRQHandler,               /* TIM6 and DAC                 */
    TIM7_IRQHandler,                   /* TIM7                         */
    TIM14_IRQHandler,                  /* TIM14                        */
    TIM15_IRQHandler,                  /* TIM15                        */
    TIM16_IRQHandler,                  /* TIM16                        */
    TIM17_IRQHandler,                  /* TIM17                        */
    I2C1_IRQHandler,                   /* I2C1                         */
    I2C2_IRQHandler,                   /* I2C2                         */
    SPI1_IRQHandler,                   /* SPI1                         */
    SPI2_IRQHandler,                   /* SPI2                         */
    USART1_IRQHandler,                 /* USART1                       */
    USART2_IRQHandler,                 /* USART2                       */
    USART3_4_IRQHandler,               /* USART3 and USART4            */
    CEC_CAN_IRQHandler,                /* CEC and CAN                  */
    USB_IRQHandler                    /* USB                          */
};
