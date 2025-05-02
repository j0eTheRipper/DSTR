#include "Node.h"
template struct Node<Transaction>;

template <class T> Node<T>::Node(T* value) {
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

template <class T> Node<T>::Node() {}
