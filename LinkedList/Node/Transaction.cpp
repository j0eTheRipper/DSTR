#include "Transaction.h"
#include "Node.h"
#include <string>

Transaction::Transaction(std::string customerID, std::string product,
                         std::string category, std::string price,
                         std::string date, std::string payment)
    : Node(customerID) {
    this->product = product;
    this->category = category;
    this->payment = payment;
    this->price = std::stoi(price);

    this->date.tm_mday = std::stoi(date.substr(0, date.find("/")));
    this->date.tm_mon = std::stoi(date.substr(3, date.find("/")));
    this->date.tm_mday = std::stoi(date.substr(5, date.length()));
}

bool Transaction::operator<(Transaction transaction) {
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
