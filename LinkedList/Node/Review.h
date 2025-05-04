#ifndef __REVIEW_H_INCLUDED__
#define __REVIEW_H_INCLUDED__

#include <string>

struct Review {
    std::string productID, review, customerID;
    int rating;

    Review(std::string row);
    Review();
    bool operator>(Review review);
    bool operator<(Review review);
    bool operator==(Review review);

  private:
    void getRowValues(std::string, std::string*);
};

#endif
