#ifndef AVRLEDDISPLAY_H
#define AVRLEDDISPLAY_H
#include "AbstractDisplay.h"
#include "AbstractLEDModel.h"
#include "avr_main.h"
class AVRLEDDisplay
{
    public:
        AVRLEDDisplay(uint8_t bit);
        void outputToDisplay(bool output);
    private:
        uint8_t bit;
};
#endif