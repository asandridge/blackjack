#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <tuple>

#include "Shoe.hpp"
#include "RuleBook.hpp"
#include "ScoreHelper.hpp"

using namespace std;

class Player
{
    private:

        int bankroll;
        int running_count;
        vector<tuple<vector<string>, int>> hands;

        Shoe *shoe;
        RuleBook *rules;
        ScoreHelper score_helper;

        int complete_hand(string, vector<string>*, bool, bool);
        int get_true_count();


    public:

        Player(int bankroll, Shoe *shoe, RuleBook *rules) : bankroll(bankroll), shoe(shoe), rules(rules), running_count(0) {}

        void play_hand(string, vector<string>, int);
        int get_bankroll();
        // void deal(vector<string>);
        int make_bet(int);
        vector<tuple<vector<string>, int>> get_hands();
        void payout(int);
        void update_running_count(vector<string>);
        void hit(vector<string>*);

};

#endif
