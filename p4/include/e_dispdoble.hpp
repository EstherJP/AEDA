#pragma once

#include <iostream>
#include "fdispersion.hpp"
#include "d_suma.hpp"
#include "d_modulo.hpp"
#include "d_pseudo.hpp"
#include "fexploracion.hpp"

template<class clave>
class dispdoble : public fexploracion<clave> {

    public:
        int nceldas_;
        fdispersion<clave>* h_;
        std::string name_;

    public:
        dispdoble(int nceldas, fdispersion<clave>* d);
        ~dispdoble(void);

        int fexp(const clave& c, int i) const;
        int operator()(const clave& c, int i) const;
        std::string get_name(void);

};

template<class clave>
dispdoble<clave>::dispdoble(int nceldas, fdispersion<clave>* d): nceldas_(nceldas), h_(d), name_("Disp. doble") {}

template<class clave>
dispdoble<clave>::~dispdoble(void) {}

template<class clave>
int dispdoble<clave>::fexp(const clave& c, int i) const {

    int aux=(*h_)(c);
    return ((aux + (i*aux)) % nceldas_);
}

template<class clave>
int dispdoble<clave>::operator()(const clave& c, int i) const {
    return fexp(c,i);
}

template<class clave>
std::string dispdoble<clave>::get_name(void) {
    return name_;
}