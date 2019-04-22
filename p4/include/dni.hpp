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
        // char* get_dni(void) const;
        void set_dni(char i);
        // char get_dni(void) const;

        bool operator==(const dni& d) const;
        bool operator<(const dni& d) const;
        unsigned long operator=(const int& d);
        // dni operator=(const dni& d);
        std::ostream& write(std::ostream& os) const;
        operator unsigned long(void) const;    
};