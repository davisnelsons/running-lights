#include "include/AbstractLEDModel.h"
#include "include/LEDController.h"
#include "include/OnOffLEDModel.h"
#include "include/TextDisplay.h"
#include <iostream>
#include <cassert>

int main() {
    std::cout << "Starting test.." << "\n";

    OnOffLEDModel* led1;
    led1 = new OnOffLEDModel();

    assert(!led1->getState()); 
    led1->setState(true);
    assert(led1->getState());
    
    TextDisplay* textDisplay;
    textDisplay = new TextDisplay(led1);
    led1->attachDisplay(textDisplay);

    led1->setState(true);
    led1->setState(true);
    led1->setState(false);

    std::cout << "\n \n";

    LEDController LEDcontroller = LEDController();

    for(int i = 0; i < 25; i++) {
        LEDcontroller.move();
    }   
    std::cout << "\n all fine \n"; 
}