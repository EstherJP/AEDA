IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g -lstdc++

ODIR=../src

LIBS=-lm

_OBJ = p3.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: p3

$(ODIR)/p3.o: $(ODIR)/p3.cpp $(IDIR)/number.hpp $(IDIR)/number_exception.hpp $(IDIR)/numberbase.hpp $(IDIR)/calculator.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

p3: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~
