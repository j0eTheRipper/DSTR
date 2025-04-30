#ifndef __LinkedList_H_INCLUDED__
#define __LinkedList_H_INCLUDED__

#include "Node/Node.h"
#include "Node/Transaction.h"
#include <iostream>

template <class T> class LinkedList {
  public:
    LinkedList(Node<T>* node);
    LinkedList();
    void insertToEnd(Node<T>* newNode);
    void insertToStart(Node<T>* newNode);
    void addFirstnode(Node<T>* node);
    void reverse();

  private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* getLastElement();
};

#endif
