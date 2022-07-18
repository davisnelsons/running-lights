#ifdef LINUX

#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <cstdint>

class TextDisplay
{
    public:
        TextDisplay(uint8_t index);
        void outputToDisplay(bool output);
    private:
        uint8_t index;

};


#endif

#endif