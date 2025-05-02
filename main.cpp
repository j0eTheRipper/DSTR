#include "LinkedList/LinkedList.h"
#include "LinkedList/Node/Node.h"
#include "LinkedList/Node/Transaction.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    string transactionRow;
    ifstream transactionsFile("transactions.csv");

    // read the first line of the file: the csv header
    getline(transactionsFile, transactionRow, '\n');

    // read the first line to insert the first node
    getline(transactionsFile, transactionRow, '\n');
    Transaction* transaction = new Transaction(transactionRow);

    Node<Transaction>* headNode = new Node(transaction);

    LinkedList transactions(headNode);

    while (getline(transactionsFile, transactionRow, '\n')) {
        Transaction* transaction = new Transaction(transactionRow);
        Node<Transaction>* node = new Node(transaction);
        transactions.insertToEnd(node);
    }
    cout << "Before Swap" << endl;
    Node<Transaction> a = transactions[2];
    Node<Transaction> b = transactions[3];
    cout << *a.value << endl;
    cout << *b.value << endl;

    cout << "Swapping" << endl;
    transactions.swap(a, b);
    cout << *a.value << endl;
    cout << *b.value << endl;

    cout << endl;
    transactionsFile.close();

    return 0;
}
