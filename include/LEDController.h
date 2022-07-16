#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H
#define LEDCOUNT 6
#include "AbstractLEDModel.h"
#include "avr_main.h"

template <typename T>
class LEDController 
{
public:
    LEDController();

    void move(); //move the running lights by one step
    void addLED(T * LED, uint8_t index); // add a LED light at the end of the LED array
    void clearLEDs(); // set all LEDs to 0, clear the array
    void switchDirection(); // switch the direction of movement
private:
    T * LEDs[LEDCOUNT];
    uint8_t currentIndex; //good for up to 256 LEDs
};

#endif