#include "../include/dni.hpp"
#include <string>

dni::dni(void) {

    for(int i=0; i<8; i++) {
        dni_[i]='0';
    }
}

dni::dni(int n) {

    srand(n);
    
    // dni_=new char[8];

    for(int i=0; i<8; i++) {
        dni_[i]='0'+rand()%(10);
    }

    // write(std::cout);
}

dni::~dni(void) { 
    // delete[] dni_;
}

std::ostream& dni::write(std::ostream& os) const {

    for(int i=0; i<8; i++) {
        os << dni_[i];
    }
    os << " ";

    return os;
}

char dni::get_dni(int i) const {
    return dni_[i];
}

// char* dni::get_dni(void) const {
//     return dni_;
// }

void dni::set_dni(char n) {

    for(int i=0; i<8; i++)
        dni_[i]=n;
}

bool dni::operator==(const dni& d) const {

    c_++;
   for(int i=0; i<8;i++) {
        if(dni_[i]!=d.get_dni(i)) {
            return false;
        }
    }
    return true;

    // unsigned long a=(unsigned long)d;
    // unsigned long b=(unsigned long)(*this);

    // if(b==d) 
    //     return true;
    // else
    //     return false;
}

bool dni::operator<(const dni& d) const {

    unsigned long a=(unsigned long)d;
    unsigned long b=(unsigned long)(*this);

    if(b<a) {
        c_++;
        return true;
    }
    else
        return false;
}

// char dni::get_dni(void) {

//     return dni_;
// }

// dni dni::operator=(const dni& d) {

//     for(int i=0; i<8; i++)
//         dni_[i]=d.get_dni(i);

//     return *this;

// }

unsigned long dni::operator=(const int& d) {

    // unsigned long a=(unsigned long)d;
    unsigned long b=(unsigned long)(*this);

    b=d;

    return b;

}

dni::operator unsigned long(void) const {   

    long long a=atoll(dni_);
    // std::cout << "a_: " << a << "\n";
    return a;
}