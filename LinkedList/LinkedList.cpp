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
    Node<T>* temp = head->next;
    head->next = newNode;
    newNode->next = temp;
    this->length++;
}

template <typename T> void LinkedList<T>::insertToEnd(Node<T>* newNode) {
    Node<T>* lastElement = getLastElement();
    lastElement->next = newNode;
    tail = newNode;
    this->length++;
}

template <typename T> int LinkedList<T>::size() { return this->length; }

template <typename T> Node<T> LinkedList<T>::operator[](int const i) {
    if (i >= length)
        return Node<T>();

    Node<T>* curr;
    if (i > length / 2) {
        curr = tail;
        int counter = length;
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
