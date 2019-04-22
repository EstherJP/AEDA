#pragma once

#include "number_exception.hpp"

class numberbase {

    private:
        int B_;
        int N_;
    
    protected:
        virtual void to_base(int n)=0;
        virtual numberbase* duplicate(void) const=0;

    public:
        numberbase(int sz, int b);
        ~numberbase(void);
        virtual numberbase* operator+(const numberbase*) const=0;
        virtual numberbase* operator-(const numberbase*) const=0;

        virtual std::ostream& write(std::ostream& os) const=0;   
        friend std::ostream& operator<<(std::ostream& os, numberbase* n);

}; 

numberbase::numberbase(int sz, int b): B_(b), N_(sz)
{
    if(B_ < 1 || N_ < 1)
        throw wrong_number_exception();
}

numberbase::~numberbase(void) {}

std::ostream& operator<<(std::ostream& os, numberbase* n) {

    return n->write(std::cout);
}

