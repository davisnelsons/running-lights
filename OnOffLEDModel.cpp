#include "include/AbstractLEDModel.h"
#include "include/OnOffLEDModel.h"

OnOffLEDModel::OnOffLEDModel()
{
    ;;
};

bool OnOffLEDModel::getState()
{
    return this->state;
}

void OnOffLEDModel::setState(bool state)
{
    this->state = state;
}

void OnOffLEDModel::attachDisplay()
{
    ;;
}