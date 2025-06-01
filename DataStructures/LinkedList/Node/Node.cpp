#include "Node.h"
#include "../PriorityQueue/Player.h"

template class Node<Player>;

template <class T> Node<T>::Node(T* value) {
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

template <class T> Node<T>::Node() {}
