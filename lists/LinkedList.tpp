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
   /*check if the position is legal*/
  if(position > currentSize || position < 0 ){
    return;
  }
  /*new node refrence for the chain*/
  Node<T>* itemNodePtr = new Node<T>(item);
  /*check if its legal to insert there*/
  if(position > currentSize || position < 0 ){
    delete itemNodePtr;
    return ;
  }
  /*if we are inserting at the head*/
  if(position == 0){
    itemNodePtr->setNext(head);
    head = itemNodePtr;
    currentSize++;
    return;
  }
  /*if we are not inserting at the head*/
  /*start at the head the use next to shift over to the right*/
  Node<T>* current = head;
  for(int i = 0; i < position-1; i++){
    current = current->getNext();
  }
  /*one we at the correct place we then use set for teh node*/
  itemNodePtr->setNext(current->getNext());
  /*set the previos node to the new node*/
  current->setNext(itemNodePtr);
  /*increase the size*/
  currentSize++;
  return;
}

template <typename T>
void LinkedList<T>::remove(std::size_t position)
{
     /*check if the position is legal*/
  if(position > currentSize || position < 0 ){
    return ;
  }
   /*new node refrence for the chain*/
  Node<T>* itemNodePtr = head->getNext();  
  /*check if we are removing the head*/
  if(position == 0){
    /*move the head to the next item*/
    itemNodePtr -> setNext(head);
    head = head->getNext();
    /*delete the old head*/
    delete itemNodePtr;
    /*decrease the size*/
    currentSize--;
    return;
  }
  /*not removing the head*/
  /*start at the head the use next to shift over to the right*/
  Node<T>* current = head;
  for(int i = 0; i < position-1; i++){
    current = current->getNext();
  }
  /*get the node to be removed*/
  Node<T>* nodeToRemove = current->getNext();
  /*set the previous node to point to the next node after the one being removed*/
  current->setNext(nodeToRemove->getNext());
  /*delete the node being removed*/
  delete nodeToRemove;
  /*decrease the size*/
  currentSize--;
  return;
}

template <typename T>
void LinkedList<T>::clear()
{
  /*go through the list and delete every node*/
  Node<T>* current = head;
  while(head != nullptr) {
    /*go to the next node*/
    Node<T>* next = current->getNext();
    /*delete current node*/
    delete current;
    /*set current to next node*/
    current = next;
  }
  /*set the head to null and size to 0*/
  head = nullptr;
  currentSize = 0;
  return ;
  // TODO
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
    /*check if the position is legal*/
  if(position > currentSize || position < 0 ){
    return T();
  }
  //if node is the frist
  if(head == 0){
    return T();
  }
  /*go throug the list untill we reach the position*/
  Node<T>* current = head;
  for(int i = 0; i < position; i++){
    current = current->getNext();
  }
  /*return the item at the position*/
  return current->getItem();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T &newValue)
{
  /*check if the position is legal*/
  if(position > currentSize || position < 0 ){
    return ;
  }
  /*go throug the list untill we reach the position*/
  Node<T>* current = head;
  for(int i = 0; i < position; i++){
    current = current->getNext();
  }
  /*set the item at the position to the new value*/
  current->setItem(newValue);
  return ;
}
