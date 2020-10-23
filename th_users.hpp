#ifndef th_users_hpp
#define th_users_hpp
#include <string>
using namespace std;

const int TABLE_USERS_SIZE = 1013;

template<typename U>
struct Users {
  string key;
  U value;
  Users<U> *next;
};

template<typename U>
class th_users{

  // pointer to pointers to buckets
  Users<U> **table_users;

  int tablesize_users; // size of the pointer table
  int count_users; // number of elements in table

  // default value to return when search fails
  U notfound;


 // search for key " key" inside the bucket at index
 // " index " of the table
 // return the element if found , or nullptr otherwise
 Users < U > *search_bucket (int index , string key ){
   Users< U > *cp = table_users[index];
   while (cp != nullptr && key != cp->key) cp = cp->next;
   return cp;
 };

 //hash function
 unsigned int hash_users(string key){
   unsigned int hashval = 0;
   for (char ch : key) hashval += ch;
   return hashval % tablesize_users;
 }

public:
  //Constructors
  th_users();
  //HashMap(VT def);
  //~HashMap(){}; //Destructor



};


#include "th_users.cpp"

#endif /* t_hash_hpp */
