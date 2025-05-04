#include "LinkedList/Array.h"
#include "LinkedList/LinkedList.h"
#include "LinkedList/Node/Node.h"
#include "LinkedList/Node/Review.h"
#include "LinkedList/Node/Transaction.h"
#include "LinkedList/Node/wordFreq.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void LinkedListIml();
Array<Transaction> LoadTransactionsArray();
Array<Review> LoadReviewsArray();
LinkedList<Transaction> LoadTransactionsLinkedList();
LinkedList<Review> LoadReviewsLinkedList();
void sanitize(string& s);
void WordFreqForOneStar(Array<Review>& reviews);
void WordFreqForOneStar(LinkedList<Review>& reviews);
string* split(string str, int& wordCount);

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
        start = chrono::high_resolution_clock::now();
        cout << "found at index: "
             << transactions.findByDate(
                    Transaction("CUST4434,Mouse,Automotive,483.15," + date +
                                ",Bank Transfer"))
             << endl;
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "Executed binary search on " << transactions.len()
             << " transactions in " << duration.count() << " microseconds"
             << endl;

        start = chrono::high_resolution_clock::now();
        cout << "transactions in the Electric category payed for by credit "
                "cards: "
             << transactions.find(x) << endl;
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "Executed linear search on " << transactions.len()
             << " transactions in " << duration.count() << " microseconds"
             << endl;

        cout << "Reviews............" << endl;
        cout << "Loading Reviews into array" << endl;
        start = chrono::high_resolution_clock::now();
        Array<Review> reviews = LoadReviewsArray();
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "loaded " << reviews.len() << " reviews in " << duration.count()
             << " microseconds" << endl;

        cout << "Select an algorithm to sort the reviews... " << endl;
        cout << "1. MergeSort" << endl;
        cout << "2. BubbleSort" << endl;
        cin >> dstrSelection;

        start = chrono::high_resolution_clock::now();
        if (dstrSelection == "1") {
            reviews = reviews.mergeSort();
        } else if (dstrSelection == "2") {
            reviews.bubbleSort();
        }
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "sorted " << reviews.len() << " reviews in " << duration.count()
             << " microseconds" << endl;
        WordFreqForOneStar(reviews);
    } else {
        cout << "a linked list will be used to store and perform operations on "
                "the "
                "dataset."
             << endl;
        cout << "loading transactions into linked list" << endl;

        auto start = chrono::high_resolution_clock::now();
        LinkedList<Transaction> transactions = LoadTransactionsLinkedList();
        auto stop = chrono::high_resolution_clock::now();
        auto duration =
            chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "loaded " << transactions.size() << " transactions in "
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
        cout << "sorted " << transactions.size() << " transactions in "
             << duration.count() << " microseconds" << endl;
        ofstream transactionsSorted("transactionsSorted.csv");
        for (int i = 0; i < transactions.size(); i++) {
            transactionsSorted << *transactions[i].value << endl;
        }
        transactionsSorted.close();

        cout << "enter a date you want to retrieve... ";
        string date;
        cin >> date;
        start = chrono::high_resolution_clock::now();
        cout << "found at index: "
             << transactions.findByDate(
                    Transaction("CUST4434,Mouse,Automotive,483.15," + date +
                                ",Bank Transfer"))
             << endl;
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "Executed binary search on " << transactions.size()
             << " transactions in " << duration.count() << " microseconds"
             << endl;

        start = chrono::high_resolution_clock::now();
        cout << "transactions in the Electric category payed for by credit "
                "cards: "
             << transactions.find(x) << endl;
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "Executed linear search on " << transactions.size()
             << " transactions in " << duration.count() << " microseconds"
             << endl;
        cout << "Reviews............" << endl;
        cout << "Loading Reviews into linkedlist" << endl;
        start = chrono::high_resolution_clock::now();
        LinkedList<Review> reviews = LoadReviewsLinkedList();
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "loaded " << reviews.size() << " reviews in "
             << duration.count() << " microseconds" << endl;

        cout << "Select an algorithm to sort the reviews... " << endl;
        cout << "1. MergeSort" << endl;
        cout << "2. BubbleSort" << endl;
        cin >> dstrSelection;

        start = chrono::high_resolution_clock::now();
        if (dstrSelection == "1") {
            reviews = reviews.mergeSort();
        } else if (dstrSelection == "2") {
            reviews.bubbleSort();
        }
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "sorted " << reviews.size() << " reviews in "
             << duration.count() << " microseconds" << endl;
        WordFreqForOneStar(reviews);
    }
}

LinkedList<Transaction> LoadTransactionsLinkedList() {
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

    transactionsFile.close();
    return transactions;
}
LinkedList<Review> LoadReviewsLinkedList() {
    string reviewRow;
    ifstream reviewsFile("reviews.csv");

    // read the first line of the file: the csv header
    getline(reviewsFile, reviewRow, '\n');

    // read the first line to insert the first node
    getline(reviewsFile, reviewRow, '\n');
    Review* review = new Review(reviewRow);

    Node<Review>* headNode = new Node(review);

    LinkedList<Review> reviews(headNode);

    while (getline(reviewsFile, reviewRow, '\n')) {
        Review* review = new Review(reviewRow);
        Node<Review>* node = new Node(review);
        reviews.insertToEnd(node);
    }

    reviewsFile.close();
    return reviews;
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
Array<Review> LoadReviewsArray() {
    string reviewRow;
    ifstream reviewsFile("reviews.csv");

    // read the first line of the file: the csv header
    getline(reviewsFile, reviewRow, '\n');

    getline(reviewsFile, reviewRow, '\n');
    Review* review = new Review(reviewRow);

    Array<Review> reviews(*review);

    while (getline(reviewsFile, reviewRow, '\n')) {
        Review* review = new Review(reviewRow);
        reviews.append(*review);
    }
    reviewsFile.close();
    return reviews;
}

void WordFreqForOneStar(LinkedList<Review>& reviews) {
    Node<Review>* current = &reviews[0];
    LinkedList<WordFreq> wordFreqList;

    while (current != nullptr) {
        if (current->value->rating != 1) {
            current = current->next;
            continue;
        }

        int wordCount = 1;
        string* reviewWords = split(current->value->review, wordCount);

        for (int i = 0; i < wordCount; i++) {
            sanitize(reviewWords[i]);
            if (reviewWords[i] == "")
                continue;

            bool found = false;
            Node<WordFreq>* wfNode = &wordFreqList[0];
            while (wfNode != nullptr) {
                if (*wfNode->value == reviewWords[i]) {
                    ++(*wfNode->value); // uses overloaded ++
                    found = true;
                    break;
                }
                wfNode = wfNode->next;
            }

            if (!found) {
                WordFreq* wf = new WordFreq(reviewWords[i], 1);
                Node<WordFreq>* newNode = new Node(wf);
                wordFreqList.insertToEnd(newNode);
            }
        }

        delete[] reviewWords;
        current = current->next;
    }

    wordFreqList = wordFreqList.mergeSort();

    Node<WordFreq>* printNode = &wordFreqList[0];
    while (printNode != nullptr) {
        cout << printNode->value->word << ": " << printNode->value->frequency
             << endl;
        printNode = printNode->next;
    }
}
void WordFreqForOneStar(Array<Review>& reviews) {
    int i = 0;
    Array<WordFreq> wordFreqArr;
    while (i < reviews.len()) {
        if (reviews[i].rating != 1) {
            i++;
            continue;
        }

        int wordCount = 1;
        string* reviewWords = split(reviews[i].review, wordCount);

        for (int j = 0; j < wordCount; j++) {
            sanitize(reviewWords[j]); // Clean up the word
            if (reviewWords[j] == "")
                continue;

            bool found = false;
            for (int k = 0; k < wordFreqArr.len(); k++) {
                if (wordFreqArr[k] == reviewWords[j]) {
                    wordFreqArr[k].frequency++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                WordFreq wf(reviewWords[j], 1);
                wordFreqArr.append(wf);
            }
        }
        delete[] reviewWords;
        i++;
    }

    wordFreqArr = wordFreqArr.mergeSort();
    for (int i = 0; i < wordFreqArr.len(); i++) {
        cout << wordFreqArr[i].word << ": " << wordFreqArr[i].frequency << endl;
    }
}

string* split(string str, int& wordCount) {
    for (char x : str) {
        if (x == ' ')
            wordCount++;
    }

    string* result = new string[wordCount];
    int j = 0;
    while (str.find(" ") != -1) {
        result[j] = str.substr(0, str.find(" "));
        str.replace(0, str.find(" ") + 1, "");
        j++;
    }
    result[j] = str;
    return result;
}

void sanitize(string& s) {
    string cleaned = "";
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        // Convert uppercase to lowercase
        if (c >= 'A' && c <= 'Z') {
            c = c + 32;
        }
        // Keep only lowercase letters and digits
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            cleaned += c;
        }
        // Otherwise skip (removes punctuation, symbols, etc.)
    }
    s = cleaned;
}
