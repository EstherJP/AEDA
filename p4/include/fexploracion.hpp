#pragma once

#include <iostream>
#include <string>

template<class clave>
class fexploracion {

    // private:
    //     int nceldas_;

    public:
        fexploracion(void) {}
        ~fexploracion(void) {}

        virtual int fexp(const clave& c, int i) const=0;
        virtual int operator()(const clave& c, int i) const=0;
        virtual std::string get_name(void)=0;
};

