#include "Node.h"

Node::Node(std::string customerID) {
    this->customerID = customerID;
    this->next = nullptr;
}
