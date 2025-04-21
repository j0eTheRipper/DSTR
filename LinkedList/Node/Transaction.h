#ifndef __Transaction_H_INCLUDED__
#define __Transaction_H_INCLUDED__

#include <ctime>
#include <string>

struct Transaction {
    std::string product, category, payment, customerID;
    struct tm date;
    int price;
    Transaction* next;
    Transaction* prev;

    Transaction(std::string);

    bool operator<(Transaction);
    bool operator>(Transaction);

  private:
    void getRowValues(std::string, std::string*);
};

#endif
