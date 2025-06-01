#ifndef __LinkedListPriority_h__
#define __LinkedListPriority_h__

#include "../Node/SingleLinkNode.h"

template <typename T> class PriorityQueueLL {
  public:
    PriorityQueueLL();
    PriorityQueueLL(T&);
    void push(T&);
    T& pop();
    T& peek();

  private:
    Node<T>* top;
    int length;
};

#endif // !__LinkedListPriority_h__
