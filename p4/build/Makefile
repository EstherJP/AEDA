IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -O3 -std=c++11 -g -lstdc++

ODIR=../src

LIBS=-lm

_OBJ = main.o count.o dni.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main

$(ODIR)/count.o: $(ODIR)/count.cpp $(IDIR)/count.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/dni.o: $(ODIR)/dni.cpp $(IDIR)/dni.hpp  $(IDIR)/count.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/count.hpp $(IDIR)/dni.hpp $(IDIR)/celda.hpp $(IDIR)/fdispersion.hpp $(IDIR)/d_pseudo.hpp $(IDIR)/d_suma.hpp $(IDIR)/d_modulo.hpp $(IDIR)/fexploracion.hpp $(IDIR)/e_lineal.hpp $(IDIR)/e_cuadratica.hpp $(IDIR)/e_dispdoble.hpp $(IDIR)/e_redisp.hpp $(IDIR)/hash.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~
