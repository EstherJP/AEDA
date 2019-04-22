#include <iostream>
#include "number.hpp"
#include "number_exception.hpp"

int main(void){
    try {
        int o, base;
        int v1,v2;

        numberbase *a, *b, *s;

        std::cout << "Introduzca el primer num: ";
        std::cin >> v1;
        std::cout << std::endl;
        std::cout << "Introduzca el segundo num: ";
        std::cin >> v2;
        std::cout << std::endl;

        std::cout << "***MENU***" << std::endl;
        std::cout << "2.-Base binaria" << std::endl;
        std::cout << "8.-Base octal" << std::endl;
        std::cout << "10.-Base decimal" << std::endl;
        std::cout << "16.-Base hextadecimal" << std::endl;
        std::cout << "0.-Otra base no puedes jeje" << std::endl;

        std::cout << "Introduzca la base: ";
        std::cin >> base;
        std::cout << std::endl;

        switch(base) {
            case 2: 
                a=new BinaryNumber(v1);
                b= new BinaryNumber(v2);
                std::cout << "La suma es: \n";
                std::cout << a;
                std::cout << b;
                std::cout << "_________________\n";
                std::cout << ((*a)+b);
                std::cout << "\nLa resta es: \n";
                std::cout << ((*a)-b);
                break;
            case 8:
                a=new OctalNumber(v1);
                b=new OctalNumber(v2);
            std::cout << "La suma es: \n";
                std::cout << a;
                std::cout << b;
                std::cout << "_________________\n";
                std::cout << ((*a)+b);
                std::cout << "\nLa resta es: \n";
                std::cout << ((*a)-b);
                break;
            case 10:
                a=new DecimalNumber(v1);
                b=new DecimalNumber(v2);
                std::cout << "La suma es: \n";
                // a->write(std::cout);
                // b->write(std::cout);
                std::cout << a;
                std::cout << b;
                std::cout << "_________________\n";
                std::cout << ((*a)+b) << std::endl;
                std::cout << "\nLa resta es: \n";
                std::cout << ((*a)-b);
                break;
            case 16:
                a=new HexaNumber(v1);
                b=new HexaNumber(v2);
                std::cout << "La suma es: \n";
                std::cout << a;
                std::cout << b;
                std::cout << "_________________\n";
                std::cout << ((*a)+b);
                std::cout << "\nLa resta es: \n";
                std::cout << ((*a)-b);
                break;
            default:
                std::cout << "Te dije que otra base no podías\n";
        }   
        /* 
            delete a;
            delete b;
            delete s;
            */
    }
    catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
