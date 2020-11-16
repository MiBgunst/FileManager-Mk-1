#include "termcolor.hpp"
#include<iostream>
#include "th_files.hpp"
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <tchar.h>
#include<ostream>
#include <direct.h>
using namespace std;

int count_usuarios = 0;
string usuarioA, contrasenaA;
void crea_usuario(){
  if(count_usuarios == 0){
    string usuario, passAdmin,contenido,line;
    cout<<"Ingrese su nombre de usuario para ser Admin"<<endl;
    cin>>usuario;
    cout<<"Ingrese su contrase\244a"<<endl;
    cin>>passAdmin;
    count_usuarios += 1;

    ifstream fs("no_abrir.txt"); //leer de este archivo
    ofstream fstemp("no_abrir0.txt"); //escribir en este archivo
    if(!fs || !fstemp){ //no se pudo abrir alguno de los 2
      cout << "Error al abrir el archivo!" << endl;
      exit(1);
    }
    //modificar linea a linea
    while(! fs . eof ()){
      getline ( fs , contenido );
      for(unsigned i =0;i<contenido.size();i++ ){
        char j = contenido[i];
        if(j == '*'){  //se encontro
            contenido = passAdmin+" goto FAIL"; //reemplazar
          }
      }
      fstemp << contenido << endl;
    }

    //reemplazar un archivo por otro
    fs.close();
    fstemp.close();
    remove("no_abrir.txt");                    // borrar el original
    rename("no_abrir0.txt", "no_abrir.bat");  // renombrar el temporal por un .bat

    ShellExecute(NULL, ("open"), ("C:/Users/gianc/Music/proyecto_algoritmos/no_abrir.bat"), NULL, NULL, SW_NORMAL); // ruta (unica en mi caso) para ejecutar el .bat

    cout<<"Si quiere ocultar la carpeta que administrar los usuarios (CarpetaProtegida) y constrase\244as debe hacer clic en el archivo no_abrir.bat y escribir S para esconder o su contraseña para abrirlo"<<endl;
  }else{
   string usuario1, contrasena1,contenido1;
   cout<<"Ingrese su nombre de usuario"<<endl;
   cin>>usuario1;
   cout<<"Ingrese su contraseña"<<endl;
   cin>>contrasena1;
   if(count_usuarios>1){
     ifstream fs1("C:/Users/gianc/Music/proyecto_algoritmos/CarpetaProtegida/Passwords.txt"); //leer de este archivo
     ofstream fstemp1("C:/Users/gianc/Music/proyecto_algoritmos/CarpetaProtegida/Passwords0.txt"); //escribir en este archivo
     while(! fs1 . eof ()){
       getline ( fs1 , contenido1 );
       fstemp1 << contenido1<<endl;
     }
     fstemp1 <<  usuario1+"="+contrasena1;
     fs1.close();
     fstemp1.close();
     remove("C:/Users/gianc/Music/proyecto_algoritmos/CarpetaProtegida/Passwords.txt");                    // borrar el original
     rename("C:/Users/gianc/Music/proyecto_algoritmos/CarpetaProtegida/Passwords0.txt","C:/Users/gianc/Music/proyecto_algoritmos/CarpetaProtegida/Passwords.txt" );  // renombrar el temporal por un .bat
   }else{
     ofstream file;
     file.open("C:/Users/gianc/Music/proyecto_algoritmos/CarpetaProtegida/Passwords.txt");
     file <<  usuario1+"="+contrasena1;
     file.close();
   }
   th_files<double>mytabla;
   string aux3 = usuario1+"_tabla";
   LPCTSTR aux2 = aux3.c_str();
   mkdir(aux2);
   //cout<<"el nombre de su tabala es "<<endl;

   count_usuarios += 1;
 }
}
// Autenticación usuario
bool autenticacion(){
  string cadena ,aux;
  cout<<"Bienvenido a la seccion de autenticacion"<<endl;
  cout<<"Ingrese su usuario"<<endl;
  cin>>usuarioA;
  cout<<"Ingrese su contrase\244a"<<endl;
  cin>>contrasenaA;
  aux = usuarioA+"="+contrasenaA;
  ifstream fe("C:/Users/gianc/Music/proyecto_algoritmos/CarpetaProtegida/Passwords.txt");
  while (!fe.eof()) {
    getline ( fe , cadena);
    for(unsigned i = 0;i<cadena.size();i++){
      if(cadena[i]==aux[i]){
        cout<<"Gracias por autenticarse"<<endl;
        return true;
      }
     }

    cout << cadena << endl;
  }
  fe.close();
  cout<<"Intentelo de nuevo"<<endl;
  return false;
}

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
   //cout<<"Para gris, presione 3"<<endl;
   cout<<"Para rojo, presione 3"<<endl;
   cout<<"Para amarillo, presione 4"<<endl;
   cout<<"Para magenta, presione 5"<<endl;
   cout<<"Para cyan, presione 6"<<endl;
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
           cout << termcolor::red;
           col=true;
       }
       else if(color_letra==4) {
           cout << termcolor::yellow;
           col=true;
       }
       else if(color_letra==5) {
           cout << termcolor::magenta;
           col=true;
       }
       else if(color_letra==6) {
           cout << termcolor::cyan;
           col=true;
       }
       else{
           cout<<"La opción ingresada no es correcta"<<endl;
           //col=false;
       }

   }

   //se ofrecen las opciones de color de fondo
   cout<<"Las opciones de color de fondo son: "<<endl;


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
           //col_f=false;
       }

   }


  crea_usuario();
  crea_usuario();
  crea_usuario();
  cout<<"supongamos que ya se hizo algun preceso"<<endl;
  cout<<autenticacion()<<endl;

   cout << termcolor::reset<<endl;
   cout<<endl;
}
