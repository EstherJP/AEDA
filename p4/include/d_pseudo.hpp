#pragma once

#include <iostream>
#include <stdlib.h>
#include "fdispersion.hpp"

template<class clave>
class pseudo : public fdispersion<clave> {

    private:
        int nceldas_;
        std::string name_;
    
    public:
        pseudo(int nceldas);
        ~pseudo(void);

        int fdis(const clave& c) const;
        std::string get_name(void);
        int operator()(const clave& c) const;

};

template<class clave>
pseudo<clave>::pseudo(int nceldas): nceldas_(nceldas), name_("Pseudo") {}

template<class clave>
pseudo<clave>::~pseudo(void) {}

template<class clave>
int pseudo<clave>::fdis(const clave& c) const {

    unsigned long a=(unsigned long)c;
    srand(a);
    return (rand() % nceldas_);

}

template<class clave>
std::string pseudo<clave>::get_name(void) {
    return name_;
}

template<class clave>
int pseudo<clave>::operator()(const clave& c) const {
    return fdis(c);
}