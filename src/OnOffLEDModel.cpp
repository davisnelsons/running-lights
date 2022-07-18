#include "include/OnOffLEDModel.h"
#include "include/AVRLEDDisplay.h"
#include "include/TextDisplay.h"

template <typename Display>
OnOffLEDModel<Display>::OnOffLEDModel()
{
    display = nullptr;
    this->state = false;
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
    if(this->display) this->display->outputToDisplay(this->state);
}

template <typename Display>
void OnOffLEDModel<Display>::attachDisplay(Display* display)
{ 
    this->display = display;
}
#ifdef AVR
template class OnOffLEDModel<AVRLEDDisplay>;
#endif
#ifdef LINUX
template class OnOffLEDModel<TextDisplay>;
#endif