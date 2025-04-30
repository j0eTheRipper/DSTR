#include "LinkedList.h"
#include <cstring>
using namespace std;

LinkedList::LinkedList(Node* node) {
    head = node;
    tail = node;
}

LinkedList::LinkedList() {}

void LinkedList::insertToStart(Node* newNode) {
    Node* temp = head->next;
    head->next = newNode;
    newNode->next = temp;
}

void LinkedList::insertToEnd(Node* newNode) {
    Node* lastElement = getLastElement();
    lastElement->next = newNode;
    tail = newNode;
}

void LinkedList::reverse() {
    Node* curr = head;
    Node* prev = nullptr;

    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

Node* LinkedList::getLastElement() {
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    return temp;
}
