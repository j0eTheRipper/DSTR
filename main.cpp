#include "DataStructures/LinkedList/LinkedList.h"
#include "DataStructures/LinkedList/Node/Node.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    LinkedList<int> list = LinkedList<int>();
    Node<int>* firstNode = new Node<int>(new int(1));
    list.insertToStart(firstNode);

    cout << *list[0].value << endl;
}
