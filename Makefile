IDIR =../include
CC=gcc
CCAVR = avr-c++
CCLIN = g++
override CFLAGS += -Wall -Werror

ODIR=build
LDIR =../lib

LIBS=

SRCDIR=src

MINFILES = $(SRCDIR)/LEDController.cpp $(SRCDIR)/main.cpp $(SRCDIR)/OnOffLEDModel.cpp 
LINFILES = $(SRCDIR)/TextDisplay.cpp
AVRFILES = $(SRCDIR)/AVRLEDDisplay.cpp
AVRBUILDF = $(CFLAGS) -Os -DF_CPU=16000000UL -DAVR -mmcu=atmega328p -c -o

build-avr:
	mkdir -p avrbuild
	$(CCAVR) $(AVRBUILDF) avrbuild/avr_main.o $(SRCDIR)/main.cpp
	$(CCAVR) $(AVRBUILDF) avrbuild/AVRLEDDisplay.o $(SRCDIR)/AVRLEDDisplay.cpp
	$(CCAVR) $(AVRBUILDF) avrbuild/OnOffLEDModel.o $(SRCDIR)/OnOffLEDModel.cpp
	$(CCAVR) $(AVRBUILDF) avrbuild/LEDController.o $(SRCDIR)/LEDController.cpp
	$(CCAVR) -mmcu=atmega328p $(CFLAGS) avrbuild/*.o -o avrbuild/out
	avr-objcopy -O ihex -R .eeprom avrbuild/out avrbuild/out.hex

build-linux:
	mkdir -p build
	$(CCLIN) $(CFLAGS) -DLINUX -c $(MINFILES) $(LINFILES)
	mv *.o build/
	$(CCLIN) $(CFLAGS) -DLINUX -o build/out build/*.o
	./build/out

flash-avr:
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:avrbuild/out.hex

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

