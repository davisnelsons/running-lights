#include "include/OnOffLEDModel.h"
#include "include/AVRLEDDisplay.h"
#include "include/LEDController.h"
#include "include/avr_main.h"


LEDController<OnOffLEDModel> controller;

#ifdef AVR
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

  ISR(PCINT0_vect)
  {
    if((PINB >> 5) & 1) controller.switchDirection();
  }


#endif




void configPins() {
  #ifdef AVR
    DDRD |= (0xFF << 2); //set to output ports D7-D2
    DDRB &= ~(1 << 5); //set B5 (D13) to input
    PORTB &= ~(1 << 5); //set B5 to pull down
    SREG |= (1 << 7); // global interrupt enable
    PCICR |= 1; //enable pin change interrupt 0
    PCMSK0 |= (1 << 5); //select pin B5 to trigger interrupt
  #endif
}


template <typename T, typename U>
void initLEDs(LEDController<T>& controller) {
  for(int i = 0; i < LEDCOUNT; i++) {
    T * LEDModel = new T(); 
    U * LEDDisplay;
    LEDDisplay = new U(LEDModel, i);
    LEDModel->attachDisplay(LEDDisplay);
    controller.addLED(LEDModel, i);
  }
}


int main() {

  #ifdef AVR
    configPins();
    controller = LEDController<OnOffLEDModel>();
    initLEDs<OnOffLEDModel, AVRLEDDisplay>(controller);
  #endif

  #ifdef LINUX
    controller = LEDController<OnOffLEDModel>();
    initLEDs<OnOffLEDModel, TextDisplay>(controller);
  #endif
  
    while(1) {
      #ifdef AVR
        _delay_ms(50);
      #endif
      #ifdef LINUX
        std::cout << "\n";
      #endif
        controller.move();
    }
}