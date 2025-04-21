#ifndef __LinkedList_H_INCLUDED__
#define __LinkedList_H_INCLUDED__

#include "Node/Transaction.h"
#include <iostream>

class LinkedList {
  public:
    LinkedList(std::string);
    LinkedList(Transaction* transaction);
    void insertToEnd(Transaction* newTransaction);
    void insertToStart(Transaction* newTransaction);
    void reverse();

  private:
    Transaction* head;
    Transaction* getLastElement();
};

#endif
