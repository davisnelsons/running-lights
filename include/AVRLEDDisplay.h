#ifndef AVRLEDDISPLAY_H
#define AVRLEDDISPLAY_H
#include "AbstractDisplay.h"
#include "AbstractLEDModel.h"
#include "avr_main.h"
class AVRLEDDisplay : public AbstractDisplay
{
    public:
        AVRLEDDisplay(AbstractLEDModel* LEDModel, uint8_t bit);
        void update();
    protected:
        void outputToDisplay();
    private:
        AbstractLEDModel* LEDModel;
        uint8_t bit;
        bool state;
};


#endif