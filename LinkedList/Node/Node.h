#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

#include <string>

struct Node {
    std::string customerID;
    Node* next;

    Node(std::string);
};

#endif // !
