#include "include/TextDisplay.h"
#include <iostream>
#include <cstdint>

TextDisplay::TextDisplay(uint8_t index) {
    this->index = index;
}

void TextDisplay::outputToDisplay(bool output) {
    std::cout << " " << output << " ";
}