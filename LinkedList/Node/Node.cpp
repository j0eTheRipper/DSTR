#include "Node.h"
using namespace std;

Node::Node(string Artist, string Song, string Genre, double length,
           int Released) {
    this->Song = Song;
    this->Artist = Artist;
    this->Release = Released;
    this->Genre = Genre;
    this->Length = length;

    this->next = nullptr;
    this->prev = nullptr;
}
