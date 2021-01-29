#ifndef TABLE_H
#define TABLE_H

#include "Player.hpp"
#include "Dealer.hpp"
#include "Shoe.hpp"
#include "ScoreHelper.hpp"

using namespace std;

class Table
{
    private:

        int betting_unit;

        Player player;
        Dealer dealer;
        Shoe shoe;
        RuleBook rules;
        ScoreHelper score_helper;


    public:

        Table(RuleBook *rules) :
            rules(*rules),
            shoe(Shoe(rules->get_decks())),
            player(1000, &shoe, rules),
            dealer(&shoe, rules, &player),
            betting_unit(10)
            {}

        int play_round();
        void print_table();
};



#endif
