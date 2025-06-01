#include "Player.h"

Player::Player(std::string username, std::string name, std::string password,
               DateRegistered date) {
    this->username = username;
    this->name = name;
    this->password = password;
    this->date = date;
}

Player::Player() {}

DateRegistered::DateRegistered(const int& day, const int& month,
                               const int& year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

DateRegistered::DateRegistered() {}

bool Player::operator<(const Player& player) {
    // true if this (ie left operand) has happened before player (ie right
    // operand)
    if (this->date.year > player.date.year) {
        return false;
    } else if (this->date.year == player.date.year) {
        if (this->date.month > player.date.month) {
            return false;
        } else if (this->date.month == player.date.month) {
            if (this->date.day >= player.date.day) {
                return false;
            }
        }
    }
    return true;
}

bool Player::operator>(const Player& player) {
    // true if this (ie left operand) has happened after player (ie right
    // operand)
    if (this->date.year < player.date.year) {
        return false;
    } else if (this->date.year == player.date.year) {
        if (this->date.month < player.date.month) {
            return false;
        } else if (this->date.month == player.date.month) {
            if (this->date.day <= player.date.day) {
                return false;
            }
        }
    }
    return true;
}

bool Player::operator==(const Player& player) {
    return this->date.day == player.date.day &&
           this->date.month == player.date.month &&
           this->date.year == player.date.year;
}
