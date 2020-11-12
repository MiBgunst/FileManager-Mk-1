#ifdef th_files_hpp



template<typename F>
th_files<F>::th_files(){
  tablesize_files = TABLE_FILES_SIZE;
  count_files = 0;
  notfound = F(999999999999);
  table_files = new KeyValueFiles<F>*[tablesize_files];

  for(int i = 0; i < tablesize_files; i++ ) table_files[i] = nullptr;
}
//Destructor
template<typename F>
th_files<F>::~th_files(){
  for(int i = 0; i < tablesize_files; i++ ) delete table_files[i] ;
}

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

template<typename F>
void th_files<F>::insert(string key , F value){
  int bucket = hash_files(key);
  KeyValueFiles<F> *cp = search_bucket(bucket, key);

  if (cp == nullptr){
      cp = new KeyValueFiles<F>;
      cp->key = key;
      cp->next = table_files[bucket];
      table_files[bucket] = cp;
      count_files++;
    }
  cp->value = value;
}

template<typename F>
int th_files<F>::size(){
  return count_files;
}

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
F th_files<F>::get(string key){

  int bucket = hash_files(key);
  KeyValueFiles<F> *cp = search_bucket(bucket, key);
  if (cp == nullptr) return 0;
  else return cp->value;

}

//remove
template <typename F>
void th_files<F>::remove(string key) {
  unsigned int bucket = hash_files(key);
  KeyValueFiles<F>* tmp = table_files[bucket];
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



#endif /* th_files_hpp */
