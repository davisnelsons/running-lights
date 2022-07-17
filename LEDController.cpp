#include "include/LEDController.h"
#include "include/OnOffLEDModel.h"
#include "include/AVRLEDDisplay.h"
#include "include/TextDisplay.h"

template <typename T>
LEDController<T>::LEDController()
{
    this->currentIndex = 0;
    this->direction = true;

    #if(DIRECTION==1)
        this->direction = false;
        currentIndex = LEDCOUNT-1; //for consistency
    #endif
}

template <typename T>
void LEDController<T>::move() {
    //(this->LEDs)[currentIndex]->setState(!((this->LEDs)[this->currentIndex]->getState()));
    T * Model = (T *) (this->LEDs)[currentIndex];

    //some weird bool type conversion prevents shortening
    if(Model->getState()){
        Model->setState(false);
    } else {
        Model->setState(true);
    }

    if(this->direction) {
        this->currentIndex = (this->currentIndex == (LEDCOUNT-1)) ? 0 : this->currentIndex+1; 
    } else {
        this->currentIndex = (this->currentIndex == 0) ? LEDCOUNT-1 : this->currentIndex-1; 
    }
    //refresh all
    for(int i = 0; i < LEDCOUNT; i++) {
        Model->updateDisplay();
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
    (this->LEDs)[this->currentIndex]->setState(!((this->LEDs)[this->currentIndex]->getState())); // ensures no "leftovers" on direction switch (double switch->triple switch)
}

template class LEDController<OnOffLEDModel<AVRLEDDisplay>>;