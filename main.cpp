#include "termcolor.hpp"
#include<iostream>
#include "th_files.hpp"
#include "th_users.hpp"
using namespace std;

int main() {
  cout<<boolalpha<<endl;
  cout << termcolor::on_white;
  cout << termcolor::red << "Texto Rojo" << endl;

  th_files<double> mitabla;
  cout << "mi tabla size: "<<mitabla.size()<<endl;

  cout << "mi tabla is empty? "<<mitabla.empty()<<endl;


  cout << termcolor::reset<<endl;
  return 0;
}
