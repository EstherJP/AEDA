IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -O3 -std=c++17 -g -lstdc++

ODIR=../src

LIBS=-lm

_OBJ = main.o count.o dni.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main

$(ODIR)/count.o: $(ODIR)/count.cpp $(IDIR)/count.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/dni.o: $(ODIR)/dni.cpp $(IDIR)/dni.hpp  $(IDIR)/count.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/count.hpp $(IDIR)/dni.hpp $(IDIR)/ordenar.hpp  
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~
