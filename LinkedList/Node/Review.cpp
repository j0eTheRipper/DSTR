#include "Review.h"
#include <string>
using namespace std;

Review::Review(string row) {
    string values[4] = {};
    getRowValues(row, values);

    productID = values[0];
    customerID = values[1];
    rating = stoi(values[2]);
    review = values[3];
}
Review::Review() {}

void Review::getRowValues(string row, string* values) {
    int i = 0;
    while (row.find(",") != -1 && i < 3) {
        values[i] = row.substr(0, row.find(","));
        row.replace(0, row.find(",") + 1, "");
        i++;
    }
    values[i] = row;
}
