#include "include/AVRLEDDisplay.h"
#include "include/AbstractDisplay.h"
#include "include/AbstractLEDModel.h"
#include <avr/io.h>
/*
*   The LEDs will be assigned as follows
    Bits 0 - 5: D2 - D7 (PD2 - PD7)
    Bits 6 - 11: D8 - D12 (PB0 - PB4)
    Bits 12 - 18: A0 - A7 (PC0 - PC7)
*
*/



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
    if(bit < 6) {
        //PORTB ^= (-(this->state) ^ PORTB) & (1 << (bit));
        PORTD ^= (-(this->state) ^ PIND) & (1 << (bit + 2));
    } else if (bit >= 6 && bit < 12) {
        PORTB ^= (-(this->state) ^ PINB) & (1 << (bit - 6));
    } else if (bit >= 12 && bit < 19) {
        PORTC ^= (-(this->state) ^ PINC) & (1 << (bit - 12));
    }
}