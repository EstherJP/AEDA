#include <iostream>
#include <vector>
#include "dni.hpp"
#include "ordenar.hpp"

count dni::c_;

int main(int argc, char* argv[]) {

    //./main N METODO ALFA NPRUEBAS

    int N=atoi(argv[1]);
    int o=atoi(argv[2]);
    //int alfa=atoi(argv[3]);
    // int npruebas=atoi(argv[4]);

    dni* v; 
    v=new dni[N];

    for(int i=0; i<N; i++)
        v[i]=dni(i*100);

    #ifdef DEMOSTRACION
        ordenar<dni>* ordF = ordenar<dni>::create(o);
        std::cout << "SIN ORDENAR: \n";
        ordF->write(std::cout, v, N);

        std::cout << " ''ORDENADO'': \n";
        ordF->ordenacion(v,N);
        ordF->write(std::cout, v, N);
   #endif

}