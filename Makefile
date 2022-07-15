IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lstdc++

test:
	gcc -Wall -c *.cpp
	mv *.o build/
	gcc -Wall $(LIBS) -o build/test build/*.o 
	./build/test

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

