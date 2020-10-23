#ifdef th_files_hpp



template<typename F>
th_files<F>::th_files(){
  tablesize_files = TABLE_FILES_SIZE;
  count_files = 0;
  notfound = F(99999999999999);
  table_files = new KeyValueFiles<F>*[tablesize_files];

  for(int i = 0; i < tablesize_files; i++ ) table_files[i] = nullptr;
}

template<typename F>
KeyValueFiles<F> * th_files<F>::search_bucket(int index, string key){
  KeyValueFiles<F> *cp = table_files[index];
  while (cp != nullptr && key != cp->key) cp = cp->next;
  return cp;
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



#endif /* th_files_hpp */
