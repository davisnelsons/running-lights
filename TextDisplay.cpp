#include "include/TextDisplay.h"
#include "include/AbstractDisplay.h"
#include "include/AbstractLEDModel.h"
#include <iostream>

TextDisplay::TextDisplay(AbstractLEDModel* LEDModel) {
    this->LEDModel = LEDModel;
    this->update();
}
void TextDisplay::update() {
    this->state = this->LEDModel->getState();
    this->outputToDisplay();
}

void TextDisplay::outputToDisplay() {
    std::cout << " " << this->state << " ";
}