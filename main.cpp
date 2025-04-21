#include "LinkedList/Node/Transaction.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    string row;
    ifstream file("file.csv");

    getline(file, row, '\n');
    getline(file, row, '\n');
    Transaction transaction(row);
    getline(file, row, '\n');
    Transaction transaction2(row);

    bool a = transaction < transaction2;

    cout << a << endl;

    cout << transaction2.price << endl;

    cout << endl;
    file.close();

    return 0;
}
