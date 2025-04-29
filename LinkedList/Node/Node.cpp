#include "Node.h"
#include "Transaction.h"

Node::Node(Transaction* transaction) {
    this->transaction = *transaction;

    this->next = nullptr;
    this->prev = nullptr;
}
