#include "LinkedList.h"
#include "Node/Node.h"
#include <cstddef>

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

template <typename T>
LinkedList<T>* LinkedList<T>::mergeSort(LinkedList<T>* linkedList) {
    if (linkedList->size() == 1) {
        return linkedList;
    } // base condition

    int leftLength = linkedList->size() / 2;
    int rightLength = leftLength;
    if (linkedList->length % 2 != 0)
        rightLength = leftLength + 1; // to account for non-even arrays

    LinkedList<T>* left = new LinkedList<T>(&(*linkedList)[0]);
    LinkedList<T>* right = new LinkedList<T>(&(*linkedList)[rightLength]);

    Node<T>* a = linkedList->head;
    while (left->size() < leftLength) {
        a = a->next;
        Node<T>* copyOfNode = new Node(a->value);
        left->insertToEnd(copyOfNode);
    }
    while (right->size() < rightLength) {
        a = a->next;
        Node<T>* copyOfNode = new Node(a->value);
        right->insertToEnd(copyOfNode);
    }

    left = mergeSort(left);
    right = mergeSort(right);

    for (int i = 0; i < left->size(); i++) {
        cout << *(*left)[i].value << " -> ";
    }
    cout << endl;

    return linkedList;
}

template <typename T>
LinkedList<T>& LinkedList<T>::merge(LinkedList<T>& left, LinkedList<T>& right) {
    int fullLength = left.size() + right.size();
    LinkedList<T>* result = new LinkedList<T>();

    Node<T>* rightPointer = &right[0];
    Node<T>* leftPointer = &left[0];
    int resultCounter = 0;

    while (resultCounter < fullLength && rightPointer && leftPointer) {
        if (*rightPointer->value < *leftPointer->value) {
            if (result->length == 0)
                result->addFirstnode(leftPointer);
            else
                result->insertToEnd(leftPointer);

            leftPointer = leftPointer->next;
        } else {
            if (result->length == 0)
                result->addFirstnode(rightPointer);
            else
                result->insertToEnd(rightPointer);

            rightPointer = rightPointer->next;
        }
        resultCounter++;
    }

    while (rightPointer) {
        result->insertToEnd(rightPointer);
        rightPointer = rightPointer->next;
        resultCounter++;
    }
    while (leftPointer) {
        result->insertToEnd(leftPointer);
        leftPointer = leftPointer->next;
        resultCounter++;
    }

    return *result;
}
