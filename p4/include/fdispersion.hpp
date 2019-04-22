#pragma once

#include <iostream>
#include <string>

template<class clave>
class fdispersion {

    // private:
    //     int nceldas_;

    public:
        fdispersion(/*int nceldas*/void) {}
        ~fdispersion(void) {}
        virtual int fdis(const clave& c) const=0;
        virtual std::string get_name(void)=0;
        virtual int operator()(const clave& c) const=0;
};

