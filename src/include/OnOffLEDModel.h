#ifndef ONOFFLEDMODEL_H
#define ONOFFLEDMODEL_H
#include "avr_main.h"

template <typename Display>
class OnOffLEDModel
{
    public:
        OnOffLEDModel();
        bool getState();
        void setState(bool state);
        void attachDisplay(Display * display);
        void updateDisplay();
    private:
        Display * display;
        bool state;
};

#endif