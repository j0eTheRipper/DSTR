#ifndef __LinkedListPriority_h__
#define __LinkedListPriority_h__

#include "../Node/Node.h"
#include "PriorityQueue.h"

template <typename T> class PriorityQueueLL : PriorityQueue<T> {
    Node<T>* top;

  private:
    void insert(Node<T>*);
};

#endif // !__LinkedListPriority_h__
