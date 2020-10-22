#ifdef t_hash_hpp



template<typename VT>
HashMap<VT>::HashMap(){
  tablesize = TABLE_SIZE;
  count = 0;
  notfound = VT(99999999999999);
  table = new KeyValueNode<VT>*[tablesize];

  for(int i = 0; i < tablesize; i++ ) table[i] = nullptr;
}

template<typename VT>
KeyValueNode<VT> * HashMap<VT>::search_bucket(int index, string key){
  KeyValueNode< VT > *cp = table[index];
  while (cp != nullptr && key != cp->key) cp = cp->next;
  return cp;
}

template<typename VT>
void HashMap<VT>::insert(string key , VT value){
  int bucket = hash(key);
  KeyValueNode<VT> *cp = search_bucket(bucket, key);

  if (cp == nullptr){
      cp = new KeyValueNode<VT>;
      cp->key = key;
      cp->next = table[bucket];
      table[bucket] = cp;
      count++;
    }
  cp->value = value;
}



#endif /* t_hash_hpp */
