#include "include/AbstractLEDModel.h"
#include "include/OnOffLEDModel.h"

OnOffLEDModel::OnOffLEDModel()
{
    display = nullptr;
};

bool OnOffLEDModel::getState()
{
    return this->state;
}

void OnOffLEDModel::setState(bool state)
{
    this->state = state;
}
void OnOffLEDModel::updateDisplay() {
    if(display) {
        this->display->outputToDisplay(this->state);
    }
}


void OnOffLEDModel::attachDisplay(AbstractDisplay* display)
{
    this->display = display;
}