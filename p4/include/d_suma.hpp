#pragma once

#include <iostream>
#include "fdispersion.hpp"

template<class clave>
class suma : public fdispersion<clave> {

    private:
        int nceldas_;
        std::string name_;
    
    public:
        suma(int nceldas);
        ~suma(void);

        int fdis(const clave& c) const;
        std::string get_name(void);
        int operator()(const clave& c) const;

};

template<class clave>
suma<clave>::suma(int nceldas): nceldas_(nceldas), name_("Suma") {}

template<class clave>
suma<clave>::~suma(void) {}

template<class clave>
int suma<clave>::fdis(const clave& c) const {

    unsigned long a=(unsigned long)c;
    int d=0;

    while(0 < a) {
        int y=a%10;
        d+=y;
        a=a/10;
    }
    return (d%nceldas_);
}

template<class clave>
std::string suma<clave>::get_name(void) {
    return name_;
}

template<class clave>
int suma<clave>::operator()(const clave& c) const {
    return fdis(c);
}

