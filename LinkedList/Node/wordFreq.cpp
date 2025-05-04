#include "wordFreq.h"
using namespace std;

WordFreq::WordFreq(string word, int frequency) {
    this->word = word;
    this->frequency = frequency;
}
WordFreq::WordFreq() {
    this->word = "";
    this->frequency = 0;
}
bool WordFreq::operator<(WordFreq wordFreq) {
    return this->frequency < wordFreq.frequency;
}
bool WordFreq::operator>(WordFreq wordFreq) {
    return this->frequency > wordFreq.frequency;
}
bool WordFreq::operator==(WordFreq wordFreq) {
    return this->frequency == wordFreq.frequency;
}
bool WordFreq::operator==(string str) { return this->word == str; }
void WordFreq::operator++() { this->frequency++; }
