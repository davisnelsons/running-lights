#include "include/AVRLEDDisplay.h"
#include "include/AbstractDisplay.h"
#include "include/AbstractLEDModel.h"
#include <avr/io.h>

AVRLEDDisplay::AVRLEDDisplay(AbstractLEDModel* LEDModel, uint8_t bit) {
    this->LEDModel = LEDModel;
    this->bit = bit;
    this->update();
}
void AVRLEDDisplay::update() {
    this->state = this->LEDModel->getState();
    this->outputToDisplay();
}

void AVRLEDDisplay::outputToDisplay() {
    PORTD ^= (-(this->state) ^ PORTD) & (1 << (bit));
}