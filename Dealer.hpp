#ifndef DEALER_H
#define DEALER_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "Shoe.hpp"
#include "RuleBook.hpp"
#include "Player.hpp"
#include "ScoreHelper.hpp"

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
        void complete_hand();
        void hit();
        string get_up_card();
        vector<string> get_hand();

};

vector<string> Dealer::deal() {
    string dealer_first_card = shoe->draw();
    string dealer_second_card = shoe->draw();
    string player_first_card = shoe->draw();
    string player_second_card = shoe->draw();
    hand = { dealer_first_card, dealer_second_card };
    return { player_first_card, player_second_card };
}

void Dealer::hit() {
    string new_card = shoe->draw();
    hand.push_back(new_card);
}

string Dealer::get_up_card() {
    return hand[1];
}

vector<string> Dealer::get_hand() {
    return hand;
}

void Dealer::complete_hand() {

    tuple<int, bool> score = score_helper.calculate_hand_score(hand);
    int count = get<0>(score);
    bool is_soft_hand = get<1>(score);

    if (count < 17 || (count == 17 && is_soft_hand && rules->get_h17())) {
        hit();
        complete_hand();
    }
    return;
}

#endif
