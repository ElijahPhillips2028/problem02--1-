#include "ArrayList.hpp"

template <typename T>
ArrayList<T>::ArrayList()
{
  /*sets the size and makes a new array list & the capcity*/
  currentSize  = 0;
  capacity = 10;
  arrayList = new T[capacity];
  
  // TODO
}

template <typename T>
ArrayList<T>::~ArrayList() 
{
  // TODO
  /*make the destructor ie delete arrayList*/
delete[] arrayList;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList &x) 
{
  // TODO
  /*coppy the consuctor using x*/
  currentSize = x.currentSize;
  arrayList = new T[currentSize]; 
  /*put the old contents into the new ones*/
    for (std::size_t i = 0; i < currentSize; i++) {
    arrayList[i] = x.arrayList[i];
  }
}

template <typename T>
ArrayList<T> &ArrayList<T>::operator=(ArrayList x)
{
  // TODO (use copy swap idiom)
  swap(x);
  return *this;
}

template <typename T>
void ArrayList<T>::swap(ArrayList &x) 
{
  // TODO
  /*swaps all of them*/
  std::swap(currentSize,x.currentSize);
  std::swap(capacity,x.capacity);
  std::swap(arrayList,x.arrayList);
}

template <typename T>
bool ArrayList<T>::isEmpty() const noexcept
{
  // TODO
  if(currentSize <= 0){
    return false;
  }
  return true;
}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept
{
  // TODO
  return currentSize;
}

template <typename T>
void ArrayList<T>::insert(std::size_t position, const T &item)
{
  // TODO
  /*check if its legal to insert there*/
  currentSize = position;
  if(position > currentSize || position < 0 ){
    return ;
  }

  for(int z =capacity; z < currentSize;z++ ){
    capacity = z;
  }
  /*go down the array untill we reach the correct item and shift everythign to the right*/

  for(int i=currentSize; i > position; i--){
    arrayList[i] = arrayList[i-1];
  }
  arrayList[position] = item;
  currentSize++;
  return ;
}

template <typename T>
void ArrayList<T>::remove(std::size_t position)
{
  // TODO
   if(position > currentSize || position < 0 ){
    return ;
  }
  /*go through the array list and shift everything to the left by one untill we get to the position then stop*/
   for(int i=currentSize; i > position; i--){
    arrayList[i] = arrayList[i+1];
  }
  /*subtract one off the current size*/
  currentSize--;
  return ;
}

template <typename T>
void ArrayList<T>::clear() 
{
  currentSize = 0;
  // TODO
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const
{
  // TODO
  T entryItem = arrayList[position];
  return entryItem;
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T &newValue) 
{
  // TODO
  if(position > currentSize || position < 0 ){
    return ;
  }
  arrayList[position] = newValue;
  return ;
}
