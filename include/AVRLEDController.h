#ifndef AVRLEDCONTROLLER_H
#define AVRLEDCONTROLLER_H
#define LEDCOUNT 6
#include "AbstractLEDModel.h"
#include "avr_main.h"
class AVRLEDController 
{
public:
    AVRLEDController();

    void move(); //move the running lights by one step
    void addLED(); // add a LED light at the end of the LED array
    void clearLEDs(); // set all LEDs to 0, clear the array
    void switchDirection(); // switch the direction of movement
private:
    AbstractLEDModel * LEDs[LEDCOUNT];
    uint8_t currentIndex; //good for up to 256 LEDs
};

#endif