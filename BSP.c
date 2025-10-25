/* Board Support Package */
#include <stm32f401xe.h>
#include "BSP.h"
#include "miros.h"

void assert_failed(){
    NVIC_SystemReset();
}

void BSP_init(){
  	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
	SysTick->VAL = 0;
	SysTick->LOAD = (SYS_CLOCK_FREQ/BSP_TICKS_PER_SEC) - 1;
	
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	GPIOA->MODER |= GPIO_MODER_MODER5_0;
}

void SysTick_Handler(){
    OSTick();

	__disable_irq();
	OSSched();
	__enable_irq();
}


