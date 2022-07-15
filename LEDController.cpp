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
}

void LEDController::move() {
    std::cout << "\n";
    for(int i = 0; i < LEDCOUNT; i++) {
        (this->LEDs)[i]->setState(!((this->LEDs)[i]->getState()));
    }
    std::cout << "\n";
}