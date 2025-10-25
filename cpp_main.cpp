#include <stdint.h>
#include <stm32f401xe.h>

extern "C" {
#include "miros.h"
#include "BSP.h"

using namespace std;

uint32_t stackIdleThread[60];

uint32_t stackBlink[60];
OSThread blink1;
void main_blink();


uint32_t stackBlink2[60];
OSThread blink2;
void main_blink2();

volatile uint32_t g_task0_loops = 0;
volatile uint32_t g_task1_loops = 0;

	
int cpp_main(void){
//uint32_t volatile run = 0;

	BSP_init();
	OSInit(stackIdleThread, sizeof(stackIdleThread));

	OSThreadStart(&blink1, &main_blink, stackBlink, sizeof(stackBlink));
	/* MAIN FUNCTION 2 STACK */
	OSThreadStart(&blink2, &main_blink2, stackBlink2, sizeof(stackBlink2));

	OSRun();
	
	return 0;
 }

void main_blink(){
	while(1){
		++g_task0_loops;
		GPIOA->BSRR = GPIO_BSRR_BS5_Msk;
		OSDelay(BSP_TICKS_PER_SEC/4);
		GPIOA->BSRR = GPIO_BSRR_BR5_Msk;
		OSDelay(BSP_TICKS_PER_SEC * 3/4);
	}
}

void main_blink2(){
	while(1){
		++g_task1_loops;
		GPIOA->BSRR = GPIO_BSRR_BS5_Msk;
		OSDelay(BSP_TICKS_PER_SEC * 3/4);
		GPIOA->BSRR = GPIO_BSRR_BR5_Msk;
		OSDelay(BSP_TICKS_PER_SEC/4);
		
	}
}
}