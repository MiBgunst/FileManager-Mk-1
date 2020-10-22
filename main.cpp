#include "termcolor.hpp"
#include<iostream>
#include "t_hash.hpp"
#include<list>
using namespace std;

int main() {

  cout << termcolor::on_white;
  cout << termcolor::red << "Texto Rojo" << endl;

  HashMap<double> mitabla;



  cout << termcolor::reset;
  return 0;
}
