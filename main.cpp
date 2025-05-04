#include "LinkedList/Array.h"
#include "LinkedList/LinkedList.h"
#include "LinkedList/Node/Node.h"
#include "LinkedList/Node/Transaction.h"
#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;

void LinkedListIml();
Array<Transaction> LoadTransactionsArray();

bool x(Transaction& t) {
    if (t.category == "Electronics" && t.payment.find("Credit Card"))
        return true;
    return false;
}
int main() {
    cout << "Welcome to Reviews and transactions analysier..." << endl;
    cout << "what data structure would you like the program to use? " << endl;
    cout << "1. array" << endl << "2. linked list" << endl;
    string dstrSelection;
    cin >> dstrSelection;

    if (dstrSelection == "1") {
        cout << "an array will be used to store and perform operations on the "
                "dataset."
             << endl;
        cout << "loading transactions into array" << endl;

        auto start = chrono::high_resolution_clock::now();
        Array<Transaction> transactions = LoadTransactionsArray();
        auto stop = chrono::high_resolution_clock::now();
        auto duration =
            chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "loaded " << transactions.len() << " transactions in "
             << duration.count() << " microseconds" << endl;

        cout << "Select an algorithm to sort the transactions... " << endl;
        cout << "1. MergeSort" << endl;
        cout << "2. BubbleSort" << endl;
        cin >> dstrSelection;

        start = chrono::high_resolution_clock::now();
        if (dstrSelection == "1") {
            transactions = transactions.mergeSort();
        } else if (dstrSelection == "2") {
            transactions.bubbleSort();
        }
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "sorted " << transactions.len() << " transactions in "
             << duration.count() << " microseconds" << endl;
        ofstream transactionsSorted("transactionsSorted.csv");
        for (int i = 0; i < transactions.len(); i++) {
            transactionsSorted << transactions[i] << endl;
        }
        transactionsSorted.close();

        cout << "enter a date you want to retrieve... ";
        string date;
        cin >> date;
        cout << transactions.findByDate(Transaction(
            "CUST4434,Mouse,Automotive,483.15," + date + ",Bank Transfer"));

        cout << "transactions in the Electric category payed for by credit "
                "cards: "
             << transactions.find(x);
    }
}

void LinkedListIml() {
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

    transactions.bubbleSort();

    for (int i = 0; i < transactions.size(); i++) {
        cout << *transactions[i].value << endl;
    }

    cout << endl;
    transactionsFile.close();
}

Array<Transaction> LoadTransactionsArray() {
    string transactionRow;
    ifstream transactionsFile("transactions.csv");

    // read the first line of the file: the csv header
    getline(transactionsFile, transactionRow, '\n');

    getline(transactionsFile, transactionRow, '\n');
    Transaction* transaction = new Transaction(transactionRow);

    Array<Transaction> transactions(*transaction);

    while (getline(transactionsFile, transactionRow, '\n')) {
        Transaction* transaction = new Transaction(transactionRow);
        transactions.append(*transaction);
    }
    transactionsFile.close();
    return transactions;
}
