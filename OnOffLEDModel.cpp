#include "include/AbstractLEDModel.h"
#include "include/OnOffLEDModel.h"
#include "include/AVRLEDDisplay.h"

template <typename Display>
OnOffLEDModel<Display>::OnOffLEDModel()
{
    
    display = nullptr;
};

template <typename Display>
bool OnOffLEDModel<Display>::getState()
{
    return this->state;
}

template <typename Display>
void OnOffLEDModel<Display>::setState(bool state)
{
    this->state = state;
}

template <typename Display>
void OnOffLEDModel<Display>::updateDisplay() {
    this->display->outputToDisplay(this->state);
}

template <typename Display>
void OnOffLEDModel<Display>::attachDisplay(Display* display)
{ 
    this->display = display;
}

template class OnOffLEDModel<AVRLEDDisplay>;