Veidots priekš AVR ATMega328p, testēts uz Arduino Nano. Arduino bibliotēkas netika izmantotas, toties tika atstāts bootloaders, jo tas ir vienīgais veids kā flashot caur avrdude bez ISP programmētāja (kas man nebija pieejams). Iespējams flashot arī ar ISP nedaudz izmainot Makefile. 


Ir iespēja daļēji testēt arī pa taisno uz linux (man sākumā nebija pieejams mikrokontrolieris), viss tiek izvadīts uz std::cout. Platformas izvēle notiek caur #ifdefiem (izmantojot makefile kā aprakstīts zemāk nevajadzētu būt problēmām). Tad gan nevar mainīt virzienu izmantojot pogu (aprakstīts vēlāk).


## Atkarības:

avr-gcc binutils-avr avr-libc avrdude avr-gcc-c++

https://www.nongnu.org/avr-libc/

https://www.nongnu.org/avrdude/


    sudo apt install avr-gcc binutils-avr avr-libc avr-gcc-c++

    sudo apt install avrdude


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



