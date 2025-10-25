#ifndef __MIROS_H
#define __MIROS_H
#include <stdint.h>


typedef struct {
    uint32_t* sp;
    uint32_t timeout; // IF TIMEOUT != 0, THREAD IS BLOCKED, IT COUNTS DOWN AT EVERY CLOCK TICK
} OSThread;

typedef void(*OSThreadHandler)();   //THIS MEANS THAT OSThreadHandler IS FROM NOW ON A POINTER TO A FUNCTION THAT TAKES NO ARGUMENTS AND RETURNS NOTHING

void OSInit(void* stackMem, uint32_t stackSize);

void OSDelay(uint32_t ticks);

void OSTick();

void OSIdle();

void OSRun();

// OSSched MUST BE CALLED WHEN INTERRUPTS ARE DISABLED
void OSSched();

void OSThreadStart(OSThread* me, OSThreadHandler threadHandler, void* stackMem, uint32_t stackSize);

#endif