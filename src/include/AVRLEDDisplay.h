#ifdef AVR

#ifndef AVRLEDDISPLAY_H
#define AVRLEDDISPLAY_H
#include <stdint.h>

class AVRLEDDisplay
{
    public:
        AVRLEDDisplay(const uint8_t bit);
        void outputToDisplay(const bool output);
    private:
        uint8_t bit;
        volatile uint8_t * port;
};
#endif

#endif