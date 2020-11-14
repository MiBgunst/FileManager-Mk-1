#include "termcolor.hpp"
#include<iostream>
#include<ostream>
//#include "th_files.hpp"
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


  cout<<"Para azul, presione 1"<<endl;
  cout<<"Para verde, presione 2"<<endl;
  cout<<"Para gris, presione 3"<<endl;
  cout<<"Para rojo, presione 4"<<endl;
  cout<<"Para amarillo, presione 5"<<endl;
  cout<<"Para magenta, presione 6"<<endl;
  cout<<"Para cyan, presione 7"<<endl;
  cout<<"Para seguir con el color defecto, presione 0"<<endl;

  int color_letra = 0;

  bool col=false;
  while(col==false){

      cin>>color_letra;

      if(color_letra==0){
          cout << termcolor::white;
          col=true;
      }
      else if(color_letra==1) {
          cout << termcolor::blue;
          col=true;
      }
      else if(color_letra==2) {
          cout << termcolor::green;
          col=true;
      }
      else if(color_letra==3) {
          cout << termcolor::grey;
          col=true;
      }
      else if(color_letra==4) {
          cout << termcolor::red;
          col=true;
      }
      else if(color_letra==5) {
          cout << termcolor::yellow;
          col=true;
      }
      else if(color_letra==6) {
          cout << termcolor::magenta;
          col=true;
      }
      else if(color_letra==7) {
          cout << termcolor::cyan;
          col=true;
      }
      else{
          cout<<"La opción ingresada no es correcta"<<endl;
          col=false;
      }

  }

  //se ofrecen las opciones de color de fondo
  cout<<"Las opciones de color para la letra son: "<<endl;


  cout<<"Para azul, presione 1"<<endl;
  cout<<"Para verde, presione 2"<<endl;
  cout<<"Para blanco, presione 3"<<endl;
  cout<<"Para rojo, presione 4"<<endl;
  cout<<"Para amarillo, presione 5"<<endl;
  cout<<"Para magenta, presione 6"<<endl;
  cout<<"Para cyan, presione 7"<<endl;
  cout<<"Para seguir con el color defecto, presione 0"<<endl;

  int color_fondo = 0;

  bool col_f=false;
  while(col_f==false){

      cin>>color_fondo;

      if(color_fondo==0){
          cout << termcolor::on_grey;
          col_f=true;
      }
      else if(color_fondo==1) {
          cout << termcolor::on_blue;
          col_f=true;
      }
      else if(color_fondo==2) {
          cout << termcolor::on_green;
          col_f=true;
      }
      else if(color_fondo==3) {
          cout << termcolor::on_white;
          col_f=true;
      }
      else if(color_fondo==4) {
          cout << termcolor::on_red;
          col_f=true;
      }
      else if(color_fondo==5) {
          cout << termcolor::on_yellow;
          col_f=true;
      }
      else if(color_fondo==6) {
          cout << termcolor::on_magenta;
          col_f=true;
      }
      else if(color_fondo==7) {
          cout << termcolor::on_cyan;
          col_f=true;
      }
      else{
          cout<<"La opción ingresada no es correcta"<<endl;
          col_f=false;
      }

  }


  cout<<"POR FAVOOOOOOOR QUE FUNCIONEEEE!!"<<endl;




  cout << termcolor::reset<<endl;
  cout<<endl;
  return 0;
}
