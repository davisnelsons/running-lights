#include <avr/io.h>
#include "include/OnOffLEDModel.h"
#include "include/AVRLEDDisplay.h"
#include "include/LEDController.h"
#include <stdlib.h>
#include "include/avr_main.h"
#include <util/delay.h>

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


void configPins() {
    DDRD |= (0xFF << 2); //set to output ports D7-D2
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
    configPins();

    LEDController<OnOffLEDModel> controller = LEDController<OnOffLEDModel>();
    initLEDs<OnOffLEDModel, AVRLEDDisplay>(controller);


    while(1) {
        _delay_ms(60);
        controller.move();
    }


    // OnOffLEDModel* led1;
    // led1 = new OnOffLEDModel();

    // AVRLEDDisplay* avrLEDDisplay1;
    // avrLEDDisplay1 = new AVRLEDDisplay(led1, 2);

    // led1->attachDisplay(avrLEDDisplay1);

    // led1->updateDisplay();
    // led1->setState(true);
    // led1->updateDisplay();
    // led1->getState();

     // OnOffLEDModel* led2;
    // led2 = new OnOffLEDModel();
    // OnOffLEDModel* led3;
    // led3 = new OnOffLEDModel();
    // OnOffLEDModel* led4;
    // led4 = new OnOffLEDModel();
    // OnOffLEDModel* led5;
    // led5 = new OnOffLEDModel();
    // OnOffLEDModel* led6;
    // led6 = new OnOffLEDModel();


    // AVRLEDDisplay* avrLEDDisplay2;
    // avrLEDDisplay2 = new AVRLEDDisplay(led2, 3);
    // led2->attachDisplay(avrLEDDisplay2);
    // AVRLEDDisplay* avrLEDDisplay3;
    // avrLEDDisplay3 = new AVRLEDDisplay(led3, 4);
    // led3->attachDisplay(avrLEDDisplay3);
    // AVRLEDDisplay* avrLEDDisplay4;
    // avrLEDDisplay4 = new AVRLEDDisplay(led4, 5);
    // led4->attachDisplay(avrLEDDisplay4);
    // AVRLEDDisplay* avrLEDDisplay5;
    // avrLEDDisplay5 = new AVRLEDDisplay(led5, 6);
    // led5->attachDisplay(avrLEDDisplay5);
    // AVRLEDDisplay* avrLEDDisplay6;
    // avrLEDDisplay6 = new AVRLEDDisplay(led6, 7);
    // led6->attachDisplay(avrLEDDisplay6);

     //led1->setState(true);
     //led1->updateDisplay();
}