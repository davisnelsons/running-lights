#include "include/AVRLEDDisplay.h"
#include "include/AbstractDisplay.h"
#include "include/AbstractLEDModel.h"
#include <avr/io.h>
/*
*   The LEDs will be assigned as follows
    Bits 0 - 5: D2 - D7 (PD2 - PD7)
    Bits 6 - 10: D8 - D12 (PB0 - PB4)
    Bits 11 - 16: A0 - A5 (PC0 - PC5)
*
*/

AVRLEDDisplay::AVRLEDDisplay(uint8_t bit) {
    if(bit < 6) {
        //Bits 0 - 5: D2 - D7 (PD2 - PD7)
        DDRD |= (1 << (bit + 2));
        this->port = &PORTD;
        this->bit = bit + 2;
    } else if(bit >= 6 && bit < 11) {
        //Bits 6 - 10: D8 - D12 (PB0 - PB4)
        DDRB |= (1 << (bit - 6));
        this->port = &PORTB;
        this->bit = bit - 6;
    } else if (bit >= 11 && bit < 17) {
        //Bits 11 - 16: A0 - A5 (PC0 - PC5)
        DDRC |= (1 << (bit - 11));
        this->port = &PORTC;
        this->bit = bit-11;
    } 

    //*(this->port) &= ~(1 << (this->bit));
}

void AVRLEDDisplay::outputToDisplay(bool output) {
    *(this->port) ^= (-(output) ^ *(this->port - 2)) & (1 << (this->bit)); // this->port - 2 --> PINX is always two bytes back from PORTX on AVR's
}