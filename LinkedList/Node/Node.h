#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

#include "Transaction.h"

struct Node {
    Transaction transaction;
    Node* next;
    Node* prev;

    Node(Transaction*);
};

#endif
