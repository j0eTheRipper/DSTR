#include "LinkedList/LinkedList.h"
#include "LinkedList/Node/Node.h"
#include "LinkedList/Node/Transaction.h"
#include <chrono>
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

    auto start = chrono::high_resolution_clock().now();
    transactions.bubbleSort();
    auto stop = chrono::high_resolution_clock().now();

    for (int i = 0; i < transactions.size(); i++) {
        cout << *transactions[i].value << endl;
    }
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "finished execution in " << duration.count() << " milliseconds";

    cout << endl;
    transactionsFile.close();

    return 0;
}
