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

AVRLEDDisplay::AVRLEDDisplay(uint8_t bit) {
    this->bit = bit;
}

void AVRLEDDisplay::outputToDisplay(bool output) {
    if(bit < 6) {
        //PORTB ^= (-(output) ^ PORTB) & (1 << (bit));
        PORTD ^= (-(output) ^ PIND) & (1 << (bit + 2));
    } else if (bit >= 6 && bit < 12) {
        PORTB ^= (-(output) ^ PINB) & (1 << (bit - 6));
    } else if (bit >= 12 && bit < 19) {
        PORTC ^= (-(output) ^ PINC) & (1 << (bit - 12));
    }
}