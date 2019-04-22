#pragma once

#include <iostream>
#include "fdispersion.hpp"
#include "d_suma.hpp"
#include "d_modulo.hpp"
#include "d_pseudo.hpp"
#include "fexploracion.hpp"

template<class clave>
class lineal : public fexploracion<clave> {

    private:
        int nceldas_;
        fdispersion<clave>* h_;
        std::string name_;

    public:
        lineal(int nceldas, fdispersion<clave>* d);
        ~lineal(void);

        int fexp(const clave& c, int i) const;
        int operator()(const clave& c, int i) const;
        std::string get_name(void);


};

template<class clave>
lineal<clave>::lineal(int nceldas, fdispersion<clave>* d): nceldas_(nceldas), h_(d), name_("Lineal") {}

template<class clave>
lineal<clave>::~lineal(void) {}

template<class clave>
int lineal<clave>::fexp(const clave& c, int i) const {
    int aux=(*h_)(c);
    return ((aux+i)%nceldas_);
}

template<class clave>
int lineal<clave>::operator()(const clave& c, int i) const {
    return fexp(c,i);
}

template<class clave>
std::string lineal<clave>::get_name(void) {
    return name_;
}