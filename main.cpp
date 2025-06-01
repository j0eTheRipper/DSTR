#include "DataStructures/LinkedList/PriorityQueue/LinkedListPriorityQueue.h"
#include "DataStructures/LinkedList/PriorityQueue/Player.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    /*
     */
    PriorityQueueLL<Player> players;
    Player a("j0e", "youssef", "123", DateRegistered(10, 10, 2020));
    Player b("jack", "nigger", "123", DateRegistered(10, 10, 2022));
    players.push(b);
    players.push(a);
    cout << players.pop().username;
    cout << players.pop().username;
}
