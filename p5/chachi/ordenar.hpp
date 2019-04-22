#pragma once

#include <iostream>
#include <string>

template<class clave>
class ordenar {
    public:
        ordenar(void) {}
        ~ordenar(void) {}

        static ordenar<clave>* create(int o, float alfa=0);
        virtual void ordenacion(clave* v, int N)=0;
        virtual std::string get_name(void)=0;
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
    private:
        std::string name_;
    public:
        seleccion(void): name_("Seleccion") {
            #ifdef DEMOSTRACION
                std::cout << "***SELECCION***\n";
            #endif
        }
        ~seleccion(void) {}

        inline std::string get_name(void) { return name_; }

        void ordenacion(clave* v, int N) {
            for(int i=0; i<N; i++) { 
                int min=i;
                #ifdef DEMOSTRACION
                    std::cout << "\nValor minimo actual: " << v[min] << "\n";
                #endif
                for(int j=i+1; j<N; j++){ 
                    if(v[j] < v[min]) {
                    #ifdef DEMOSTRACION
                        std::cout << "Nuevo valor minimo: " << v[j] << "\n";
                        std::cout << "Se intercambian las posiciones " << min << " y " << j << "\n";
                    #endif
                        min=j;
                    }
                }
                clave x=v[i];
                v[i]=v[min];
                v[min]=x;

                #ifdef DEMOSTRACION
                    std::cout << "El vector queda: \n";
                    ordenar<clave>::write(std::cout,v,N);
                #endif
            }
        }
};

template<class clave>
class shakesort : public ordenar<clave> {
    private:
        std::string name_;
    public:
        shakesort(void): name_("ShakeSort") {
            #ifdef DEMOSTRACION
                std::cout << "***SHAKESORT***\n";
            #endif
        }
        ~shakesort(void) {}

        inline std::string get_name(void) { return name_; }

        void ordenacion(clave* v, int N) {
            int ini=0; 
            int fin=N-1; 
            int cam=N;
            clave x;
            while(ini < fin) {
                for(int j=fin; j>=ini; j--) {
                   #ifdef DEMOSTRACION                    
                        std::cout << "Ini: " << ini << " Fin: " << fin; 
                    #endif
                    if(v[j] < v[j-1]) { 
                        x = v[j-1];
                        v[j-1]=v[j];
                        v[j]=x;
                        cam=j;
                        // std::cout << " Cam: " << cam << "\n";
                    } 
                    #ifdef DEMOSTRACION
                        std::cout << "El vector queda:   ";
                        ordenar<clave>::write(std::cout,v,N);
                        std::cout << "\n";
                    #endif
                }
                ini=cam + 1;
                for(int j=ini; j<=fin; j++) {
                    #ifdef DEMOSTRACION
                        std::cout << "Ini: " << ini << " Fin: " << fin;
                    #endif
                    if(v[j] < v[j-1]) { 
                        x = v[j-1];
                        v[j-1]=v[j];
                        v[j]=x;
                        cam=j;
                        // std::cout << " Cam: " << cam << "\n";
                    } 
                    #ifdef DEMOSTRACION
                        std::cout << "El vector queda:   ";
                        ordenar<clave>::write(std::cout,v,N);
                        std::cout << "\n";
                    #endif
                }
                fin=cam-1;
            }
        }
};

//ESTA MAL
template<class clave>
class heapsort : public ordenar<clave> {
    private:
        std::string name_;
    public:
        heapsort(void): name_("HeapSort ") {
            #ifdef DEMOSTRACION
                std::cout << "***HEAPSORT***\n";
            #endif
        }
        ~heapsort(void) {}

        inline std::string get_name(void) { return name_; }

        void baja(int i, clave* v, int N) {
            clave x = v[i];
            int h1=0, h2=0, h=0;

            while(2*i+1 <= N) { 
                h1 = 2*i+1; 
                h2 = h1 + 1;

                if (h1 == N)
                    h = h1; 
                
                else if (v[h2] < v[h1])
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
            #ifdef DEMOSTRACION            
                std::cout << "FASE DE INSERCION\n";
            #endif
            for(int i = N/2-1; i >= 0; i--) {
                #ifdef DEMOSTRACION
                    std::cout << "i: " << i << " x: " << v[i] << "\n";
                #endif
                baja(i, v, N);
                #ifdef DEMOSTRACION
                    std::cout << "El vector queda:   ";
                    ordenar<clave>::write(std::cout,v,N);
                    std::cout << "\n";
                #endif
            }

            #ifdef DEMOSTRACION            
                std::cout << "HEAP ordenado: ";
                ordenar<clave>::write(std::cout,v,N);
                std::cout << "\n";
            #endif


            for(int i = N-1; i >= 0; i--) { 
                #ifdef DEMOSTRACION
                    std::cout << "i: " << i << " x: " << v[i] << "\n";
                #endif
                x = v[0];
                v[0] = v[i];
                v[i] = x;
                baja(0,v,i-1);
                #ifdef DEMOSTRACION
                    std::cout << "El vector queda:   ";
                    ordenar<clave>::write(std::cout,v,N);
                    std::cout << "\n";
                #endif
            }
        }
};

template<class clave>
class mergesort : public ordenar<clave> {
    private:
        std::string name_;
    public:
        mergesort(void): name_("MergeSort") {
            #ifdef DEMOSTRACION
                std::cout << "***MERGESORT***\n";
            #endif
        }
        ~mergesort(void) {}

        inline std::string get_name(void) { return name_; }

        void ordenacion(clave* v, int N) {
            sort(v,0,N-1);

            // #ifdef DEMOSTRACION 
            //     std::cout << "El vector queda:   ";
            //     ordenar<clave>::write(std::cout,v,N);
            //     std::cout << "\n";
            // #endif
        }

        void sort(clave* v, int ini, int fin) {
            if(ini < fin) {
                int cen=(ini+fin)/2;
                sort(v,ini,cen);
                sort(v,cen+1,fin);
                merge(v,ini,cen,fin);
            }
        }

        void merge(clave* v, int ini, int cen, int fin) {
            int i=ini, j=cen+1, k=ini;
            clave aux[fin+1];

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

            // #ifdef DEMOSTRACION
            //     std::cout << "ini: " << ini << " fin: " << fin << " centro: " << cen << "\n";
            // #endif
        }
};

template<class clave>
class shellshort : public ordenar<clave> {
    private:
        float alfa_;
        std::string name_;
    public:
        shellshort(float alfa): alfa_(alfa), name_("ShellSort") {
            #ifdef DEMOSTRACION
                std::cout << "***SHELLSORT***\n";
            #endif
        }
        ~shellshort(void) {}

        inline std::string get_name(void) { return name_; }

        void ordenacion(clave* v, int N) {
            int del=N*alfa_;
            while(del > 0) { 
                #ifdef DEMOSTRACION
                    std::cout << "alfa: " << alfa_ << " delta: " << del << std::endl;
                #endif
                del=del/2;
                deltasort(del, v, N);
            }
        }

        void deltasort(int d, clave* v, int N) { 
            clave x;
            int j;
            for(int i=d; i < N; i++) { 
                x = v[i]; 
                j = i; 
                
                while((j >= d) && (x < v[j-d])) { 
                    v[j]=v[j-d];
                    j = j-d;
                }
                v[j]=x;
            }

            #ifdef DEMOSTRACION
                std::cout << "El vector queda:   ";
                ordenar<clave>::write(std::cout,v,N);
                std::cout << "\n";
            #endif
        }
};

template<class clave>
ordenar<clave>* ordenar<clave>::create(int o, float alfa) {

    ordenar<clave>* ord; 
    int i=0;

    switch(o) {
        case 1:
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
           ord=new shellshort<clave>(alfa);
            break;
        default:
            std::cout << "Error\n";
    }
    return ord;
}