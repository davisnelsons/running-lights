#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "AbstractDisplay.h"
#include "AbstractLEDModel.h"

class TextDisplay : public AbstractDisplay
{
    public:
        TextDisplay(AbstractLEDModel* LEDModel, int index);
        void update();
    protected:
        void outputToDisplay();
    private:
        AbstractLEDModel* LEDModel;
        bool state;
};


#endif