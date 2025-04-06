#include "Review.h"
#include "Node.h"

Review::Review(std::string productID, std::string customerID,
               std::string review, int rating)
    : Node(customerID) {
    this->productID = productID;
    this->review = review;
    this->rating = rating;
}
