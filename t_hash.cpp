#ifdef t_hash_hpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>

//Constructor
template<typename F>
th_files<F>::th_files(){
  tablesize_files = TABLE_FILES_SIZE;
  count_files = 0;
  notfound = F("Not found");
  nameTU="None";
  table_files = new KeyValueFiles<F>*[tablesize_files];
  for(int i = 0; i < tablesize_files; i++ ) table_files[i] = nullptr;

}

//Destructor
template<typename F>
th_files<F>::~th_files(){
  KeyValueFiles<F> *tmp;
      for(int i = 0; i < tablesize_files; ++i){
        tmp = table_files[i];
        while(tmp != nullptr){
          table_files[i] = table_files[i]->next;
          delete tmp;
          tmp = table_files[i];
        }
      }
      delete[] table_files;
}

//serarch privado
template<typename F>
KeyValueFiles<F> * th_files<F>::search_bucket(int index, string key){
  KeyValueFiles<F> *cp = table_files[index];
  while (cp != nullptr && key != cp->key) cp = cp->next;
  return cp;
}

//search public
template<typename F>
bool th_files<F>::search(string key){

    int bucket = hash_files(key);

    return search_bucket(bucket, key) != nullptr;
}

//insert
template<typename F>
void th_files<F>::insert(string key , F value, string usuarioA){
  if(count_files==tablesize_files) rehash(usuarioA);
  int bucket = hash_files(key);
  KeyValueFiles<F> *cp = search_bucket(bucket, key);
  string valueF=value;
  if (cp == nullptr){
      cp = new KeyValueFiles<F>;
      cp->key = key;
      cp->next = table_files[bucket];
      table_files[bucket] = cp;
      count_files++;
    }
  cp->value = value;
  ofstream file;
  string aux0 = "C:/Users/Ángel/desktop/aed/";
  string aux1 = aux0+usuarioA+"_tabla/";
  string aux2 = aux1+key+".txt";
  file.open(aux2);
  file << "Ingrese su texto\n";
  file<<valueF<<endl;
  file.close();
}

//rehash
template <typename F>
void th_files<F>::rehash(string usuarioA) {
    int size= tablesize_files;
    KeyValueFiles<F> ** old_table = table_files;
    tablesize_files = tablesize_files*2;
    table_files = new KeyValueFiles<F>*[tablesize_files];
    for (int k=0; k<tablesize_files; k++) table_files[k]=nullptr;
    count_files=0;

    KeyValueFiles<F> * temp;
    for(int q=0; q<size; q++){
        temp = old_table[q];
        while(old_table[q] != nullptr){
            string key = temp->key;
            F value = temp->value;
            insert(key,value,usuarioA);
            temp = temp->next;
            delete old_table[q];
            old_table[q] = temp;
        }
    }

}

//size
template<typename F>
int th_files<F>::size(){
  return count_files;
}

//empty
template<typename F>
bool th_files<F>::empty(){
  return count_files == 0;
}


// display
template<typename F>
void th_files<F>::display()const{
  int auxm=0;
  cout<<"Hash Table users, n = "<<tablesize_files<<" m = "<<count_files<<endl;
  for( int i = 0; i<tablesize_files;i++){
    KeyValueFiles< F > *cp = table_files[i];
    cout<<"bucket: "<<i<<" --> ";
    while(cp!=nullptr){
      cout<<"("<<cp->key<<","<<cp->value<<") --> ";
      cp=cp->next;
      auxm++;
    }
    cout<<"//"<<endl;
    if(auxm==count_files) break;
  }
}

//get
template<typename F>
void th_files<F>::get(string key){

  int bucket = hash_files(key);
  KeyValueFiles<F> *cp = search_bucket(bucket, key);
  if (cp == nullptr){
    cout<<"No se encuentra "<<key<<" en la tabla"<<endl;
  }
  else  cout<<cp->value<<endl;

}

//remove
template <typename F>
void th_files<F>::removeFL(string key,string usuarioA) {
  unsigned int bucket = hash_files(key);
  KeyValueFiles<F>* tmp = table_files[bucket];
  string aux0 = "C:/Users/Ángel/desktop/aed/";
  string aux1 = aux0+usuarioA+"_tabla/";
  string aux2 = aux1+key+".txt";
  LPCTSTR aux3 = aux2.c_str();
  remove(aux3);
  if(tmp != nullptr){
    if(tmp->key == key){
      table_files[bucket] = tmp->next;
      delete tmp;
      count_files--;
    }else{
      while(true){
	KeyValueFiles<F>* nxt = tmp->next;
	if(nxt != nullptr && nxt->key == key){
	  tmp->next = nxt->next;
	  delete nxt;
	  count_files--;
	  break;
	}else

    	cout<<"La llave no fue encontrada en  la taba"<<endl;
	tmp = nxt;
      }
    }
  }else
    cout<<"La llave no fue encontrada en  la taba"<<endl;
}

//open file
template <typename F>
void th_files <F>::open_file(string key,string usuarioA){
  bool aux = search(key);
  string aux0 = "C:/Users/Ángel/desktop/aed/";
  string aux1 = aux0+usuarioA+"_tabla/";
  string aux2 = aux1+key+".txt";
  LPCTSTR aux3 = aux2.c_str();
  if(aux == true){
      ShellExecute(NULL, ("open"), (aux3), NULL, NULL, SW_NORMAL);
  }else{
    cout<<"el archivo "<<key<<"no existe en su usuario"<<endl;
  }
}
#endif /* t_hash_hpp */

//=============================================================================================================================================================================================================================================
// FUNCIONES PARA EL PROGRAMA
//=============================================================================================================================================================================================================================================
