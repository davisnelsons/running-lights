#include "include/AVRLEDController.h"
#include "include/OnOffLEDModel.h"
#include "include/AbstractDisplay.h"
#include "include/AVRLEDDisplay.h"

AVRLEDController::AVRLEDController()
{
    for(int i = 0; i < LEDCOUNT; i++) {
        (this->LEDs)[i] = new OnOffLEDModel(); 
        AVRLEDDisplay* ledDisplay;
        ledDisplay = new AVRLEDDisplay((this->LEDs)[i], 2+i);
        (this->LEDs)[i]->attachDisplay(ledDisplay);
    }
    currentIndex = 0;
}

void AVRLEDController::move() {
    
    (this->LEDs)[currentIndex]->setState(!((this->LEDs)[currentIndex]->getState()));
    currentIndex = (currentIndex == (LEDCOUNT-1)) ? 0 : currentIndex+1; 

    //refresh all
    for(int i = 0; i < LEDCOUNT; i++) {
        (this->LEDs)[i]->updateDisplay();
    }

}