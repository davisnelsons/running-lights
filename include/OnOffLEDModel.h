#include "AbstractLEDModel.h"
#ifndef ONOFFLEDMODEL_H
#define ONOFFLEDMODEL_H

class OnOffLEDModel : public AbstractLEDModel
{
    public:
        OnOffLEDModel();
        bool getState();
        void setState(bool state);
        void attachDisplay();
};

#endif