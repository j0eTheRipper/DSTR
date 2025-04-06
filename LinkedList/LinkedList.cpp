#include "LinkedList.h"
#include <iostream>
using namespace std;

Node* head;

LinkedList::LinkedList(string name, string id, double salary) {
    Node* newEmployee = new Node(name, id, salary);
    head = newEmployee;
}

void LinkedList::insertToStart(Node* newEmp) {
    Node* temp = head->next;
    head->next = newEmp;
    newEmp->next = temp;
}

void LinkedList::insertToEnd(Node* newEmp) {
    Node* lastElement = getLastElement();
    lastElement->next = newEmp;
}

void LinkedList::display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
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
