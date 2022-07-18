IDIR =../include
CC=gcc
CCAVR = avr-c++
CCLIN = g++
override CFLAGS +=-pedantic -Wall -Werror

ODIR=build
LDIR =../lib

LIBS=

MINFILES = LEDController.cpp AbstractDisplay.cpp AbstractLEDModel.cpp avr_main.cpp OnOffLEDModel.cpp 
LINFILES = TextDisplay.cpp
AVRFILES = AVRLEDDisplay.cpp

test:
	g++ -Wall -g -Werror -c *.cpp
	mv *.o build/
	g++ -Wall $(LIBS) -o build/test build/*.o 
	./build/test

build-avr:
	$(CFLAGS) += -DAVR
	$(CCAVR) -Os -DF_CPU=16000000UL $(CFLAGS) -mmcu=atmega328p -c -o avrbuild/avr_main.o avr_main.cpp
	$(CCAVR) -Os -DF_CPU=16000000UL $(CFLAGS) -mmcu=atmega328p -c -o avrbuild/AVRLEDDisplay.o AVRLEDDisplay.cpp
	$(CCAVR) -Os -DF_CPU=16000000UL $(CFLAGS) -mmcu=atmega328p -c -o avrbuild/OnOffLEDModel.o OnOffLEDModel.cpp
	$(CCAVR) -Os -DF_CPU=16000000UL $(CFLAGS) -mmcu=atmega328p -c -o avrbuild/LEDController.o LEDController.cpp
	$(CCAVR) -mmcu=atmega328p $(CFLAGS) avrbuild/*.o -o avrbuild/out
	avr-objcopy -O ihex -R .eeprom avrbuild/out avrbuild/out.hex

build-linux:
	
	$(CCLIN) $(CFLAGS) -DLINUX -c $(MINFILES) $(LINFILES)
	mv *.o build/
	$(CCLIN) $(CFLAGS) -DLINUX -o build/out build/*.o
	./build/out

flash-avr:
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:avrbuild/out.hex

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

