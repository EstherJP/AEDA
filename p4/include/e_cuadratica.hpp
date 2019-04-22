#pragma once

#include <iostream>
#include "fdispersion.hpp"
#include "d_suma.hpp"
#include "d_modulo.hpp"
#include "d_pseudo.hpp"
#include "fexploracion.hpp"

template<class clave>
class cuadratica : public fexploracion<clave> {

    public:
        int nceldas_;
        fdispersion<clave>* h_;
        std::string name_;

    public:
        cuadratica(int nceldas, fdispersion<clave>* d);
        ~cuadratica(void);

        int fexp(const clave& c, int i) const;
        int operator()(const clave& c, int i) const;
        std::string get_name(void);
};

template<class clave>
cuadratica<clave>::cuadratica(int nceldas, fdispersion<clave>* d): nceldas_(nceldas), h_(d), name_("Cuadratica") {}

template<class clave>
cuadratica<clave>::~cuadratica(void) {}

template<class clave>
int cuadratica<clave>::fexp(const clave& c, int i) const {

    int aux=(*h_)(c);
    return ((aux+(i*i)) % nceldas_);
}

template<class clave>
int cuadratica<clave>::operator()(const clave& c, int i) const {
    return fexp(c,i);
}

template<class clave>
std::string cuadratica<clave>::get_name(void) {
    return name_;
}