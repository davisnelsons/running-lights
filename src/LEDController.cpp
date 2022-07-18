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
    T * Model = (T *) (this->LEDs)[this->currentIndex];

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
    #ifdef AVR
    Model->updateDisplay();
    #endif
    #ifdef LINUX
    this->updateLEDs();
    #endif
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
    T * Model = (T *) (this->LEDs)[this->currentIndex];
    if(Model->getState()){
        Model->setState(false);
    } else {
        Model->setState(true);
    }
}

template <typename T>
void LEDController<T>::updateLEDs()
{
    //refresh all
    for(int i = 0; i < LEDCOUNT; i++) {
        this->LEDs[i]->updateDisplay();
    }
}

#ifdef AVR
template class LEDController<OnOffLEDModel<AVRLEDDisplay>>;
#endif
#ifdef LINUX
template class LEDController<OnOffLEDModel<TextDisplay>>;
#endif