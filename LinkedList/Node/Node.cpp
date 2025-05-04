#include "Node.h"
#include "wordFreq.h"
template struct Node<Transaction>;
template struct Node<Review>;
template struct Node<WordFreq>;

template <class T> Node<T>::Node(T* value) {
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

template <class T> Node<T>::Node() {}
