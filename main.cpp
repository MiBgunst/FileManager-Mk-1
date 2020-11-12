#include "termcolor.hpp"
#include<iostream>
#include<ostream>
#include "th_files.hpp"
//#include "th_users.hpp"
using namespace std;

int main() {
  cout<<boolalpha<<endl;
  cout << termcolor::on_white;
  cout << termcolor::red<<endl;


  th_files<double> mitabla;
  cout << "mi tabla size: "<<mitabla.size()<<endl;

  cout << "mi tabla is empty? "<<mitabla.empty()<<endl;
  cout<<"insertando..."<<endl;
  mitabla.insert("hola",7);
  mitabla.insert("pepe",4);
  mitabla.insert("jnvoa",21);
  cout<<endl;
  cout<<"buscando..."<<endl;
  cout<<mitabla.search("pepe");
  cout<<endl;
  cout<<"display"<<endl;
  mitabla.display();

  cout<<endl;
  cout<<"bucando..."<<endl;
  cout<<"Para el key 'jnvoa', el valor es: "<<mitabla.get("jnvoa")<<endl;

  cout<<"¿El key 'ur' está en la tabla? "<<mitabla.get("ur")<<endl;

  cout<<endl;
  cout<<"borrando..."<<endl;

  mitabla.remove("perro");
  mitabla.remove("hola");
  mitabla.display();


  cout << termcolor::reset<<endl;
  cout<<endl;
  return 0;
}
