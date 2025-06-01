#ifndef __PLAYER_H_INCLUDED__
#define __PLAYER_H_INCLUDED__

#include <string>
struct DateRegistered {
    int day, month, year;
    DateRegistered();
    DateRegistered(const int&, const int&, const int&);

    std::string toString();
};

struct Player {
    std::string name, username, password;
    DateRegistered date;

    Player(std::string, std::string, std::string, DateRegistered);
    Player();

    bool operator<(const Player&);
    bool operator>(const Player&);
    bool operator==(const Player&);
};

#endif // !__
