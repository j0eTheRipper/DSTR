#ifndef __Transaction_H_INCLUDED__
#define __Transaction_H_INCLUDED__

#include "Node.h"
#include <ctime>
#include <string>

struct Transaction : public Node {
    std::string product, category, payment;
    struct tm date;
    int price;

    Transaction(std::string, std::string, std::string, std::string, std::string,
                std::string);

    bool operator<(Transaction);
    bool operator>(Transaction);
};

#endif
