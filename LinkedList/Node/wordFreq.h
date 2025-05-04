#ifndef __WORDFREQ_INCLUDED__
#define __WORDFREQ_INCLUDED__

#include <string>
struct WordFreq {
    std::string word;
    int frequency;

    WordFreq(std::string word, int frequency);
    WordFreq();
    bool operator<(WordFreq);
    bool operator>(WordFreq);
    bool operator==(WordFreq);
    bool operator==(std::string);
    void operator++();
};

#endif // !__WORDFREQ_INCLUDED__
