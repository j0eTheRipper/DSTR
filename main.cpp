#include "LinkedList/Node/Node.h"
#include "LinkedList/Node/Transaction.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    string transaction, review;
    ifstream reviews("reviews.csv");
    ifstream transactions("transactions.csv");

    // read the first 2 lines (headers)
    getline(reviews, review, '\n');
    getline(transactions, transaction, '\n');

    while (getline(transactions, transaction, '\n')) {
        Transaction* t = new Transaction(transaction);
        cout << Node(t).transaction.customerID << endl;
    }

    cout << endl;
    reviews.close();
    transactions.close();

    return 0;
}
