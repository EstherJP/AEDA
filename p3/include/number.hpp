#pragma once 

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "number_exception.hpp"
#include "numberbase.hpp"

template <int N, int B, typename T=char>
class number : public numberbase {

    private:
        T* d_;
        char signo_;

        void to_base(int n);
    public:

        number(int n=0);
        number(const number<N, B, T>& n);
        ~number();

        numberbase* duplicate(void) const;

        void c_dos(void);

        std::ostream& write(std::ostream& os) const;

        number<N, B, T> suma(const number<N,B,T> &s) const;
        number<N, B, T> resta(const number<N,B,T> &s) const;
        bool same(const number<N,B,T> &s) const;
        bool mayor(const number<N,B,T> &s) const;
        int mayor_neg(const number<N,B,T> &s) const;

        T get_d(int i) const;
        void set_d(T a, int i);
        char get_signo(void) const;
        void set_signo(char s);

        number<N,B,T> operator+(const number<N,B,T>& n) const;
        number<N,B,T> operator-(const number<N,B,T>& n) const;
        void operator=(const number<N, B, T>& n) const;
        bool operator>(const number<N,B,T>& n) const;
        operator number<N+1,B,T>(void) const;
        numberbase* operator+(const numberbase* n) const;
        numberbase* operator-(const numberbase* n) const;
        
};

template <int N, int B, typename T>
number<N, B, T>::number(int n): numberbase(N, B) {

    d_=new T[N];
    if(!d_)
        throw null_pointer_exception();
    if(n < 0)
        signo_ = '-';
    else
        signo_ = '+';
        
    to_base(n);
}

template <int N, int B, typename T>
number<N, B, T>::number(const number<N, B, T>& n): numberbase(N,B) {

    d_=new T[N];
    signo_=n.get_signo();
    for(int i=0; i < N; i++) {
        d_[i]=n.get_d(i);
    }
}

template <int N, int B, typename T>
numberbase* number<N,B,T>::duplicate(void) const {
    return new number<N, B, T>(*this);
}

template <int N, int B, typename T>
number<N, B, T>::~number(void) {
  if(d_!=NULL)
       delete[] d_;
}

template <int N, int B, typename T>
void number<N, B, T>::to_base(int n) {

    bool c=false;
    int a, i=0;

    if(n<0) {
        n*=-1;
        if(B==2)
            c=true;
    }

    if(B==2)
        signo_=' ';

    while(n > 0) {
        a=n%B;  
        d_[i]=a;
        n=n/B; 
        i++;
    }

    while(i < N){
            d_[i]=0;
            i++;
    }

    if(c==true && B==2)
        c_dos();

    //write(std::cout);
}

template <int N, int B, typename T>
void number<N,B,T>::c_dos(void) {

    bool c=false;
    for(int i=0; i<N; i++) {
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

template <int N, int B, typename T>
std::ostream& number<N, B, T>::write(std::ostream& os) const {

    os << signo_ << " ";
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

template <int N, int B, typename T>
number<N, B, T> number<N, B, T>::suma(const number<N,B,T> &s) const {

    number<N,B,T> sr;
    int n1=0, n2=0, r=0, c;
    int carry = 0;

    for(int i=0; i < N; i++) {
        r = 0;

        n1=get_d(i);
        n2=s.get_d(i);

        r=n1+n2+carry;

        if(carry==1) {
            carry=0;
        }
        //si el resultado es menor que la base lo meto
        if(r < B) {
            sr.d_[i] = r;
           // std::cout << "r: " << r << std::endl;
        }
        //si el resultado es mayor que la base activo el carry y le resto la base y lo meto
        else if(r >= B) {
            carry=1;
            r=r-B;
            
            sr.d_[i] = r; 
          //  std::cout << "r2: " << r << std::endl;

        }
    }
    
    if(carry==1) {
        throw overflow_exception();
    }
    
    return sr;
}

template <int N, int B, typename T>
number<N, B, T> number<N, B, T>::resta(const number<N,B,T> &s) const {

    number<N,B,T> sr;
    int n1=0, n2=0, r=0, c;
    int carry = 0;

    for(int i=0; i < N; i++) {
        r = 0;

        n1=get_d(i);
        n2=s.get_d(i);

        r=n1-n2;
        if(n1<n2) 
            r*=-1;

       // std::cout << n1 << " - " << n2 << " = " << r << '\n';
        r=n1-n2-carry;
        //si el resultado es menor que la base lo meto
        if(r < B) {
            sr.d_[i] = r;
        }
        //si el resultado es mayor que la base activo el carry y le resto la base y lo meto
        else if(r >= B) {
            carry=1;
            r=r+B;  
            sr.d_[i] = r;   
        }
    }
    
    return sr;
}

template <int N, int B, typename T>
bool number<N, B, T>::same(const number<N,B,T> &s) const {

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

template <int N, int B, typename T>
bool number<N, B, T>::mayor(const number<N,B,T> &s) const {

    int n1=0, n2=0;
    bool m=false;

    //for(int i=d_.size()-1; i >= 0; i--) {
    for(int i=N-1; i >= 0; i--) {
        n1=get_d(i);
        n2=s.get_d(i);

       // std::cout << n1 << " y " << n2 << std::endl;
 
        if(n1 < n2)  {
           // std::cout << "El segundo numero es mayor" << std::endl;
            m=true;
        }
        else if(n2 > n1)
            m=false;
           // std::cout << "El primero numero es mayor" << std::endl;
    }
    return m;
}

template<int N, int B, typename T>
int number<N,B,T>::mayor_neg(const number<N,B,T> &s) const {

    if(signo_==s.get_signo())
        return 0;
    if(signo_=='+')
        return 1;
    if(signo_=='-')
        return 2;
}

template <int N, int B, typename T>
T number<N, B, T>::get_d(int i) const {
    return d_[i];
}

template <int N, int B, typename T>
void number<N,B,T>::set_d(T a, int i) {
    d_[i]=a;
}

template <int N, int B, typename T>
char number<N, B, T>::get_signo(void) const {
    return signo_;
}

template <int N, int B, typename T>
void number<N,B,T>::set_signo(char s) {
    signo_=s;
}

template<int N, int B, typename T>
number<N,B,T> number<N,B,T>::operator+(const number<N,B,T>& n) const {
    number<N,B,T> t;

    if(signo_ == n.get_signo()) {
        t=suma(n);
        t.signo_=signo_;
    }

    if(signo_=='+' && n.get_signo()=='-') {
        if(*this>n) {
            t=n.resta(*this);
            t.signo_='+';
        }
        else {
             t=resta(n);
             t.signo_='-';
        }     
    }

    if(signo_=='-' && n.get_signo()=='+') {
        if(!(*this>n)) {
            t=resta(n);
            t.signo_='-';
        }
        else {
            t=n.resta(*this);
            t.signo_='+';
        }
    }

    return t;
}

template <int N, int B, typename T>
numberbase* number<N,B,T>::operator+(const numberbase* n) const {

    const number<N,B,T>* s=dynamic_cast<const number<N,B,T>*>(n);
    number<N,B,T>* r=dynamic_cast<number<N,B,T>*>(duplicate());

    (*r)=(*this)+(*s);

    return r;
}

template<int N, int B, typename T>
number<N,B,T> number<N,B,T>::operator-(const number<N,B,T>& n) const {
    number<N,B,T> t;

   /* if(signo_ == n.get_signo()) {
        t=suma(n);
        t.signo_=signo_;
    }

    if(signo_=='+' && n.get_signo()=='-') {
        if(*this>n) {
            t=n.resta(*this);
            t.signo_='+';
        }
        else {
             t=resta(n);
             t.signo_='-';
        }     
    }

    if(signo_=='-' && n.get_signo()=='+') {
        if(!(*this>n)) {
            t=resta(n);
            t.signo_='+';
        }
        else {
            t=n.resta(*this);
            t.signo_='-';
        }
    }

    return t;*/

    if(signo_ == n.get_signo()) {
        if(signo_=='-') {
            t=suma(n);
            t.signo_=signo_;
        }
        else if(signo_=='+') {
            t=resta(n);
            if(*this>n) {
                t.signo_='+';
            }
            else {
                t.signo_='-';
            }  
        }
    }

    if(signo_=='+' && n.get_signo()=='-') {
        if(*this>n) {
            t=n.resta(*this);
            t.signo_='+';
        }
        else {
             t=resta(n);
             t.signo_='-';
        }     
    }

    if(signo_=='-' && n.get_signo()=='+') {
        if(!(*this>n)) {
            t=resta(n);
            t.signo_='+';
        }
        else {
            t=n.resta(*this);
            t.signo_='-';
        }
    }
 
    return t; 
}

template <int N, int B, typename T>
numberbase* number<N,B,T>::operator-(const numberbase* n) const {

    const number<N,B,T>* s=dynamic_cast<const number<N,B,T>*>(n);
    number<N,B,T>* r=dynamic_cast<number<N,B,T>*>(duplicate());

    (*r)=(*this)-(*s);

    return r;
}

template <int N, int B, typename T>
void number<N, B, T>::operator=(const number<N, B, T>& n) const{

    for(int i=0; i < N; i++)
        d_[i]=n.d_[i];
}

template <int N, int B, typename T>
bool number<N, B, T>::operator>(const number<N,B,T>& n) const {

    return mayor(n);
}

template <int N, int B, typename T>
number<N, B, T>::operator number<N+1,B,T>(void) const {

    number<N+1,B,T> t;
    //std::cout << "N+1 pricipio\n";

    t.set_signo(get_signo());
    for(int i=0; i < N; i++) 
       t.set_d(d_[i],i);

    //t.write(std::cout);

    return t;
}

class BinaryNumber : public number<8,2>{
    public:
        BinaryNumber(int n): number<8,2>(n) {}
 };

class OctalNumber : public number<8,8>{
    public:
        OctalNumber(int n): number<8,8>(n) {}
 };

class DecimalNumber : public number<8,10>{
    public:
        DecimalNumber(int n): number<8,10>(n) {}
 };

class HexaNumber : public number<8,16> {
    public:
        HexaNumber(int n): number<8,16>(n) {} 
};





