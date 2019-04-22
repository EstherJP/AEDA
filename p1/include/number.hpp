#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <sstream>

template <size_t N, size_t B, typename T=char>

class number {

    private:
        std::vector<T> d_;

        void to_base(int n);
    public:
        number() {}
        number(int n);
        ~number() {}

       // void test_number(void);
        number<N, B, T> suma(const number<N,B,T> &s) const;
        number<N, B, T> resta(const number<N,B,T> &s) const;
        void same(const number<N,B,T> &s) const;
        int get_n(int i) const;
        bool mayor(const number<N,B,T> &s) const;
        std::ostream& write(std::ostream& os) const;
        void push(int n);
};

template <size_t N, size_t B, typename T>
number<N, B, T>::number(int n) {
    //d_.resize(N);
    to_base(n);
}

template <size_t N, size_t B, typename T>
void number<N, B, T>::to_base(int n) {

    int a;
    T v;
    int s=N;
    std::stringstream saux;

    while(n > 0) {
        a=n%B;
        if(a>=10) {
            v ='A'+a-10;
        }
        else {
            saux << a;
            saux >> v;
        }

        d_.push_back(v);
        n=n/B; 
    }
}

template <size_t N, size_t B, typename T>
std::ostream& number<N, B, T>::write(std::ostream& os) const {
    //for(int i = 0; i < d_.size(); i++)
    for(int i=d_.size()-1; i >= 0; i--)
        std::cout << d_[i] << " ";
    std::cout << std::endl; 

    return os;
}

template <size_t N, size_t B, typename T>
number<N, B, T> number<N, B, T>::suma(const number<N,B,T> &s) const {

    number<N,B,T> sr;
    int n1=0, n2=0, r=0, c;
    bool carry = false;
    T a;
    std::stringstream saux;

    for(int i=0; i < N; i++) {
        r = 0;

        n1=get_n(i);
        n2=s.get_n(i);

        r=n1+n2;
        std::cout << n1 << " + " << n2 << " = " << r << std::endl;

        if(carry==1) {
            r = r + 1;
            carry=0;
        }
        if(r < B) {
            if(r <= 9) {
                sr.push(r);
            }
            else {
                sr.push(r);
            }
        }
        else if(r >= B) {
            carry=1;
            r=r-B;

            sr.push(r);
        }
    }

    std::cout << "La suma es: ";
    sr.write(std::cout);
    std::cout << std::endl;
   
    return sr;
}

template <size_t N, size_t B, typename T>
number<N, B, T> number<N, B, T>::resta(const number<N,B,T> &s) const {

    number<N,B,T> sr;
    int n1=0, n2=0, r=0, c;
    bool carry = false;
    T a;
    std::stringstream saux;

    for(int i=0; i < N; i++) {
        r = 0;

        n1=get_n(i);
        n2=s.get_n(i);

        r=n1-n2;
        std::cout << n1 << " - " << n2 << " = " << r << std::endl;

        if(carry==1) {
            r = r - 1;
            carry=0;
        }

        if(r < B) {
            if(r <= 9) {
                sr.push(r);
            }
            else {
               // char caux='A' + r - 10;
                //std::cout << "caux: " << caux << std::endl;
                sr.push(r);
            }
        }
        else if(r >= B) {
            carry=1;
            r=r+B;

            sr.push(r);
        }
    }

    if(mayor(s)==false) {
        std::cout << "La resta es: ";
        sr.write(std::cout);
        std::cout << std::endl;
    }
    else
        std::cout << "No se puede realizar la resta\n" << std::endl;

    return sr;    
}

template <size_t N, size_t B, typename T>
void number<N, B, T>::push(int n) {

    char a;
    
    if(n > 9){
        a = 'A' + n - 10;
        //   std::cout << "elemento insertado: " << a << '\n';        
        d_.push_back(a);
    }
    else{
        std::stringstream saux;
        saux << n;
        saux >> a;
        d_.push_back(a);
    }
}

template <size_t N, size_t B, typename T>
int number<N, B, T>::get_n(int i) const {

    char a=d_[i];
    int n;

    if(a >= 64) {
        n = a - 65 + 10;
    }
    else {
        std::stringstream saux;
        saux << a;
        saux >> n;
    }

    return n;
}


template <size_t N, size_t B, typename T>
void number<N, B, T>::same(const number<N,B,T> &s) const {

    int n1=0, n2=0, cont=0;

    for(int i=0; i < N; i++) {
        n1=get_n(i);
        n2=s.get_n(i);

        if(n1==n2) 
            cont++;
    }
            
    if(cont==N)
        std::cout << "Los numeros son iguales" << std::endl;
    else 
        std::cout << "Son diferentes" << std::endl;
}

template <size_t N, size_t B, typename T>
bool number<N, B, T>::mayor(const number<N,B,T> &s) const {

    int n1=0, n2=0;
    bool m=false;

    for(int i=d_.size()-1; i >= 0; i--) {
        n1=get_n(i);
        n2=s.get_n(i);

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

template <size_t N, size_t B>
//void test_number(void) {
void test_number(int v1, int v2) {

    number<N, B> n(v1);
    number<N, B> n1(v2);

    n.write(std::cout);
    n1.write(std::cout);

    n.suma(n1);
    n.resta(n1);
    n.same(n1);
    n.mayor(n1);
}






