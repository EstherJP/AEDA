#pragma once

#include <iostream>
#include <iomanip>
#include <exception>
//#include <new>

class number_exception: public std::exception { };

class bad_alloc_exception: public number_exception {
    public:
        virtual const char* what(void) const throw() {

            return "Mala posicion";

        }
};

class null_pointer_exception: public number_exception {
    public:
        virtual const char* what(void) const throw() {

            return "No se pudo crear el puntero";

        }
};

class overflow_exception: public number_exception {
    public:
        virtual const char* what(void) const throw() {

            return "Índice sobrepasado";

        }
};

class underflow_exception: public number_exception {
    public:
        virtual const char* what(void) const throw() {
            return "Índice incorrecto";
        }
};
