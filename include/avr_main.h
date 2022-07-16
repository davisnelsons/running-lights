#ifndef AVR_MAIN_H
#define AVR_MAIN_H

#ifdef LINUX
    #include "TextDisplay.h"
    #include <iostream>
#endif

#ifdef AVR
#include <stddef.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" int __cxa_guard_acquire(__guard *);
extern "C" void __cxa_guard_release (__guard *);
extern "C" void __cxa_guard_abort (__guard *);
extern "C" void __cxa_pure_virtual(void);

void * operator new(size_t size);
void operator delete(void * ptr);
#endif

#endif

