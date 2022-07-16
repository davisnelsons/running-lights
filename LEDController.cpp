#include "include/LEDController.h"
#include "include/OnOffLEDModel.h"
#include "include/AbstractDisplay.h"
#include "include/TextDisplay.h"

template <typename T>
LEDController<T>::LEDController()
{
    currentIndex = 0;
}

template <typename T>
void LEDController<T>::move() {
    (this->LEDs)[currentIndex]->setState(!((this->LEDs)[currentIndex]->getState()));
    currentIndex = (currentIndex == (LEDCOUNT-1)) ? 0 : currentIndex+1; 
    //refresh all
    for(int i = 0; i < LEDCOUNT; i++) {
        (this->LEDs)[i]->updateDisplay();
    }
}

template <typename T>
void LEDController<T>::addLED(T * LED, uint8_t index) {
    if(index < LEDCOUNT) {
        this->LEDs[index] = LED;
    }
}


template class LEDController<OnOffLEDModel>;