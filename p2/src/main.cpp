#include <iostream>
#include "number.hpp"
#include "binary.hpp"
#include "number_exception.hpp"

template <int N, int B>
//void test_number(void) {
void test_number(int v1, int v2) {

    number<N, B> n(v1);
    number<N, B>cn(n);

    number<N, B> n1(v2);
    number<N, B>cn1(n1);
    number<N,B> r; 


    try {

        n.write(std::cout);
        n1.write(std::cout);

        // std::cout << std::endl;

     //   number<N,B> r; 
        r=n+n1;
        // std::cout << "La suma es: ";
        r.write(std::cout);
        // std::cout << std::endl;

        // // r=n-n1;
        // // std::cout << "La resta es: ";
        // // r.write(std::cout);
        // // std::cout << std::endl;
    
    } catch(std::exception& e) {
        // std::cout << "Hay un overflow en el resultado\n";
        std::cout << e.what() << std::endl;
        // std::cout << "EL resultado es: ";
        // ((number<N+1,B>) n + (number<N+1,B>) n1).write(std::cout);
        // std::cout << std::endl;

        
    }
        //n.suma(n1).write(std::cout);
        //n.resta(n1).write(std::cout);
        //n.same(n1);
        //n.mayor(n1);
}

template <int N, int B>
//void test_number(void) {
void test_number2(int v1, int v2) {

    number<N,2> r; 

    number<N, 2> n(v1);
    number<N, 2>cn(n);

    number<N, 2> n1(v2);
    number<N, 2>cn1(n1);

    n.write(std::cout);
    n1.write(std::cout); 

    // std::cout << std::endl;

    r=n+n1;
   // (n+n1).write(std::cout);
    r.write(std::cout);

   // n.suma(n1).write(std::cout);
    //n.resta(n1).write(std::cout);
    //n.same(n1);
    //n.mayor(n1);
}

int main(void){
    int o, b;

    int v1,v2;

    std::cout << "Introduzca el primer num: ";
    std::cin >> v1;
    std::cout << std::endl;
    std::cout << "Introduzca el segundo num: ";
    std::cin >> v2;
    std::cout << std::endl;

    std::cout << "***MENU***" << std::endl;
    std::cout << "2.-Base binaria" << std::endl;
    std::cout << "10.-Base decimal" << std::endl;
    std::cout << "16.-Base hextadecimal" << std::endl;
    std::cout << "0.-Otra base no puedes jeje" << std::endl;

    std::cin >> o;

    if(o==2) {
        std::cout << "---Binario---" << std::endl;
        test_number2<4,2>(v1,v2);
    }

    else if(o==10) {
        std::cout << "---Decimal---" << std::endl;
        test_number<4,10>(v1,v2);
    }

    else if(o==16) {
        std::cout << "---Hexadecimal---" << std::endl;
        test_number<4,16>(v1,v2);
    }

    // else if(o==0) {
    //     std::cout << "Introduzca una base";
    //     std::cin >> b;
    //     std::cout << std::endl;

    //     std::cout << "---Base " << b << "---" << std::endl;
    //     test_number<4,b>();
    // }
}
