#include "Transaction.h"
using namespace std;

Transaction::Transaction(string row) {
    string values[6] = {};
    getRowValues(row, values); // populate the values

    this->customerID = values[0];
    this->product = values[1];
    this->category = values[2];
    this->price = stoi(values[3]);

    string date = values[4]; // get the date value from the 4th column
    // get the substring of day, month, and year and assign them to variables in
    // date dstr
    this->date.tm_mday = stoi(date.substr(0, date.find("/")));
    this->date.tm_mon = stoi(date.substr(3, date.find("/")));
    this->date.tm_mday = stoi(date.substr(6, date.length()));

    this->payment = values[5];

    this->next = nullptr;
    this->prev = nullptr;
}

bool Transaction::operator<(Transaction transaction) {
    // true if this (ie left operand) has happened before transaction (ie right
    // operand)
    if (this->date.tm_year > transaction.date.tm_year) {
        return false;
    } else if (this->date.tm_year == transaction.date.tm_year) {
        if (this->date.tm_mon > transaction.date.tm_mon) {
            return false;
        } else if (this->date.tm_mon == transaction.date.tm_mon) {
            if (this->date.tm_mday >= transaction.date.tm_mday) {
                return false;
            }
        }
    }
    return true;
}

bool Transaction::operator>(Transaction transaction) {
    // true if this (ie left operand) has happened after transaction (ie right
    // operand)
    if (this->date.tm_year < transaction.date.tm_year) {
        return false;
    } else if (this->date.tm_year == transaction.date.tm_year) {
        if (this->date.tm_mon < transaction.date.tm_mon) {
            return false;
        } else if (this->date.tm_mon == transaction.date.tm_mon) {
            if (this->date.tm_mday <= transaction.date.tm_mday) {
                return false;
            }
        }
    }
    return true;
}

void Transaction::getRowValues(string row, string* values) {
    int i = 0;
    while (row.find(",") != -1) {
        values[i] = row.substr(0, row.find(","));
        row.replace(0, row.find(",") + 1, "");
        i++;
    }
    values[i] = row;
}
