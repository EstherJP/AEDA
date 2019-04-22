#pragma once

#include <iostream>
#include "celda.hpp"
#include "fdispersion.hpp"
#include "fexploracion.hpp"

#include "d_modulo.hpp"
#include "d_pseudo.hpp"
#include "d_suma.hpp"

#include "e_lineal.hpp"
#include "e_cuadratica.hpp"
#include "e_dispdoble.hpp"
#include "e_redisp.hpp"

template<class clave>
class hash {

    private:
        int nceldas_;
        int nbloques_;

        celda<clave>** t_;
    
        fdispersion<clave>* h_;
        fexploracion<clave>* g_;

    public:
        hash(int nceldas, int nbloques, int fd, int fe);
        ~hash(void);

        bool buscar(clave& c) const;
        bool insertar(clave c);

        std::ostream& write(std::ostream& os) const;
};

template<class clave>
hash<clave>::hash(int nceldas, int nbloques, int fd, int fe): 
    nceldas_(nceldas), 
    nbloques_(nbloques) 
{
    //creo las celdas de la tabla
    t_=new celda<clave>*[nceldas_];

    // creo los bloques de las celdas
    for(int i=0; i<nceldas_; i++)
        t_[i]=new celda<clave>(nbloques_);

    //llamada a la funcion dispersion
    switch(fd) {
        case 1:
            h_=new suma<clave>(nceldas_);
            break;
        case 2:
            h_=new modulo<clave>(nceldas_);
            break;
        case 3:
            h_=new pseudo<clave>(nceldas_);
            break;
        default:
            std::cout << "Error\n";
    }

    switch(fe) {
        case 1:
            g_=new lineal<clave>(nceldas_, h_);
            break;

        case 2:
            g_=new cuadratica<clave>(nceldas_, h_);
            break;
        
        case 3:
            g_=new dispdoble<clave>(nceldas_, h_);
            break;
        
        case 4:
            g_=new redisp<clave>(nceldas_, h_);
            break;
        
        default:
            std::cout << "Error\n";
    }
}

template<class clave>
hash<clave>::~hash(void) {
    if(t_!=NULL) {
        for(int i=0; i<nceldas_; i++) {
            if(t_[i]!=NULL) {
                delete t_[i];
                t_[i]=NULL;
            }
        }
        delete[] t_;
    }
}

template<class clave>
bool hash<clave>::buscar(clave& c) const {
    bool find=false;
    bool full=false;
    int i=0;

    while(!find && i<nceldas_ && !full) {
        find=t_[(*g_)(c,i)]->buscar(c);
        full=t_[(*g_)(c,i)]->full();

        if(!find)
            i++;
    }
    return find;
}

template<class clave>
bool hash<clave>::insertar(clave c) {
    bool insert=false;
    int i=0;

    while(!insert && i<nceldas_) {
      //  insert=t_[g_->fexp(h_->fdis(c),i)]->insertar(c);
       insert=t_[(*g_)(c,i)]->insertar(c);
        // sd::cout << "insertado celda: " << 
        // if(insert==false)
        //     std::cout << "colision\n";
        if(insert==false)
            i++;

    }
    if(insert)
        return true;
    else 
        return false;
}

template<class clave>
std::ostream& hash<clave>::write(std::ostream& os) const {
    
    for(int i=0; i<nceldas_; i++) {
        os << "[" << i+1 << "]";

        t_[i]->write(std::cout);
        os << std::endl;
    }

    return os;
}
