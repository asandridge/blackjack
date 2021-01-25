#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

#include "Player.hpp"
#include "Dealer.hpp"
#include "Shoe.hpp"

using namespace std;

class Table
{
    private:

        int decks;
        bool h17;
        bool dos;
        bool variants;
        string counting_strategy;
        string blackjack_payout;

        Player player;
        Dealer dealer;
        Shoe shoe;

    public:

        Table(int decks, bool h17, bool dos, bool variants, string counting_strategy, string blackjack_payout) :
            decks(decks),
            h17(h17),
            dos(dos),
            variants(variants),
            counting_strategy(counting_strategy),
            blackjack_payout(blackjack_payout),
            shoe(Shoe(decks)) {}
};

void Table::Table()

#endif
