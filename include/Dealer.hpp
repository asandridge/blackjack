#ifndef DEALER_H
#define DEALER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Dealer
{
     private:

        vector<string> hand;
        Shoe *shoe;
        RuleBook *rules;
        Player *player;
        ScoreHelper score_helper;

     public:

        Dealer(Shoe *shoe, RuleBook *rules, Player *player) : shoe(shoe), rules(rules), player(player) {}

        vector<string> deal();
        void play_hand();
        void hit();
        string get_up_card();
        vector<string> get_hand();
        void make_refunds(int);

};

#endif
