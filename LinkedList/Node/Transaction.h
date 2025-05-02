#ifndef __Transaction_H_INCLUDED__
#define __Transaction_H_INCLUDED__

#include "Review.h"
#include <ctime>
#include <ostream>
#include <string>

struct Transaction {
    std::string product, category, payment, customerID;
    struct tm date;
    int price;

    Transaction(std::string);
    Transaction();

    bool operator<(Transaction);
    bool operator>(Transaction);

    friend std::ostream& operator<<(std::ostream& out, Transaction transaction);

  private:
    void getRowValues(std::string, std::string[]);
};

#endif
