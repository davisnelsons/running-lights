#include "include/LEDController.h"
#include "include/OnOffLEDModel.h"
#include "include/AVRLEDDisplay.h"
#include "include/TextDisplay.h"

template <typename T>
LEDController<T>::LEDController()
{
    this->currentIndex = 0;
    this->direction = right;

    #if(DIRECTION==1)
        this->direction = left;
        currentIndex = LEDCOUNT-1; //for consistency
    #endif
}

template <typename T>
void LEDController<T>::move() {
    T * Model = (T *) (this->LEDs)[this->currentIndex];
    //some weird bool type conversion prevents shortening
    if(!Model) return;
    if(Model->getState()){
        Model->setState(false);
    } else {
        Model->setState(true);
    }
    if(this->direction == right) {
        this->currentIndex = (this->currentIndex == (LEDCOUNT-1)) ? 0 : this->currentIndex+1; 
    } else {
        this->currentIndex = (this->currentIndex == 0) ? LEDCOUNT-1 : this->currentIndex-1; 
    }
    #ifdef AVR
    Model->updateDisplay(); //update only the single changed LED
    #endif
    #ifdef LINUX
    this->updateLEDs(); //update all to have nice output to std::cout
    #endif
}    

template <typename T>
void LEDController<T>::addLED(T * LED, const uint8_t index) {
    if(LED) {
        if(index < LEDCOUNT) {
            this->LEDs[index] = LED;
        }
    }
}

template <typename T>
void LEDController<T>::switchDirection() {
    this->direction = (direction_t) !(this->direction);
    T * Model = (T *) (this->LEDs)[this->currentIndex];
    if(!Model) return;
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
        if(this->LEDs[i]) this->LEDs[i]->updateDisplay();
    }
}

#ifdef AVR
template class LEDController<OnOffLEDModel<AVRLEDDisplay>>;
#endif
#ifdef LINUX
template class LEDController<OnOffLEDModel<TextDisplay>>;
#endif