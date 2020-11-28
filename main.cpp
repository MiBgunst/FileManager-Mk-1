#include "termocolor.hpp"
#include "t_hash.hpp"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <tchar.h>
#include<ostream>
#include <direct.h>
using namespace std;

th_files<string> mytabla;
int count_usuarios = 0;
string usuarioA, contrasenaA;
bool estadoA=false;

// FUNCION AUTENTICA
void autenticacion(){
  string cadena ,aux;
  estadoA=false;
  cout<<"Bienvenido a la seccion de autenticacion"<<endl;
  int contador=0;
  for(int i = 1;i<=3;i++){
    cout<<"Ingrese su usuario"<<endl;
    cin>>usuarioA;
    cout<<"Ingrese su contrase\244a"<<endl;
    cin>>contrasenaA;
    aux = usuarioA+"="+contrasenaA;
    ifstream fe("C:/Users/gianc/Music/proyecto_algoritmos/CarpetaProtegida/Passwords.txt");
      while (!fe.eof()) {
        getline ( fe , cadena);
          if(cadena==aux){
            cout<<"Gracias por autenticarse"<<endl;
            estadoA= true;
            break;
         }
      }

    fe.close();
    contador +=1;
    if(estadoA==true)break;
  }if(contador==3){
    cout<<"L\241mite de intentos alcanzado. Por seguridad, el sistema se cerrar\240"<<endl;
    cout<<estadoA<<endl;
    exit(1);
}
}

// FUNCION CREA USUARIO
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
   cout<<"Ingrese su contrase\244a"<<endl;
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

   //nameTU=usuario1;
   string aux3 = usuario1+"_tabla";
   LPCTSTR aux2 = aux3.c_str();
   mkdir(aux2);
   //cout<<"el nombre de su tabala es "<<nameTU<<endl;
   count_usuarios += 1;
 }
}

// FUNCION INICIO DEL PROGRAMA
void inicio(){
  cout<<"A continuaci\242n, est\240n las opciones a las que puede acceder: "<<endl;

  int user_options = 0;
  bool option = false;

  while(option == false){
    cout<<endl;
    cout<<"Para registrarse, presione 1 "<<endl; //crea_usuario
    cout<<"Para autenticarse, presione 2 (debe hacerlo antes de ejecutar las funciones que estan a continuaci\242n)"<<endl; //autenticacion
    cout<<"Para saber si su tabla est\240 vac\241a, presione 3"<<endl; //empty
    cout<<"Para ver el tama\244o de su tabla, presione 4"<<endl; //size
    cout<<"Para ver el display, presione 5"<<endl; //display
    cout<<"Para saber si un archivo a dato se encuentra en la tabla, presione 6"<<endl; //search
    cout<<"Para insertar archivos, presione 7"<<endl; //insert
    cout<<"Para abrir un archivo, presione 8"<<endl; //open_file
    cout<<"Para insertar datos cortos, presione 9"<<endl; //insert
    cout<<"Para obtener la informaci\242n de un dato corto, presione 10"<<endl; //get
    cout<<"Para eliminar un dato o archivo, presione 11"<<endl; //remove
    cout<<endl;
    cout<<"Para salir, presione 0"<<endl;
    cout<<"Por favor, elija una opci\242n: ";
    cin >> user_options;

    cout<<endl;
    if(user_options == 0){
      cout<<"Gracias por utilizar este programa." <<endl;
      break;
    }

    else if(user_options == 1)  crea_usuario();

    else if(user_options == 2)  autenticacion();

    else if(estadoA == true){
      if(user_options == 3) cout<<"Est\240 su tabla vac\241a? "<< mytabla.empty()<<endl;

      else if(user_options == 4)cout<<"El tama\244o de su tabla es: "<<mytabla.size()<<endl;

      else if(user_options == 5) mytabla.display();

      else if(user_options == 6) {
        string search;
        cout<<"Ingrese el valor del key que desea buscar: ";
        cin>> search;
        cout<<"El valor ingresado est\240 en su tabla? " << mytabla.search(search) << endl;
      }

      else if(user_options == 7){
        string insert;
        cout<<"Ingrese el valor del key que desea insertar: ";
        cin>> insert;
        string val = "";
        mytabla.insert(insert,val,usuarioA);
      }

      else if(user_options == 8){
        string file;
        cout<<"Ingrese el normbre del archivo que desea abrir: ";
        cin>> file;
        mytabla.open_file(file,usuarioA);
      }

      else if (user_options == 9){
        cout<<"Con esta opci\242n, usted puede guardar datos cortos. Claves, direcciones, fechas de cumplea\244os, etc."<<endl;
        cout<<"Por ejemplo, clave_eaulas(titulo) --> ur123(valor)"<<endl;

        string key;
        string value;
        cout<<"Por favor, ingrese el t\241tulo del dato que quiere guardar: ";
        cin>>key;
        cout<<endl;
        cout<<"Por favor ingrese el valor asignado al t\241tulo anterior: ";
        cin>>value;
        mytabla.insert(key,value,usuarioA);
      }
      else if(user_options == 10){
        string get;
        cout<<"ingrese el t\241tulo del dato almacenado: ";
        cin>>get;
        mytabla.get(get);
      }

      else if(user_options == 11){
        string elem_borrar;
        cout<<"Ingrese el título del dato guardado: ";
        cin>>elem_borrar;
        mytabla.removeFL(elem_borrar,usuarioA);
      }

      else cout<<"El valor ingresado no es correcto"<<endl;

    }
      else cout<<"El valor ingresado no es correcto"<<endl;
  }
}

//FUNCION INTERFAZ
void interfaz(){
  //mensaje de bienvenida
  cout<<"Bienvenido usuario"<<endl;
  cout<<"Este programa le permitirá tener privacidad en sus archivos y encontrarlos de la forma más rápida posbile"<<endl;
  cout<<endl;
  //se le ofrece al usuario la oportunidad de seleccionar el color de fondo y color de letra
  cout<<"Para hacer su experiencia m\240s agradable, es posible cambiar el color de la letra y el color de fondo."<<endl;

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
}

int main() {
  cout<<boolalpha;
  interfaz();
  inicio();
  cout << termcolor::reset<<endl;
  cout<<endl;
   return 0;
 }
