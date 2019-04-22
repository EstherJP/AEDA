#pragma once

#include <iostream>

template<class clave>
class celda {

    private:
        int nbloques_; 
        int nclaves_;

        clave* clv_;   //vector de nceldas

    public:
        celda(void) {}
        celda(int nbloques);
        ~celda(void);

        bool buscar(clave& c) const;
        bool insertar(clave&     c);

        bool full(void) const;

        std::ostream& write(std::ostream& os) const;

};

template<class clave>
celda<clave>::celda(int nbloques):
    nbloques_(nbloques),
    nclaves_(0)
{ 
    clv_=new clave[nbloques_];

    for(int i=0; i<nbloques_; i++) {
        clv_[i]=0;
    }
} 

template<class clave>
celda<clave>::~celda(void) {
    if(clv_!=NULL)
        delete[] clv_;
}

template<class clave>
bool celda<clave>::full(void) const {

    if(nbloques_==nclaves_)
    // for(int i=0; i<nbloques_; i++)
    //     if(clv_[i]==0)
        return true;
    else
        return false;
}

template<class clave>
bool celda<clave>::buscar(clave& c) const {

    for(int i=0; i<nbloques_; i++) {
        if(clv_[i]==c) 
            return true;
    } 
    return false;
}

template<class clave>
bool celda<clave>::insertar(clave& c) {
    //for(int i=0; i < nbloques_; i++) {
    // int i=0;
    // bool insert=false;
    // while(!insert && i<nbloques_) {
    //     if(clv_[i]==0) {
    //         std::cout << "c: " << c << "\n";
    //         clv_[i]=c;
    //         std::cout << "clv_[i]: " << clv_[i] << "\n";
    //         nclaves_++;
    //         insert=true;
    //     }
    //     i++;
    // }
    // return insert;
    if(!full()) {
        // std::cout << "c: " << c << "\n";
        clv_[nclaves_]=c;
        // std::cout << "clv_[i]: " << clv_[nclaves_] << "\n";
        nclaves_++;
        return true;
    }
    return false;
}

template<class clave>
std::ostream& celda<clave>::write(std::ostream& os) const {

    // std::cout << "nclaves " << nclaves_ << std::endl;
    for(int i=0; i<nbloques_; i++) {
        clv_[i].write(std::cout);
    }
    os << std::endl;

    return os;
}
