#include <stdint.h>
#include <stm32f4xx_it.h>
/* extern uint32_t Stack_Mem;
extern uint32_t Stack_Size; */
//#define STACK_TOP ((uint32_t)&Stack_Mem + Stack_Size)

void assert_failed();
extern uint32_t __StackTop; //__asm("__initial_sp");
void Reset_Handler(void);

/* STM32F401RE device-specific interrupt handlers */
void WWDG_IRQHandler(void);                   /*  0 */
void PVD_IRQHandler(void);                    /*  1 */
void TAMP_STAMP_IRQHandler(void);             /*  2 */
void RTC_WKUP_IRQHandler(void);               /*  3 */
void FLASH_IRQHandler(void);                  /*  4 */
void RCC_IRQHandler(void);                    /*  5 */
void EXTI0_IRQHandler(void);                  /*  6 */
void EXTI1_IRQHandler(void);                  /*  7 */
void EXTI2_IRQHandler(void);                  /*  8 */
void EXTI3_IRQHandler(void);                  /*  9 */
void EXTI4_IRQHandler(void);                  /* 10 */
void DMA1_Stream0_IRQHandler(void);           /* 11 */
void DMA1_Stream1_IRQHandler(void);           /* 12 */
void DMA1_Stream2_IRQHandler(void);           /* 13 */
void DMA1_Stream3_IRQHandler(void);           /* 14 */
void DMA1_Stream4_IRQHandler(void);           /* 15 */
void DMA1_Stream5_IRQHandler(void);           /* 16 */
void DMA1_Stream6_IRQHandler(void);           /* 17 */
void ADC_IRQHandler(void);                    /* 18 */
void EXTI9_5_IRQHandler(void);                /* 23 */
void TIM1_BRK_TIM9_IRQHandler(void);          /* 24 */
void TIM1_UP_TIM10_IRQHandler(void);          /* 25 */
void TIM1_TRG_COM_TIM11_IRQHandler(void);     /* 26 */
void TIM1_CC_IRQHandler(void);                /* 27 */
void TIM2_IRQHandler(void);                   /* 28 */
void TIM3_IRQHandler(void);                   /* 29 */
void TIM4_IRQHandler(void);                   /* 30 */
void I2C1_EV_IRQHandler(void);                /* 31 */
void I2C1_ER_IRQHandler(void);                /* 32 */
void I2C2_EV_IRQHandler(void);                /* 33 */
void I2C2_ER_IRQHandler(void);                /* 34 */
void SPI1_IRQHandler(void);                   /* 35 */
void SPI2_IRQHandler(void);                   /* 36 */
void USART1_IRQHandler(void);                 /* 37 */
void USART2_IRQHandler(void);                 /* 38 */
void EXTI15_10_IRQHandler(void);              /* 40 */
void RTC_Alarm_IRQHandler(void);              /* 41 */
void OTG_FS_WKUP_IRQHandler(void);            /* 42 */
void DMA1_Stream7_IRQHandler(void);           /* 47 */
void SDIO_IRQHandler(void);                   /* 49 */
void TIM5_IRQHandler(void);                   /* 50 */
void SPI3_IRQHandler(void);                   /* 51 */
void DMA2_Stream0_IRQHandler(void);           /* 56 */
void DMA2_Stream1_IRQHandler(void);           /* 57 */
void DMA2_Stream2_IRQHandler(void);           /* 58 */
void DMA2_Stream3_IRQHandler(void);           /* 59 */
void DMA2_Stream4_IRQHandler(void);           /* 60 */
void OTG_FS_IRQHandler(void);                 /* 67 */
void DMA2_Stream5_IRQHandler(void);           /* 68 */
void DMA2_Stream6_IRQHandler(void);           /* 69 */
void DMA2_Stream7_IRQHandler(void);           /* 70 */
void USART6_IRQHandler(void);                 /* 71 */
void I2C3_EV_IRQHandler(void);                /* 72 */
void I2C3_ER_IRQHandler(void);                /* 73 */
void FPU_IRQHandler(void);                    /* 81 */
void SPI4_IRQHandler(void);                   /* 84 */


const uint32_t __myVectors[] __attribute__((section(".my_vector_table"))) = {
    (uint32_t)&__StackTop,  // The error seen here in vscode is just because pointers on this device are 64bits, so casting them into 32bits is bad. But this code will run on STM32 so it's all good
    (uint32_t)&Reset_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&HardFault_Handler,
    (uint32_t)&MemManage_Handler,
    (uint32_t)&BusFault_Handler,
    (uint32_t)&UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uint32_t)&SVC_Handler,
    (uint32_t)&DebugMon_Handler,
    0,
    (uint32_t)&PendSV_Handler,
    (uint32_t)&SysTick_Handler,

    // --- STM32F401RE Device Specific Interrupts ---
    (uint32_t)&WWDG_IRQHandler,             // 0
    (uint32_t)&PVD_IRQHandler,              // 1
    (uint32_t)&TAMP_STAMP_IRQHandler,       // 2
    (uint32_t)&RTC_WKUP_IRQHandler,         // 3
    (uint32_t)&FLASH_IRQHandler,            // 4
    (uint32_t)&RCC_IRQHandler,              // 5
    (uint32_t)&EXTI0_IRQHandler,            // 6
    (uint32_t)&EXTI1_IRQHandler,            // 7
    (uint32_t)&EXTI2_IRQHandler,            // 8
    (uint32_t)&EXTI3_IRQHandler,            // 9
    (uint32_t)&EXTI4_IRQHandler,            // 10
    (uint32_t)&DMA1_Stream0_IRQHandler,     // 11
    (uint32_t)&DMA1_Stream1_IRQHandler,     // 12
    (uint32_t)&DMA1_Stream2_IRQHandler,     // 13
    (uint32_t)&DMA1_Stream3_IRQHandler,     // 14
    (uint32_t)&DMA1_Stream4_IRQHandler,     // 15
    (uint32_t)&DMA1_Stream5_IRQHandler,     // 16
    (uint32_t)&DMA1_Stream6_IRQHandler,     // 17
    (uint32_t)&ADC_IRQHandler,              // 18
    0, 0, 0, 0,                           // 19–22 reserved
    (uint32_t)&EXTI9_5_IRQHandler,          // 23
    (uint32_t)&TIM1_BRK_TIM9_IRQHandler,    // 24
    (uint32_t)&TIM1_UP_TIM10_IRQHandler,    // 25
    (uint32_t)&TIM1_TRG_COM_TIM11_IRQHandler, // 26
    (uint32_t)&TIM1_CC_IRQHandler,          // 27
    (uint32_t)&TIM2_IRQHandler,             // 28
    (uint32_t)&TIM3_IRQHandler,             // 29
    (uint32_t)&TIM4_IRQHandler,             // 30
    (uint32_t)&I2C1_EV_IRQHandler,          // 31
    (uint32_t)&I2C1_ER_IRQHandler,          // 32
    (uint32_t)&I2C2_EV_IRQHandler,          // 33
    (uint32_t)&I2C2_ER_IRQHandler,          // 34
    (uint32_t)&SPI1_IRQHandler,             // 35
    (uint32_t)&SPI2_IRQHandler,             // 36
    (uint32_t)&USART1_IRQHandler,           // 37
    (uint32_t)&USART2_IRQHandler,           // 38
    0,                                    // 39 reserved
    (uint32_t)&EXTI15_10_IRQHandler,        // 40
    (uint32_t)&RTC_Alarm_IRQHandler,        // 41
    (uint32_t)&OTG_FS_WKUP_IRQHandler,      // 42
    0, 0, 0, 0,                           // 43–46 reserved
    (uint32_t)&DMA1_Stream7_IRQHandler,     // 47
    0,                                    // 48 reserved
    (uint32_t)&SDIO_IRQHandler,             // 49
    (uint32_t)&TIM5_IRQHandler,             // 50
    (uint32_t)&SPI3_IRQHandler,             // 51
    0, 0, 0, 0,                           // 52–55 reserved
    (uint32_t)&DMA2_Stream0_IRQHandler,     // 56
    (uint32_t)&DMA2_Stream1_IRQHandler,     // 57
    (uint32_t)&DMA2_Stream2_IRQHandler,     // 58
    (uint32_t)&DMA2_Stream3_IRQHandler,     // 59
    (uint32_t)&DMA2_Stream4_IRQHandler,     // 60
    0, 0, 0, 0, 0, 0,                     // 61–66 reserved
    (uint32_t)&OTG_FS_IRQHandler,           // 67
    (uint32_t)&DMA2_Stream5_IRQHandler,     // 68
    (uint32_t)&DMA2_Stream6_IRQHandler,     // 69
    (uint32_t)&DMA2_Stream7_IRQHandler,     // 70
    (uint32_t)&USART6_IRQHandler,           // 71
    (uint32_t)&I2C3_EV_IRQHandler,          // 72
    (uint32_t)&I2C3_ER_IRQHandler,          // 73
    0, 0, 0, 0, 0, 0, 0,                  // 74–80 reserved
    (uint32_t)&FPU_IRQHandler,              // 81
    0, 0,                                 // 82–83 reserved
    (uint32_t)&SPI4_IRQHandler,             // 84
};

__attribute__((naked)) void HardFault_Handler(void){
   __asm volatile (
        "CPSID i\n"             // disable interrupts
        "LDR   R0, =__StackTop\n"  // load address of stack top
        "MOV   SP, R0\n"           // set SP = __StackTop
        "BL    assert_failed\n"    // call C function
    );
};

void MemManage_Handler(void){
    assert_failed();
}

void BusFault_Handler(void){
    assert_failed();
}