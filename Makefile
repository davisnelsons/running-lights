IDIR =../include
CC=gcc
CCAVR = avr-c++
CFLAGS=--pedantic

ODIR=build
LDIR =../lib

LIBS=

test:
	g++ -Wall -g -Werror -c *.cpp
	mv *.o build/
	g++ -Wall $(LIBS) -o build/test build/*.o 
	./build/test

build-avr:
	$(CCAVR) -Os -DF_CPU=16000000UL $(CFLAGS) -mmcu=atmega328p -c -o avrbuild/avr_main.o avr_main.cpp
	$(CCAVR) -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o avrbuild/abstractDisplay.o AbstractDisplay.cpp
	$(CCAVR) -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o avrbuild/abstractLEDModel.o AbstractLEDModel.cpp
	$(CCAVR) -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o avrbuild/AVRLEDDisplay.o AVRLEDDisplay.cpp
	$(CCAVR) -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o avrbuild/OnOffLEDModel.o OnOffLEDModel.cpp
	$(CCAVR) -Os -DF_CPU=16000000UL $(CFLAGS) -mmcu=atmega328p -c -o avrbuild/LEDController.o LEDController.cpp
	$(CCAVR) -mmcu=atmega328p avrbuild/*.o -o avrbuild/out
	avr-objcopy -O ihex -R .eeprom avrbuild/out avrbuild/out.hex
	

flash-avr:
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:avrbuild/out.hex

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

