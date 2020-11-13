#include "termcolor.hpp"
#include<iostream>
#include<ostream>
#include "th_files.hpp"
using namespace std;


int main() {



  //mensaje de bienvenida
  cout<<"Bienvenido usuario"<<endl;
  cout<<"Este programa le permitirá tener privacidad en sus archivos y encontrarlos de la forma más rápida posbile"<<endl;
  cout<<endl;

  //se le ofrece al usuario la oportunidad de seleccionar el color de fondo y color de letra
  cout<<"Para hacer su experiencia más agradable, es posible cambiar el color de la letra y el color de fondo."<<endl;

  //se ofrecen las opciones de color de letra
  cout<<"Las opciones de color para la letra son: "<<endl;

  cout<<"Para blanco, presione 1"<<endl;
  cout<<"Para azul, presione 2"<<endl;
  cout<<"Para verde, presione 3"<<endl;
  cout<<"Para gris, presione 4"<<endl;
  cout<<"Para rojo, presione 5"<<endl;
  cout<<"Para amarillo, presione 6"<<endl;
  cout<<"Para magenta, presione 7"<<endl;
  cout<<"Para cyan, presione 8"<<endl;
  cout<<"Para seguir con el color defecto, presione 0"<<endl;

  int color_letra = 0;
  cin>>color_letra;

  switch (color_letra) {
      // case 0:
      // break;


      case 1: cout << termcolor::white;
      break;

      case 2: cout << termcolor::blue;
      break;

      case 3: cout << termcolor::green;
      break;

      case 4: cout << termcolor::grey;
      break;

      case 5: cout << termcolor::red;
      break;

      case 6: cout << termcolor::yellow;
      break;

      case 7: cout << termcolor::magenta;
      break;

      case 8: cout << termcolor::cyan;
      break;

      default: cout<<"sin cambios"<<endl;
      break;
  }
  cout<<endl;


  //se ofrecen las opciones de color de fondo
  cout<<"Las opciones de color para el fondo son: "<<endl;
  cout<<"Para blanco, presione 1"<<endl;
  cout<<"Para azul, presione 2"<<endl;
  cout<<"Para verde, presione 3"<<endl;
  cout<<"Para gris, presione 4"<<endl;
  cout<<"Para rojo, presione 5"<<endl;
  cout<<"Para amarillo, presione 6"<<endl;
  cout<<"Para magenta, presione 7"<<endl;
  cout<<"Para cyan, presione 8"<<endl;
  cout<<"Para seguir con el color defecto, presione 0"<<endl;
  int color_fondo = 0;
  cin>>color_fondo;

  switch (color_fondo) {
      default: {cout<<"sin cambios" <<endl;}
      break;

      case 1: cout << termcolor::on_white;
      break;

      case 2: cout << termcolor::on_blue;
      break;

      case 3: cout << termcolor::on_green;
      break;

      case 4: cout << termcolor::on_grey;
      break;

      case 5: cout << termcolor::on_red;
      break;

      case 6: cout << termcolor::on_yellow;
      break;

      case 7: cout << termcolor::on_magenta;
      break;

      case 8: cout << termcolor::on_cyan;
      break;



  }
  cout<<endl;


  cout<<"funciona?"<<endl;

  //sistema de autenticación de usuarios
  cout<<"Presione 1 para ingresar con un usuario ya creado\n";
  cout<<"Presione 2 para crear un usuario"<<endl;
  cout<<"Presione 3 para ingresar siendo administrador"<<endl;
  int autentica = 0;
  cin>>autentica;

  switch (autentica) {

      case 1: //dar paso a la creación del usuario
      break;

      case 2: //dar paso a autenticación de usuario
      break;

      case 3: //ingresar como administrador
      break;

  }

  //
  // th_files<double> mitabla;
  // cout << "mi tabla size: "<<mitabla.size()<<endl;
  //
  // cout << "mi tabla is empty? "<<mitabla.empty()<<endl;
  // cout<<"insertando..."<<endl;
  // mitabla.insert("hola",7);
  // mitabla.insert("pepe",4);
  // mitabla.insert("jnvoa",21);
  // cout<<endl;
  // cout<<"buscando..."<<endl;
  // cout<<mitabla.search("pepe");
  // cout<<endl;
  // cout<<"display"<<endl;
  // mitabla.display();
  //
  // cout<<endl;
  // cout<<"bucando..."<<endl;
  // cout<<"Para el key 'jnvoa', el valor es: "<<mitabla.get("jnvoa")<<endl;
  //
  // cout<<"¿El key 'ur' está en la tabla? "<<mitabla.get("ur")<<endl;
  //
  // cout<<endl;
  // cout<<"borrando..."<<endl;
  //
  // mitabla.remove("perro");
  // mitabla.remove("hola");
  // mitabla.display();


  cout << termcolor::reset<<endl;
  cout<<endl;
  return 0;
}
