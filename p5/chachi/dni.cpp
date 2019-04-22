#include "../include/dni.hpp"
#include <string>

dni::dni(void) {

    for(int i=0; i<8; i++) {
        dni_[i]='0';
        // dni_[i]='0'+rand()%(10);

    }
}

dni::dni(int n) {

    srand(n);
    
    for(int i=0; i<8; i++) {
        dni_[i]='0'+rand()%(10);
    }
}

dni::~dni(void) {}

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

bool dni::operator<(const dni& d) {

    unsigned long a=(unsigned long)(*this);
    unsigned long b=(unsigned long)d;

    c_++;
    if(a<b) 
        return true;

    else
        return false;
}

// bool dni::operator<=(const dni& d) {

//     unsigned long a=(unsigned long)(*this);
//     unsigned long b=(unsigned long)d;

//     c_++;
//     if(a<=b) 
//         return true;

//     else
//         return false;

// }


unsigned long dni::operator=(const int& d) {

    // unsigned long a=(unsigned long)d;
    unsigned long b=(unsigned long)(*this);

    b=d;

    return b;

}

dni::operator unsigned long(void) const {   

    //long long a=atoll(dni_);
    // std::cout << "a_: " << a << "\n";

    std::stringstream ss;
    std::string a;

    int c;
    char j;
    unsigned long b;

    for(int i=0; i<8; i++) {
        c=dni_[i];
        a+=c;
    }

    ss << a;
    ss >> b;
    return b;

   // return a;
}