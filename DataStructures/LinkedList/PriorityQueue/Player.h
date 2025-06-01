#ifndef __PLAYER_H_INCLUDED__
#define __PLAYER_H_INCLUDED__

#include <string>
struct DateRegistered {
    int day, month, year;
    DateRegistered();
    DateRegistered(const int& day, const int& month, const int& year);

    std::string toString();
};

struct Player {
    std::string name, username, password;
    DateRegistered date;

    Player(std::string username, std::string name, std::string password,
           DateRegistered date);
    Player();

    bool operator<(const Player&);
    bool operator>(const Player&);
    bool operator==(const Player&);
};

#endif // !__
