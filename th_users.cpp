#ifdef th_users_hpp
//Constructor
template<typename U>
th_users<U>::th_users(){
  tablesize_users = TABLE_USERS_SIZE;
  count_users = 0;
  notfound = U(99999999999999);
  table_users = new Users<U>*[tablesize_users];

  for(int i = 0; i < tablesize_users; i++ ) table_users[i] = nullptr;
}





#endif /* th_users_hpp */
