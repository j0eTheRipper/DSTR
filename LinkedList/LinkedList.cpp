#include "LinkedList.h"
#include <cstring>
using namespace std;
template class LinkedList<Transaction>;

template <typename T> LinkedList<T>::LinkedList(Node<T>* node) {
    head = node;
    tail = node;
}

template <typename T> LinkedList<T>::LinkedList() {}

template <typename T> void LinkedList<T>::insertToStart(Node<T>* newNode) {
    Node<T>* temp = head->next;
    head->next = newNode;
    newNode->next = temp;
}

template <typename T> void LinkedList<T>::insertToEnd(Node<T>* newNode) {
    Node<T>* lastElement = getLastElement();
    lastElement->next = newNode;
    tail = newNode;
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
