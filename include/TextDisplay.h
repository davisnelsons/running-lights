#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "AbstractDisplay.h"
#include "AbstractLEDModel.h"
#include "avr_main.h"
class TextDisplay : public AbstractDisplay
{
    public:
        TextDisplay(AbstractLEDModel* LEDModel);
        void update();
    protected:
        void outputToDisplay();
    private:
        AbstractLEDModel* LEDModel;
        bool state;
};


#endif