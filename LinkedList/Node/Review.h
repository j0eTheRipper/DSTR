#ifndef __REVIEW_H_INCLUDED__
#define __REVIEW_H_INCLUDED__
#include "Node.h"

struct Review {
    std::string productID, review;
    int rating;

    Review(std::string, std::string, std::string, int);
};

#endif
