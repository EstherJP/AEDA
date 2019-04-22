#include <iostream>
#include "number.hpp"

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
        test_number<4,2>(v1,v2);
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
