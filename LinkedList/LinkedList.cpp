#include "LinkedList.h"
#include "Node/Node.h"
#include <cstring>
using namespace std;
template class LinkedList<Transaction>;

template <typename T> LinkedList<T>::LinkedList(Node<T>* node) {
    length = 1;
    head = node;
    tail = node;
}

template <typename T> LinkedList<T>::LinkedList() {}

template <typename T> void LinkedList<T>::insertToStart(Node<T>* newNode) {
    Node<T>* temp = head;
    head = newNode;
    head->next = temp;
    temp->prev = head;
    this->length += 1;
}

template <typename T> void LinkedList<T>::insertToEnd(Node<T>* newNode) {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    this->length += 1;
}

template <typename T> int LinkedList<T>::size() { return this->length; }

template <typename T> Node<T>& LinkedList<T>::operator[](int const i) {
    Node<T>* curr;
    if (i > (length / 2)) {
        curr = tail;
        int counter = length - 1;
        while (counter > i) {
            curr = curr->prev;
            counter--;
        }
    } else {
        curr = head;
        int counter = 0;
        while (counter < i) {
            curr = curr->next;
            counter++;
        }
    }
    return *curr;
}

template <typename T> void LinkedList<T>::swap(Node<T>& a, Node<T>& b) {
    T* temp = a.value;
    a.value = b.value;
    b.value = temp;
}

template <typename T> void LinkedList<T>::reverse() {
    Node<T>* curr = head;
    Node<T>* prev = nullptr;

    while (curr) {
        Node<T>* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

template <typename T> Node<T>* LinkedList<T>::getLastElement() {
    Node<T>* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    return temp;
}

template <typename T> void LinkedList<T>::bubbleSort() {
    for (int i = 0; i < length; i++) {
        Node<T>* a = &(*this)[i];
        Node<T>* b = a;
        for (int j = 0; j < length - (1 + i); j++) {
            b = b->next;
            if (*a->value < *b->value) {
                this->swap(*a, *b);
            }
        }
    }
}
