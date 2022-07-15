#include "include/LEDController.h"
#include "include/OnOffLEDModel.h"
#include "include/AbstractDisplay.h"
#include "include/TextDisplay.h"
#include <iostream>
LEDController::LEDController()
{
    for(int i = 0; i < LEDCOUNT; i++) {
        (this->LEDs)[i] = new OnOffLEDModel(); 
        TextDisplay* textDisplay;
        textDisplay = new TextDisplay((this->LEDs)[i]);
        (this->LEDs)[i]->attachDisplay(textDisplay);
    }
    currentIndex = 0;
}

void LEDController::move() {
    std::cout << "\n";
    (this->LEDs)[currentIndex]->setState(!((this->LEDs)[currentIndex]->getState()));
    currentIndex = (currentIndex == (LEDCOUNT-1)) ? 0 : currentIndex+1; 

    //refresh all
    for(int i = 0; i < LEDCOUNT; i++) {
        (this->LEDs)[i]->updateDisplay();
    }

    std::cout << "\n";
}