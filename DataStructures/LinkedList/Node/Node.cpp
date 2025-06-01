#include "Node.h"

template <class T> Node<T>::Node(T* value) {
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

template <class T> Node<T>::Node() {}
