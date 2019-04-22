#pragma once 

#include "number.hpp"

template <int N, typename T>
class number<N,2,T> {

    private:
        T* d_;

        void to_base(int n);
    public:

        number(int n=0);
        number(const number<N, 2, T>& n);
        ~number();
        number<N, 2, T> suma(const number<N,2,T> &s) const;
        number<N, 2, T> resta(const number<N,2,T> &s) const;
        bool same(const number<N,2,T> &s) const;
        bool mayor(const number<N,2,T> &s) const;
        std::ostream& write(std::ostream& os) const;
        T get_d(int i) const;
        void c_dos(void);

        void operator=(const number<N, 2, T>& n) const;
       // number<N,B,T> operator+(const number<N,2,T>& n) const;
        bool operator>(const number<N,2,T>& n) const;
};

template <int N, typename T>
number<N, 2, T>::number(int n) {

    d_=new T[N];
    if(!d_)
        throw null_pointer_exception();

    to_base(n);
}

template <int N, typename T>
number<N, 2, T>::number(const number<N, 2, T>& n) {

    d_=new T[N];
    for(int i=0; i < N; i++) {
        d_[i]=n.get_d(i);
    }
}

template <int N,  typename T>
number<N, 2, T>::~number(void) {
  if(d_!=NULL)
       delete[] d_;
}

template <int N,  typename T>
void number<N, 2, T>::to_base(int n) {
    bool c=false;
    int a, i=0;

    if(n<0) {
        c=true;
        n*=-1;
    }

    while(n > 0) {
        a=n%2;  
        d_[i]=a;
        n=n/2; 
        i++;
    }

    if(c==true)
        c_dos();
}

template <int N, typename T>
void number<N,2,T>::c_dos(void) {

    bool c=false;

    for(int i=0; i<N; i++) {
   // T aux=d_[i]+48;

        if(c==true) {
            if(d_[i]==1) {
                d_[i]=0;
            }

            else if(d_[i]==0)
                d_[i]=1;         
        }

        if(d_[i]==1) 
                c=true;
    }
}

template <int N, typename T>
std::ostream& number<N, 2, T>::write(std::ostream& os) const {
    for(int i=N-1; i >= 0; i--) {
        if(d_[i] <= 9) {
            T aux=d_[i]+48;
            os << aux << " ";
        }
        else {
            T aux= 'A' + d_[i] - 10;
            os << aux << " ";
        }
    }
    std::cout << std::endl; 

    return os;
}

template <int N,  typename T>
T number<N, 2, T>::get_d(int i) const {
    return d_[i];
}

template <int N,  typename T>
bool number<N, 2, T>::same(const number<N,2,T> &s) const {

    int n1=0, n2=0, cont=0;

    for(int i=0; i < N; i++) {
        n1=get_d(i);
        n2=s.get_d(i);

        if(n1==n2) 
            cont++;
    }
            
    if(cont==N) {
        std::cout << "Los numeros son iguales" << std::endl;
        return 1;
    }
    else {
        std::cout << "Son diferentes" << std::endl;
        return 0;
    }
}

template <int N,  typename T>
bool number<N, 2, T>::mayor(const number<N,2,T> &s) const {

    int n1=0, n2=0;
    bool m=false;

    //for(int i=d_.size()-1; i >= 0; i--) {
    for(int i=N-1; i >= 0; i--) {
        n1=get_d(i);
        n2=s.get_d(i);

       // std::cout << n1 << " y " << n2 << std::endl;
 
        if(n1 < n2)  {
            std::cout << "El segundo numero es mayor" << std::endl;
            m=true;
        }
        else if(n2 > n1)
            std::cout << "El primero numero es mayor" << std::endl;
    }
    return m;
}

// template<int N,  typename T>
// number<N,2,T> number<N,2,T>::operator+(const number<N,2,T>& n) const {
//     number<N,2,T> t;

//     if(signo_ == n.get_signo()) {
//         t=suma(n);
//         t.signo_=signo_;
//     }

//     if(signo_=='+' && n.get_signo()=='-') {
//         if(*this>n) {
//             t=n.resta(*this);
//             t.signo_='-';
//         }
//         else {
//              t=resta(n);
//              t.signo_='-';
//         }     
//     }

//     if(signo_=='-' && n.get_signo()=='+') {
//         if(!(*this>n)) {
//             t=resta(n);
//             t.signo_='-';
//         }
//         else {
//             t=n.resta(*this);
//             t.signo_='+';
//         }
//     }

//     return t;
// }

template <int N,  typename T>
void number<N, 2, T>::operator=(const number<N, 2, T>& n) const{

    for(int i=0; i < N; i++)
        d_[i]=n.d_[i];
}

template <int N,  typename T>
bool number<N, 2, T>::operator>(const number<N,2,T>& n) const {

    return mayor(n);
}

// template <int N, int B>
// //void test_number(void) {
// void test_number2(int v1, int v2) {

//     number<N, 2> n(v1);
//     number<N, 2>cn(n);

//     number<N, 2> n1(v2);
//     number<N, 2>cn1(n1);

//     n.write(std::cout);
//     n1.write(std::cout);

//     std::cout << std::endl;

//     //r=n+n1;
//    // (n+n1).write(std::cout);
//    // r.write(std::cout);

//    // n.suma(n1).write(std::cout);
//     //n.resta(n1).write(std::cout);
//     //n.same(n1);
//     //n.mayor(n1);
// }