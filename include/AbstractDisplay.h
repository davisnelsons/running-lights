#ifndef ABSTRACTDISPLAY_H
#define ABSTRACTDISPLAY_H

class AbstractDisplay
{
    public:
        AbstractDisplay() {};
        virtual void update() = 0;
    protected:
        virtual void outputToDisplay() = 0;
};


#endif