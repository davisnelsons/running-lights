#include "include/AbstractLEDModel.h"
#include "include/LEDController.h"
#include "include/OnOffLEDModel.h"
#include <iostream>
#include <cassert>

int main() {
    std::cout << "Starting test.." << "\n";

    OnOffLEDModel led1;

    assert(!led1.getState()); 
    led1.setState(true);
    assert(led1.getState());
    

    std::cout << "all fine \n"; 
}