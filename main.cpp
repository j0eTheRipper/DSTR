#include "LinkedList/LinkedList.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream file = ifstream("reviews_cleaned.csv");
    string row;
    LinkedList reviews = LinkedList();

    while (getline(file, row)) { // while there is a new line to be read...
    }
    return 0;
}
