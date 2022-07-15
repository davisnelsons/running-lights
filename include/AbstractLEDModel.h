#ifndef ABSTRACTLEDMODEL_H
#define ABSTRACTLEDMODEL_H

#include "AbstractDisplay.h"
#include <cstdint>
class AbstractLEDModel
{
    protected:
        bool state;
    public:
        AbstractLEDModel();
        virtual void setState(bool state) = 0;
        virtual bool getState() = 0;
        virtual void attachDisplay(AbstractDisplay* display) = 0;
};

#endif