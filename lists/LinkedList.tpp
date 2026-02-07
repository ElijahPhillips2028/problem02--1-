#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  // TODO
Node<T>* head;
head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  //destuctor
  // TODO
      Node<T>* current = head;
  while(head != nullptr) {
    /*go to the next node in line*/
    Node<T>* next = current->getNext();
    /*delete current node*/
    delete current;
    /*set current to next node*/
    current = next;
  }

}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &x)
{
/*start with an emplty function*/  
head = nullptr;
currentSize = 0;
  /*get the first node from list*/
Node<T>* current = x.head;
  /*look for the last node*/
Node<T>* end = nullptr;
/*go through the list until we reach the end*/
  while(current != nullptr){
    this->insert(currentSize, current->getItem());
    current = current->getNext();
  }
  /*set the size*/
  currentSize = x.currentSize;
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> x)
{
  // TODO (use copy swap idiom)
  /*swaps this with x*/
  swap(x);
  return *this;
}

template <typename T>
void LinkedList<T>::swap(LinkedList &x)
{
  // TODO
  /*goes to the head and swaps to x*/
  Node<T>* tempHead = head;
  head = x.head;
  x.head = tempHead;
  /*swaps the size with x*/
  std::size_t tempSize = currentSize;
  currentSize = x.currentSize;
  x.currentSize = tempSize;
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  // TODO
  if(currentSize <= 0){
    return true;
  }
  return false;
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  // TODO
  return currentSize;
}

template <typename T>
void LinkedList<T>::insert(std::size_t position, const T &item)
{
  
  // TODO
}

template <typename T>
void LinkedList<T>::remove(std::size_t position)
{
  // TODO
}

template <typename T>
void LinkedList<T>::clear()
{
  // TODO
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  // TODO
  return T();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T &newValue)
{
  // TODO
}
