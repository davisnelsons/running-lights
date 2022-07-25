Made for AVR ATMega328P, tested on Arduino Nano

You will need
    avr-gcc binutils-avr avr-libc avrdude avr-gcc-c++


Use the makefile to compile for AVR:


    make build-avr
    make flash-avr
    
Or for linux:

    make build-linux





Veidots priekš AVR ATMega328p, testēts uz Arduino Nano. Arduino bibliotēkas netika izmantotas, toties tika atstāts bootloaders, jo tas ir vienīgais veids kā flashot caur avrdude bez ISP programmētāja (kas man nebija pieejams). Iespējams flashot arī ar ISP nedaudz izmainot Makefile.


No AVR bibliotēkas izmantots <avr/io.h> un <avr/interrupt.h>


Ir iespēja daļēji testēt arī pa taisno uz linux (man sākumā nebija pieejams mikrokontrolieris), viss tiek izvadīts uz std::cout. Platformas izvēle notiek caur #ifdefiem (izmantojot makefile kā aprakstīts zemāk nevajadzētu būt problēmām). Tad gan nevar mainīt virzienu izmantojot pogu (aprakstīts vēlāk).


## Atkarības:

avr-gcc binutils-avr avr-libc avrdude avr-gcc-c++

https://www.nongnu.org/avr-libc/

https://www.nongnu.org/avrdude/


    sudo apt install gcc-avr binutils-avr avr-libc avr-gcc-c++

    sudo apt install avrdude


Kompilēju uz Fedora 36, gcc 11.2.0. Ja caur apt pieejamas tikai vecākas avr-gcc versijas, iespējams jābūvē kā aprakstīts

https://onlinedocs.microchip.com/pr/GUID-317042D4-BCCE-4065-BB05-AC4312DBC2C4-en-US-2/index.html?GUID-41EADB64-AF46-4891-8D49-4A7FBACB147B

# AVR


D13(PB5) izmantots kā virziena maiņas poga


    make build-avr


    make flash-avr


Lai flashotu ar citu programmētāju, kā arī lai izvēlētos citu usb portu jāizmana šī rindā Makefile:

    avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:avrbuild/out.hex


Var izmainīt ātrumu, sākuma virzienu kā arī LED skaitu pievienojot parametrus:

    -CFLAGS+=-DDIRECTION=1 -CFLAGS+=-DSPEED=140 -CFLAGS+=-DLEDCOUNT=11
(ātrums robežās 0 - 255; LED skaits robežās 0-17)


# Linux

    make build-linux

Programma tiks palaista uzreiz. Tāpat var izmainīt

    -CFLAGS+=-DDIRECTION=1 -CFLAGS+=-DSPEED=140 -CFLAGS+=-DLEDCOUNT=11



