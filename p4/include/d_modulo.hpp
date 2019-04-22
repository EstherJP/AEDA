#pragma once

#include <iostream>
#include "fdispersion.hpp"

template<class clave>
class modulo : public fdispersion<clave> {

    private:
        int nceldas_;
        std::string name_;

    public:
        modulo(int nceldas);
        ~modulo(void);   

        int fdis(const clave& c) const;
        std::string get_name(void);
        int operator()(const clave& c) const;

};

template<class clave>
modulo<clave>::modulo(int nceldas): nceldas_(nceldas), name_("Modulo") {}

template<class clave>
modulo<clave>::~modulo(void) {}

template<class clave>
int modulo<clave>::fdis(const clave& c) const {

    // std::cout << "a: " << c << std::endl;

    unsigned long a=(unsigned long)c;
    int r=a % nceldas_;
    // std::cout << "ncledas: " << nceldas_ << std::endl;
    

    // std::cout << "r: " << r << std::endl;

    return (a%nceldas_);
}

template<class clave>
std::string modulo<clave>::get_name(void) {
    return name_;
}

template<class clave>
int modulo<clave>::operator()(const clave& c) const {
    return fdis(c);
}