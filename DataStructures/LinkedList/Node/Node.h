#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

template <class T> struct Node {
    T* value;
    Node* next;
    Node* prev;

    Node(T*);
    Node();
};

#endif
