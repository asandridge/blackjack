#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Player
{
    private:

        int bankroll;
        vector<string> hand;
        map<string, string> hard_totals;
        map<string, string> soft_totals;
        map<string, string> splitting;

    public:

        void complete_hand();
        void hit();
        void double_down();
        void split();

};

#endif
