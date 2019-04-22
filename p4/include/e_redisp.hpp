#pragma once

#include <iostream>
#include "fdispersion.hpp"
#include "d_suma.hpp"
#include "d_modulo.hpp"
#include "d_pseudo.hpp"
#include "fexploracion.hpp"

template<class clave>
class redisp : public fexploracion<clave> {

    public:
        int nceldas_;
        fdispersion<clave>* h_;

    public:
        redisp(int nceldas, fdispersion<clave>* d);
        ~redisp(void);
        std::string name_;

        int fexp(const clave& c, int i) const;
        int operator()(const clave& c, int i) const;
        std::string get_name(void);

};

template<class clave>
redisp<clave>::redisp(int nceldas, fdispersion<clave>* d): nceldas_(nceldas), h_(d), name_("Redisp") {}

template<class clave>
redisp<clave>::~redisp(void) {}

template<class clave>
int redisp<clave>::fexp(const clave& c, int i) const {
    
    int aux=(*h_)(c);
    srand(c);
    int op = (rand() % 3);
    switch(op) {
        case 0:
            return((aux + i) % nceldas_);
            break;

        case 1:
            return(aux + (i * i) % nceldas_);
            break;

        case 2:
            return((aux + i * aux) % nceldas_);
            break;

        default:
            std::cout << "Error en la generación del numero aleatorio" << std::endl;
            exit(0);
            break;
    }
}

template<class clave>
int redisp<clave>::operator()(const clave& c, int i) const {
    return fexp(c,i);
}

template<class clave>
std::string redisp<clave>::get_name(void) {
    return name_;
}