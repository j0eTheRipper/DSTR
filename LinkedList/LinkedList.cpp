#include "LinkedList.h"
#include <cstring>
using namespace std;

Transaction* head;
Transaction* tail;

LinkedList::LinkedList(string row) {
    Transaction* newTransaction = new Transaction(row);
    head = newTransaction;
    tail = newTransaction;
}

void LinkedList::insertToStart(Transaction* newTransaction) {
    Transaction* temp = head->next;
    head->next = newTransaction;
    newTransaction->next = temp;
}

void LinkedList::insertToEnd(Transaction* newTransaction) {
    Transaction* lastElement = getLastElement();
    lastElement->next = newTransaction;
    tail = newTransaction;
}

void LinkedList::reverse() {
    Transaction* curr = head;
    Transaction* prev = nullptr;

    while (curr) {
        Transaction* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

Transaction* LinkedList::getLastElement() {
    Transaction* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    return temp;
}
