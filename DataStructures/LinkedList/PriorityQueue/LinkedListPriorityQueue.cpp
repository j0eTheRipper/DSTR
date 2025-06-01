#include "LinkedListPriorityQueue.h"
#include "../Node/SingleLinkNode.h"
#include "Player.h"

template class PriorityQueueLL<Player>;

template <typename T> PriorityQueueLL<T>::PriorityQueueLL() {
    this->top = nullptr;
    this->length = 0;
}

template <typename T> PriorityQueueLL<T>::PriorityQueueLL(T& startingNode) {
    this->top = new Node<T>(startingNode);
    this->length = 1;
}

template <typename T> void PriorityQueueLL<T>::push(T& value) {
    Node<T>* newNode = new Node(value);

    if (this->length == 0) { // if there are no nodes
        this->top = newNode;
        this->length++;
        return;
    }

    // we have a node...
    Node<T>* a = top;
    if (a->value > newNode->value) {
        newNode->next = a;
        this->top = newNode;
        this->length++;
        return;
    }

    while (a->next) {
        if (a->next->value > newNode->value) {
            break;
        }
        a = a->next;
    }

    newNode->next = a->next;
    a->next = newNode;
    this->length++;
}

template <typename T> T& PriorityQueueLL<T>::peek() { return this->top->value; }

template <typename T> T& PriorityQueueLL<T>::pop() {
    T& result = this->top->value;
    Node<T>* temp = this->top;
    this->top = this->top->next;
    delete temp;
    return result;
}
