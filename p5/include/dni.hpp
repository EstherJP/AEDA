#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
#include "count.hpp"

class dni {

    private:
        char dni_[8];                //vector que contiene el dni

    public:
        static count c_;             //contador

        dni(void);
        dni(int n);                  //contructor que crea un dni rando,
        ~dni(void);                 //destructor

        char get_dni(int i) const;
        void set_dni(char i);

        bool operator==(const dni& d) const;
        bool operator<(const dni& d);
        unsigned long operator=(const int& d);

        std::ostream& write(std::ostream& os) const;
        operator unsigned long(void) const;    
};