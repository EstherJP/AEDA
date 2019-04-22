#include <iostream>
#include <vector>
#include "dni.hpp"
#include "ordenar.hpp"
#include <stdlib.h>

count dni::c_;

int main(int argc, char* argv[]) {

    //./main N METODO SEMILLA ALFA NPRUEBAS

    int N=atoi(argv[1]);
    int o=atoi(argv[2]);
    int seed=atoi(argv[3]);

    dni* v; 
    v=new dni[N];

    for(int i=0; i<N; i++)
        v[i]=dni(i*seed);

    if(argc==6) {
        // for(int i=0; i<N; i++)
        //     v[i]=dni(i*seed);
        int npruebas=atoi(argv[5]);
        float alfa=atof(argv[4]);
        int i=0;

        std::cout << "                  " << "Numero de comparaciones\n";
        std::cout << "          " << "Minimo" << "      " << "Medio" << "      " << "Maximo" << "\n";
        while(i<5) {
            ordenar<dni>* ordF = ordenar<dni>::create(i+1,alfa);
            dni::c_.start();
            for(int j=0; j<npruebas; j++) {
                ordF->ordenacion(v,N);
                dni::c_.stop();
            }

            std::cout << ordF->get_name();
            std::cout << "   " << dni::c_.get_min() << "     ";
            std::cout << "   " << dni::c_.get_acc() << "     ";
            std::cout << "   " << dni::c_.get_max() << "     " << "\n";
            dni::c_.reset();
        
            i++;
        }
    }

    #ifdef DEMOSTRACION 
        if(o==5) {
            float alfa=atof(argv[4]);
            ordenar<dni>* ordF = ordenar<dni>::create(o,alfa);
            std::cout << "\nSIN ORDENAR: \n";
            ordF->write(std::cout, v, N);
            std::cout << "\n";

            ordF->ordenacion(v,N);

            std::cout << "ORDENADO: \n";
            ordF->write(std::cout, v, N);
        }

        else {
            ordenar<dni>* ordF = ordenar<dni>::create(o);
            std::cout << "\nSIN ORDENAR: \n";
            ordF->write(std::cout, v, N);
            std::cout << "\n";

            ordF->ordenacion(v,N);

            std::cout << "ORDENADO: \n";
            ordF->write(std::cout, v, N);
        }
    #endif

}