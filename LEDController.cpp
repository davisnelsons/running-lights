#include "include/LEDController.h"
#include "include/OnOffLEDModel.h"
#include "include/AbstractDisplay.h"
#include "include/TextDisplay.h"

template <typename T>
LEDController<T>::LEDController()
{
    currentIndex = 0;
    direction = true;

    #if(DIRECTION==1)
        direction = false;
        currentIndex = LEDCOUNT-1; //for consistency
    #endif
}

template <typename T>
void LEDController<T>::move() {
    
    (this->LEDs)[currentIndex]->setState(!((this->LEDs)[currentIndex]->getState()));
    if(direction) {
        currentIndex = (currentIndex == (LEDCOUNT-1)) ? 0 : currentIndex+1; 
    } else {
        currentIndex = (currentIndex == 0) ? LEDCOUNT-1 : currentIndex-1; 
    }
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

template <typename T>
void LEDController<T>::switchDirection() {
    this->direction = !(this->direction);
    (this->LEDs)[currentIndex]->setState(!((this->LEDs)[currentIndex]->getState())); // ensures no "leftovers" on direction switch (double switch->triple switch)
}

template class LEDController<OnOffLEDModel>;