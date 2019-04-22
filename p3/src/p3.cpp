#include <iostream>
#include <string>
#include <sstream>
#include "calculator.hpp"
#include "number.hpp"
#include "numberbase.hpp"

using namespace std;

int main() {

  string expr_str( "5 4 + 1 -");
  istringstream expresion(expr_str);

  cout << expr_str << " =\n" << calculador< number<4,10,char> >(expresion) << endl;

  expresion.seekg(0, expresion.beg);
  cout << expr_str << " =\n" << calculador< number<8,2,char> >(expresion) << endl;

  expresion.seekg(0, expresion.beg);
  cout << expr_str << " =\n" << calculador< number<4,8,char> >(expresion) << endl;

  cout << "Postfix expresion = " << calculador< number<4,16,char> >(cin) << endl;

  return 0;
}
