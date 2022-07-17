#ifndef ABSTRACTDISPLAY_H
#define ABSTRACTDISPLAY_H

class AbstractDisplay
{
    public:
        AbstractDisplay() {};
        virtual void outputToDisplay(bool output) = 0;
    protected:
        
};


#endif