#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <tchar.h>

using namespace std;

int main() {
  string passAdmin, contenido,line;
  cout<<"ingrese la contrase\244a de Admin para administrar los usuarios "<<endl;
  cin>>passAdmin;

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

    cout<<contenido<<endl; // imprime en pantalla  lo modificado
    fstemp << contenido << endl;
  }

  //reemplazar un archivo por otro
  fs.close();
  fstemp.close();
  remove("no_abrir.txt");                    // borrar el original
  rename("no_abrir0.txt", "no_abrir.bat");  // renombrar el temporal por un .bat

  //siguiendo la logica que usaste en el resto
  cout << "El archivo ha sido modificado correctamente" << endl;
  // revisen como hacer esta liea universal para que con solo el nombre lo ubique y lo ejecute
  ShellExecute(NULL, ("open"), ("C:/Users/gianc/Music/proyecto_algoritmos/no_abrir.bat"), NULL, NULL, SW_NORMAL); // ruta (unica en mi caso) para ejecutar el .bat





  return 0;
}
