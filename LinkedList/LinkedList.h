#ifndef __LinkedList_H_INCLUDED__
#define __LinkedList_H_INCLUDED__

#include "Node/Node.h"
#include <iostream>

class LinkedList {
  public:
    LinkedList();
    void insertToStart(Node* newNode);
    void insertToEnd(Node* newNode);
    void display();
    void reverse();

  private:
    Node* head;
    Node* getLastElement();
};

#endif
