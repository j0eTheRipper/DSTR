#include "SingleLinkNode.h"
#include "../PriorityQueue/Player.h"

template class Node<Player>;

template <typename T> Node<T>::Node(T& value) : value(value) {
    this->next = nullptr;
}

template <typename T> Node<T>::~Node() {}
