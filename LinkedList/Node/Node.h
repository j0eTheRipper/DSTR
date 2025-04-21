#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

#include <string>

struct Node {
    std::string Artist;
    std::string Song;
    std::string Genre;
    double Length;
    int Release;
    Node* next;
    Node* prev;

    Node(std::string, std::string, std::string, double, int);
};

#endif // !
