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
    void swap(Node<T>& a, Node<T>& b);
    void reverse();
    int size();
    Node<T>& operator[](int const i);
    void bubbleSort();
    LinkedList<T> mergeSort();
    int findByDate(const T& target);
    int find(bool (*filter)(T& a));

  private:
    int length;
    Node<T>* head;
    Node<T>* tail;
    LinkedList<T> merge(LinkedList<T>& left, LinkedList<T>& right);
};

#endif
