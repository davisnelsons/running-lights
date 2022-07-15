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
    if(display) {
        this->display->update();
    }
}

void OnOffLEDModel::attachDisplay(AbstractDisplay* display)
{
    this->display = display;
}