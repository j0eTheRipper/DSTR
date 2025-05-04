#include "LinkedList.h"
#include "Node/Node.h"

using namespace std;
template class LinkedList<Transaction>;

template <typename T> LinkedList<T>::LinkedList(Node<T>* node) {
    length = 1;
    head = node;
    tail = node;
}

template <typename T> LinkedList<T>::LinkedList() {
    length = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T> void LinkedList<T>::insertToStart(Node<T>* newNode) {
    Node<T>* temp = head;
    head = newNode;
    head->next = temp;
    temp->prev = head;
    this->length += 1;
}

template <typename T> void LinkedList<T>::insertToEnd(Node<T>* newNode) {
    if (length == 0 || head == nullptr || tail == nullptr) {
        addFirstnode(newNode);
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    tail->next = nullptr;
    this->length += 1;
}

template <typename T> void LinkedList<T>::addFirstnode(Node<T>* newNode) {
    length = 1;
    head = newNode;
    tail = newNode;
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

template <typename T> LinkedList<T> LinkedList<T>::mergeSort() {
    if (length <= 1) {
        return *this;
    }

    int mid = length / 2;
    LinkedList<T> left, right;

    Node<T>* curr = head;
    for (int i = 0; i < mid; ++i) {
        left.insertToEnd(new Node<T>(new T(*curr->value)));
        curr = curr->next;
    }
    for (int i = mid; i < length; ++i) {
        right.insertToEnd(new Node<T>(new T(*curr->value)));
        curr = curr->next;
    }

    LinkedList<T> sortedLeft = left.mergeSort();
    LinkedList<T> sortedRight = right.mergeSort();
    return merge(sortedLeft, sortedRight);
}

template <typename T>
LinkedList<T> LinkedList<T>::merge(LinkedList<T>& left, LinkedList<T>& right) {
    LinkedList<T> result;

    Node<T>* leftPtr = left.head;
    Node<T>* rightPtr = right.head;

    while (leftPtr && rightPtr) {
        if (*(leftPtr->value) > *(rightPtr->value)) {
            result.insertToEnd(new Node<T>(new T(*(leftPtr->value))));
            leftPtr = leftPtr->next;
        } else {
            result.insertToEnd(new Node<T>(new T(*(rightPtr->value))));
            rightPtr = rightPtr->next;
        }
    }

    while (leftPtr) {
        result.insertToEnd(new Node<T>(new T(*(leftPtr->value))));
        leftPtr = leftPtr->next;
    }
    while (rightPtr) {
        result.insertToEnd(new Node<T>(new T(*(rightPtr->value))));
        rightPtr = rightPtr->next;
    }

    return result;
}
