#ifndef t_hash_hpp
#define t_hash_hpp
#include <string>

using namespace std;

const int TABLE_FILES_SIZE = 3;

template<typename F>
struct KeyValueFiles {
  string key;
  F value;
  KeyValueFiles<F> *next;
};

template<typename F>
class th_files{

  // pointer to pointers to buckets
  KeyValueFiles<F> **table_files;

  int tablesize_files; // size of the pointer table
  int count_files; // number of elements in table
  string nameTU; // table name
  // default value to return when search fails
  F notfound;

  KeyValueFiles<F>* search_bucket (int index , string key ); //ya definido en el cpp


 //hash function
 unsigned int hash_files(string key){
  unsigned int hashval = 0;
  for (char ch : key) hashval += ch;
  return hashval % tablesize_files;
}

  //rehash
  void rehash(string usuario);

public:
  //Constructor
  th_files();

  //Destructor
  ~th_files();

  //size
  int size () ;

  //empty
  bool empty () ;

  //clear
  void clear () ;

  //get para datos cortos
  void get ( string key ) ;

  //search
  bool search ( string key ) ;

  //insert
  void insert ( string key , F value,string usuarioA ) ;

  // // chained hash remove : remove element with key = key
  void removeFL ( string key,string usuarioA ) ;

  // abre el archivo  que requiere el usuario
  void open_file (string key,string usuarioA);

  //display
  void display() const;




};

#include "t_hash.cpp"

#endif /* t_hash_hpp */
