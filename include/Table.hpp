#ifndef TABLE_H
#define TABLE_H

#include "../src/Player.cpp"
#include "../src/Dealer.cpp"

using namespace std;

class Table
{
    private:

        int betting_unit;

        Player player;
        Dealer dealer;
        Shoe shoe;
        RuleBook rules;

    public:

        Table(RuleBook *rules) :
            rules(*rules),
            shoe(Shoe(rules->get_decks())),
            player(&shoe, rules),
            dealer(&shoe, rules, &player),
            betting_unit(1)
            {}

        int play_round();
        void print_table(vector<tuple<vector<string>, int>>);
        void reset();
        int get_player_bankroll();
};



#endif
