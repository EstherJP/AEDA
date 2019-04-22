IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g -lstdc++

ODIR=../src

LIBS=-lm

_OBJ = main.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main

$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/number.hpp $(IDIR)/number_exception.hpp $(IDIR)/binary.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~
