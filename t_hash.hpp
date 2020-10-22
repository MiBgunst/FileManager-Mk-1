#ifndef t_hash_hpp
#define t_hash_hpp
#include <string>
using namespace std;

const int TABLE_SIZE = 1013;

template<typename VT>
struct KeyValueNode {
  string key;
  VT value;
  KeyValueNode<VT> *next;
};

template<typename VT>
class HashMap{

  // pointer to pointers to buckets
  KeyValueNode<VT> **table;

  int tablesize; // size of the pointer table
  int count; // number of elements in table

  // default value to return when search fails
  VT notfound;


 // search for key " key" inside the bucket at index
 // " index " of the table
 // return the element if found , or nullptr otherwise
 // KeyValueNode < VT >* search_bucket (int index , string key ); //ya definido en el cpp

 //hash function
 unsigned int hash(string key){
   unsigned int hashval = 0;
   for (char ch : key) hashval += ch;
   return hashval % tablesize;
 }

public:
  //Constructors
  HashMap();
  //HashMap(VT def);
  //~HashMap(); //Destructor

  int size () ; // return no. of elements
  bool empty () ; // true if there are no elements
  void clear () ; // delete all elements

  // chained hash search : search for elem with key = key
  VT get ( string key ) ;

  // return true if key is in table
  bool search ( string key ) ;

  // chained hash insert : insert at the head of bucket
  void insert ( string key , VT value ) ;

  // chained hash remove : remove element with key = key
  void remove ( string key ) ;

  // print no. of elems in each bucket to a file filename
  void distribution ( const string & filename ) ;
  KeyValueNode < VT >* search_bucket (int index , string key );

};


#include "t_hash.cpp"

#endif /* t_hash_hpp */
