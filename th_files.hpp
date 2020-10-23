#ifndef th_files_hpp
#define th_files_hpp
#include <string>
using namespace std;

const int TABLE_FILES_SIZE = 1013;

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

  // default value to return when search fails
  F notfound;


 // search for key " key" inside the bucket at index
 // " index " of the table
 // return the element if found , or nullptr otherwise
 KeyValueFiles<F>* search_bucket (int index , string key ); //ya definido en el cpp

 //hash function
 unsigned int hash_files(string key){
   unsigned int hashval = 0;
   for (char ch : key) hashval += ch;
   return hashval % tablesize_files;
 }

public:
  //Constructors
  th_files();
  //HashMap(VT def);
  //~HashMap(); //Destructor

  int size () ; // return no. of elements
  bool empty () ; // true if there are no elements
  void clear () ; // delete all elements

  // // chained hash search : search for elem with key = key
  // VT get ( string key ) ;
  //
  // // return true if key is in table
  // bool search ( string key ) ;
  //
  // // chained hash insert : insert at the head of bucket
  void insert ( string key , F value ) ;
  //
  // // chained hash remove : remove element with key = key
  // void remove ( string key ) ;
  //
  // // print no. of elems in each bucket to a file filename
  // void distribution ( const string & filename ) ;


};


#include "th_files.cpp"

#endif /* t_hash_hpp */
