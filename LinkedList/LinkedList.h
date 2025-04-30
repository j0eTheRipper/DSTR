#ifndef __LinkedList_H_INCLUDED__
#define __LinkedList_H_INCLUDED__

#include "Node/Node.h"
#include "Node/Transaction.h"
#include <iostream>

class LinkedList {
  public:
    LinkedList(Node* node);
    LinkedList();
    void insertToEnd(Node* newNode);
    void insertToStart(Node* newNode);
    void addFirstnode(Node* node);
    void reverse();

  private:
    Node* head;
    Node* tail;
    Node* getLastElement();
};

#endif
