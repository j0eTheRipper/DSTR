#include "LinkedList.h"
#include <cstring>
using namespace std;

Node* head;
Node* tail;

LinkedList::LinkedList(Transaction* transaction) {
    Node* newNode = new Node(transaction);
    head = newNode;
    tail = newNode;
}

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
