#include "include/OnOffLEDModel.h"
#include "include/LEDController.h"
#include "include/main.h"
#include "include/config.h"

#ifdef LINUX
  #include "include/TextDisplay.h"
  #include <unistd.h>
  //definition of global controller
  LEDController<OnOffLEDModel<TextDisplay>> controller;
#endif

const uint8_t speed = SPEED; //from  config.h

#ifdef AVR
  //avr-gcc needs these definitions for compilation of c++ files
  int __cxa_guard_acquire(__guard *g) {return !*(char *)(g);};
  void __cxa_guard_release (__guard *g) {*(char *)g = 1;};
  void __cxa_guard_abort (__guard *) {};
  void __cxa_pure_virtual(void) {};
  void * operator new(size_t size)
  {
    return malloc(size);
  }
  void operator delete(void * ptr)
  {
    free(ptr);
  }

  #include "include/AVRLEDDisplay.h"
  //definition of (global) controller
  LEDController<OnOffLEDModel<AVRLEDDisplay>> controller;

  ISR(PCINT0_vect)
  {
    if((PINB >> 5) & 1) controller.switchDirection();
  }

  volatile uint8_t timerTick = 0;


  ISR(TIMER0_OVF_vect) {
    timerTick++;
    if(timerTick == (256 - speed)){
      controller.move();
      timerTick = 0;
    } 
  }
#endif

void configPins() {
  #ifdef AVR
    DDRB &= ~(1 << 5); //set B5 (D13) to input
    PORTB &= ~(1 << 5); //set B5 to pull down
    SREG |= (1 << 7); // global interrupt enable
    PCICR |= 1; //enable pin change interrupt 0
    PCMSK0 |= (1 << 5); //select pin B5 to trigger interrupt
    //timer
    TCCR0A &= ~(0xFF); //set all bits to 0 for normal operation
    TCCR0B |= 3; // t/64 clock input
    TIMSK0 |= 1; // enable overflow interrupt
  #endif
}

template <typename Model, typename Display>
void initLEDs(LEDController<Model>& controller) {
  for(int i = 0; i < LEDCOUNT; i++) {
    Model * LEDModel = new Model(); 
    if(!LEDModel) continue;
    Display * LEDDisplay;
    LEDDisplay = new Display(i);
    if(!LEDDisplay) continue;
    LEDModel->attachDisplay(LEDDisplay);
    controller.addLED(LEDModel, i);
  }
}

int main() {

  #ifdef AVR
    configPins();
    controller = LEDController<OnOffLEDModel<AVRLEDDisplay>>();
    initLEDs<OnOffLEDModel<AVRLEDDisplay>, AVRLEDDisplay>(controller);
  #endif

  #ifdef LINUX
    controller = LEDController<OnOffLEDModel<TextDisplay>>();
    initLEDs<OnOffLEDModel<TextDisplay>, TextDisplay>(controller);
  #endif

    while(1) {
      #ifdef LINUX
        std::cout << "\n";
        controller.move();
        usleep(100000-speed*100);
      #endif
    }
}