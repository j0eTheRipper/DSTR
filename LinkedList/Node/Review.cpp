#include "Review.h"

Review::Review(std::string productID, std::string customerID,
               std::string review, int rating) {
    this->productID = productID;
    this->review = review;
    this->rating = rating;
}
