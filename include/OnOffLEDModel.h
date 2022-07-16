#include "AbstractLEDModel.h"
#include "AbstractDisplay.h"
#ifndef ONOFFLEDMODEL_H
#define ONOFFLEDMODEL_H
#include "avr_main.h"
class OnOffLEDModel : public AbstractLEDModel
{
    public:
        OnOffLEDModel();
        bool getState();
        void setState(bool state);
        void attachDisplay(AbstractDisplay* display);
        void updateDisplay();
    private:
        AbstractDisplay* display;
};

#endif