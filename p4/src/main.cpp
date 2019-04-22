#include <iostream>
#include "dni.hpp"
#include <string>
#include "celda.hpp"
#include "hash.hpp"
#include <vector>
#include <iomanip>

//Declaramos el contador de dni para hacer el estudio
count dni::c_;

int main(void) {

   //variables
   int nbloques=0, nceldas=0, fe=0, fd=0, npruebas=0;
   float factor=0.0;
   fdispersion<dni>* h;
   fexploracion<dni>* g;

   //opciones
   std::cout << "Numero de celdas de la tabla: ";
   std::cin >> nceldas;
   std::cout << std::endl;

   std::cout << "Numero de bloques de la tabla: ";
   std::cin >> nbloques;
   std::cout << std::endl;

   std::cout << "******* MENU ******" << std::endl;
   std::cout << "Funcion dispersion: " << std::endl;
   std::cout << "1.- Suma" << std::endl;
   std::cout << "2.- Modulo" << std::endl;
   std::cout << "3.- Pseudoaleatoria" << std::endl;
   std::cin >> fd;
   std::cout << std::endl;

   std::cout << "Funcion exploracion: " << std::endl;
   std::cout << "1.- Lineal" << std::endl;
   std::cout << "2.- Cuadratica" << std::endl;
   std::cout << "3.- Dispersion doble" << std::endl;
   std::cout << "4.- Redispersion" << std::endl;
   std::cin >> fe;
   std::cout << std::endl;

   switch(fd) {
      case 1:
         h=new suma<dni>(nceldas);
         break;
      case 2:
         h=new modulo<dni>(nceldas);
         break;
      case 3:
         h=new pseudo<dni>(nceldas);
         break;
      default:
         std::cout << "Error\n";

   }

   switch(fe) {
      case 1:
         g=new lineal<dni>(nceldas, h);
         break;

      case 2:
         g=new cuadratica<dni>(nceldas, h);
         break;
      
      case 3:
         g=new dispdoble<dni>(nceldas, h);
         break;
      
      case 4:
         g=new redisp<dni>(nceldas, h);
         break;
      
      default:
         std::cout << "Error\n";
   }

   //creacion de la tabla
   hash<dni> tabla(nceldas, nbloques, fd, fe);

   std::cout << "Introduzca el factor de carga(0<factor<1): ";
   std::cin >> factor;
   std::cout << std::endl;

   int N=factor*nceldas*nbloques;

   //creacion del banco de registros
   std::vector<dni> banco(2*N,0);

   //introducimos los dnis en el banco
   for(int i=0; i<2*N; i++) {
      banco[i]=dni(i);
   }

   //para mostrar los dnis que estoy metiendo
   // for(dni d: banco) {
   //    std::cout << d << "  \n";
   // }
   // std::cout << std::endl;

   //inserto en la tabla la mitad de los dnis
   for(int j=0; j<N; j++)
      tabla.insertar(banco[j]);

   //mostrar la tabla
   // std::cout << "***TABLA***\n\n";
	// tabla.write(std::cout);

   std::cout << "Introduzca el numero de pruebas: ";
   std::cin >> npruebas;
   std::cout << std::endl;

   //ESTUDIO
   std::cout << "\n ***RESULTADOS***\n";

   std::cout << "Celdas" << std::setw(10) << "Bloques" << std::setw(15);
   std::cout << "Dispersion" << std::setw(15) << "Exploracion" << std::setw(10);
   std::cout << "Carga" << std::setw(10) << "Pruebas\n";
  
   std::cout << nceldas << std::setw(10) << nbloques << std::setw(15);
   std::cout << h->get_name() << std::setw(18) << g->get_name() << std::setw(10);
   std::cout << factor << std::setw(5) << npruebas << "\n\n";

   std::cout << std::setw(20) << "Minimo" << std::setw(10) << "Medio" << std::setw(10) << "Maximo" << std::setw(15) << "\n";

   //hacemos el estudio de las busquedas
   dni::c_.reset();
   dni::c_.start();
   for(int j=0; j < npruebas; j++) {
      // dni::c_.start();  
      tabla.buscar(banco[rand()%N]);
      dni::c_.stop();
   }

   std::cout << "Busquedas" << std::setw(10);
   std::cout << std::setw(10) << dni::c_.get_min() << std::setw(10);
   std::cout << std::setw(10) << dni::c_.get_acc()/npruebas << std::setw(10);
   std::cout << std::setw(10) << dni::c_.get_max() << std::setw(10) << "\n";
   dni::c_.reset();

   //estudio de insercion
   dni::c_.start();
   for(int j=0; j < npruebas; j++) {
      // dni::c_.start();
      tabla.buscar(banco[N+rand()%N]);
      dni::c_.stop();
   }

   std::cout << "Insercion" << std::setw(10);
   std::cout << std::setw(10) << dni::c_.get_min() << std::setw(10);
   std::cout << std::setw(10) << dni::c_.get_acc() << std::setw(10);
   std::cout << std::setw(10) << dni::c_.get_max() << std::setw(10) << "\n";
   dni::c_.reset();


}
































/*******COMPROBACION DE QUE LA CLASE CONTADOR FUNCIONA*********/
// void f(void) {
    
//     std::cout << "holiwis\n";
// }

// int main(void) {

//     count c;

//     int i=0;

//     while(i<5) {
//         f();
//         c++;
//         i++;
//     }

//     std::cout << c;
// }

 //  int nbloques;

   //  dni d(3);
   //  unsigned long a= (unsigned long)d;
   // //  d.write(std::cout);

   //  dni n(2);
   //  unsigned long b= (unsigned long)n;
   // //  n.write(std::cout);

   //  if(a<b)
   //    std::cout << "a es menor\n";
   // else
   //    std::cout << "b es menor\n";


   //  std::cout << "Introduzca el numero de bloques: ";
   //  std::cin >> nbloques;
   //  std::cout << "\n";

   // celda<dni> dn(nbloques);
