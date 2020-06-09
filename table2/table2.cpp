#include <iostream>
#include<cassert>
#include<string>
 #include "table2.h"
 #include "node2.h"

using namespace std;

namespace main_savitch_12B{

template< class RecordType>
table<RecordType>::table(){
  total_records = 0;
  for(int i =0; i < TABLE_SIZE; i++){
    data[i] = NULL;
  }
}


template< class RecordType>
table<RecordType>::table(const table& source){
  main_savitch_6B::node<RecordType> *tail;
  for(int i =0; i < TABLE_SIZE; i++){
    list_copy(source.data[i], data[i], tail);
  }
  this->total_records = source.total_records;
}

template< class RecordType>
table<RecordType>::~table(){
  for(int i =0; i < TABLE_SIZE; i++){
    list_clear(data[i]);
  }
}

template <class RecordType>
void table<RecordType>::insert(const RecordType& entry)
{
    if(is_present(entry) == false)
    {
        main_savitch_6B::node<RecordType> *cursor = data[hash(entry)];
        if(cursor == NULL)
        {
            cursor = data[hash(entry)] = new main_savitch_6B::node<RecordType>;
            cursor->data = entry;
            cursor->link = NULL;
        }
        else
        {
            while(cursor->link != NULL && cursor->data.key != entry)
            {
                cursor = cursor->link;
            }

            cursor->link = new main_savitch_6B::node<RecordType>;
            cursor = cursor->link;
            cursor->link = NULL;
            cursor->data = entry;
        }

        total_records++;
    }
}
template <class RecordType>
void table<RecordType>::remove(int key){
  main_savitch_6B::node<RecordType> *head = data[hash(key)],
                   *precursor = NULL;
  bool find = false;
  while(head!=NULL){
    if(head->data.key==key){
      find = true;
      break;
    }
    precursor = head;
    head = head->link;
  }
  if(find == true){
    list_remove(precursor);
    total_records--;
  }
}
template <class RecordType>
void table<RecordType>::operator=(const table& source){
  if(this == &source){
    return;
  }
  total_records = source.total_records;
  for(int i  = 0; i < TABLE_SIZE; i++){
    data[i] = source.data[i];
  }
}
template <class RecordType>
void table<RecordType>::find(int key, bool& found, RecordType& result) const{
main_savitch_6B::node<RecordType> *head = data[hash(key)];
  found  = false;
  while(head!=NULL&&head->data.key!=key){
    if(head->data.key==key){
      found  = true;
      result = head->data;
      break;
    }
    head = head->link;

  }
}
template <class RecordType>
bool table<RecordType>::is_present(int key) const{
main_savitch_6B::node<RecordType> *head = data[hash(key)];
  bool found  = false;
  while(head!=NULL){
    if(head->data.key==key){
      found = true;
      break;
    }
    head=head->link;
  }
  return found;
}
template<class RecordType>
size_t table<RecordType>::hash(int key) const{
        return (key % TABLE_SIZE);
    }

}
