#pragma once

#include <iostream>


template<class clave>
class ordenar {
    // private:
    //     clave* v_;
    //     int N_;
    public:
        ordenar(void) {}
        // ordenar(clave* v, int N): v_(v),N_(N) {}
        ~ordenar(void) {}

        static ordenar<clave>* create(int o);
        virtual void ordenacion(clave* v, int N)=0;
        std::ostream& write(std::ostream& os, const clave* v, int N) const {
            for(int i=0; i < N; i++) 
                v[i].write(std::cout);
            os << std::endl;

            return os;
        }

};

//////////////////////////////////////////////////////////////////////////////
template<class clave>
class seleccion : public ordenar<clave> {
    // private:
    //     int N;
    //     std::vector<clave> v;
    public:
        //seleccion(std::vector<clave> v, int N): v(v), N(N) {}
        seleccion(void) {}
        ~seleccion(void) {}

        void ordenacion(clave* v, int N) {
            for(int i=0; i<N; i++) { 
                int min=i;
                for(int j=i+1; j<N; j++){ 
                    if(v[j] < v[min]) {
                     //  std::cout << "if\n";
                        min=j;
                    }
                   // std::cout << "min: " << min << " j: " << j << "\n";
                
                }
               // std::cout << "Min: " << v[min] << " J: " << v[j] << std::endl;
                clave x=v[i];
                v[i]=v[min];
                v[min]=x;
                //v[i].write(std::cout);
            }

        }
};

template<class clave>
class shakesort : public ordenar<clave> {
    public:
        shakesort(void) {}
        ~shakesort(void) {}

        void ordenacion(clave* v, int N) {
            int ini=0; 
            int fin=N-1; 
            int cam=N;
            clave x;
            while (ini < fin) {
                for(int j=fin; j>=ini; j--) {
                    if(v[j] < v[j-1]) { 
                        x = v[j-1];
                        v[j-1]=v[j];
                        v[j]=x;
                        cam=j;
                    } 
                }
                ini=cam + 1;
                for(int j=ini; j<=fin; j++)
                    if(v[j] < v[j-1]) { 
                        x = v[j-1];
                        v[j-1]=v[j];
                        v[j]=x;
                        cam=j;
                    } 
                fin=cam-1;
            }
        }
};

//ESTA MAL
template<class clave>
class heapsort : public ordenar<clave> {
    public:
        heapsort(void) {}
        ~heapsort(void) {}

        void baja(int i, clave* v, int N) {
            clave x = v[i];
            int h1=0, h2=0, h=0;

            while(2*i+1 <= N) { 
                h1 = 2*i+1; 
                h2 = h1 + 1;

                if (h1 == N)
                    h = h1; 
                
                else if (v[h1] > v[h2])
                    h = h1;
                
                else 
                    h = h2;
                
                if(v[h] <= x)
                    break; 
                
                else {                 
                    v[i]=v[h];
                    v[h]=x; 
                    i = h;
                }
            }
        }

        void ordenacion(clave* v, int N) {
            clave x;
            for(int i = N/2-1; i >= 0; i--)
                baja(i, v, N);

            ordenar<clave>::write(std::cout,v,N);

            for(int i = N-1; i >= 0; i--) { 
                x = v[0];
                v[0] = v[i];
                v[i] = x;
                baja(0,v,i-1);
            }
        }
};

template<class clave>
class mergesort : public ordenar<clave> {
    public:
        mergesort(void) {}
        ~mergesort(void) {}

        void ordenacion(clave* v, int N) {
            sort(v,0,N-1);
        }

        void sort(clave* v, int ini, int fin) {
            //int cen;
            if(ini < fin) {
                int cen=(ini+fin)/2;
                sort(v,ini,cen);
                sort(v,cen+1,fin);
                merge(v,ini,cen,fin);
            }
        }

        void merge(clave* v, int ini, int cen, int fin) {
            int i=ini, j=cen+1, k=ini;
            clave aux[fin];

            while((i<=cen) && (j<=fin)) {
                if(v[i] < v[j]) {
                    aux[k]=v[i];
                    i++;
                }
                else {
                    aux[k]=v[j];
                    j++;
                }
                k++;
            }

            if(i > cen) {
                while(j<=fin) {
                    aux[k]=v[j];
                    j++;
                    k++;
                }
            }
            else {
                while(i <= cen) {
                    aux[k]=v[i];
                    i++;
                    k++;
                }
            }
            for(int k=ini; k<=fin; k++)
                v[k]=aux[k];
        }
};

template<class clave>
class shellshort : public ordenar<clave> {
    public:
        shellshort(void) {}
        ~shellshort(void) {}

        void ordenacion(clave* v, int N) {
            int del=N;
            while(del > 0) { 
                del=del/2;
                deltasort(del, v, N);
            }
        }

        void deltasort(int d, clave* v, int N) { 
            clave x;
            for(int i=d + 1; i <= N; i++) { 
                x = v[i]; 
                int j = i; 
                
                while((j > d) && (x < v[j-d])) { 
                    v[j]=v[j-d];
                    j = j-d;
                }
                v[j]=x;
            }
        }
};

template<class clave>
ordenar<clave>* ordenar<clave>::create(int o) {

    ordenar<clave>* ord; 

    switch(o) {
        case 1:
            std::cout << "selecion\n";
           ord=new seleccion<clave>;
            break;
        case 2:
            ord=new shakesort<clave>;
            break;
        case 3:
            ord=new heapsort<clave>;
            break;
        case 4:
            ord=new mergesort<clave>;
            break;
        case 5:
           ord=new shellshort<clave>;
            break;
        default:
            std::cout << "Error\n";
    }
    return ord;
}