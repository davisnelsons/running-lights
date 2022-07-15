#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H
#define LEDCOUNT 10
#include "AbstractLEDModel.h"

class LEDController 
{
public:
    LEDController();

    void move(); //move the running lights by one step
    void addLED(); // add a LED light at the end of the LED array
    void clearLEDs(); // set all LEDs to 0, clear the array
    void switchDirection(); // switch the direction of movement
private:
    AbstractLEDModel * LEDs[LEDCOUNT];
};

#endif