#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <map>
#include <vector>
#include <math.h>

#include "Shoe.hpp"
#include "RuleBook.hpp"
#include "ScoreHelper.hpp"

using namespace std;

enum moves { HIT, STAND, DOUBLE, SPLIT, SURRENDER };

map<int, map<string, moves>> hard_totals = {
    { 21, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", STAND }, { "8", STAND }, { "9", STAND }, { "10", STAND }, { "A", STAND } }},
    { 20, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", STAND }, { "8", STAND }, { "9", STAND }, { "10", STAND }, { "A", STAND } }},
    { 19, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", STAND }, { "8", STAND }, { "9", STAND }, { "10", STAND }, { "A", STAND } }},
    { 18, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", STAND }, { "8", STAND }, { "9", STAND }, { "10", STAND }, { "A", STAND } }},
    { 17, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", STAND }, { "8", STAND }, { "9", STAND }, { "10", STAND }, { "A", STAND } }},
    { 16, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", HIT }, { "8", HIT }, { "9", SURRENDER }, { "10", SURRENDER }, { "A", SURRENDER } }},
    { 15, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", SURRENDER }, { "A", HIT } }},
    { 14, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
    { 13, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
    { 12, { { "2", HIT }, { "3", HIT }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
    { 11, { { "2", DOUBLE }, { "3", DOUBLE }, { "4", DOUBLE }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", DOUBLE }, { "8", DOUBLE }, { "9", DOUBLE }, { "10", DOUBLE }, { "A", DOUBLE } }},
    { 10, { { "2", DOUBLE }, { "3", DOUBLE }, { "4", DOUBLE }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", DOUBLE }, { "8", DOUBLE }, { "9", DOUBLE }, { "10", HIT }, { "A", HIT } }},
    { 9, { { "2", HIT }, { "3", DOUBLE }, { "4", DOUBLE }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
    { 8, { { "2", HIT }, { "3", HIT }, { "4", HIT }, { "5", HIT }, { "6", HIT }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
    { 7, { { "2", HIT }, { "3", HIT }, { "4", HIT }, { "5", HIT }, { "6", HIT }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
    { 6, { { "2", HIT }, { "3", HIT }, { "4", HIT }, { "5", HIT }, { "6", HIT }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
    { 5, { { "2", HIT }, { "3", HIT }, { "4", HIT }, { "5", HIT }, { "6", HIT }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
    { 4, { { "2", HIT }, { "3", HIT }, { "4", HIT }, { "5", HIT }, { "6", HIT }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }}
};

map<int, map<string, moves>> soft_totals = {
    { 21, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", STAND }, { "8", STAND }, { "9", STAND }, { "10", STAND }, { "A", STAND } }},
    { 20, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", STAND }, { "8", STAND }, { "9", STAND }, { "10", STAND }, { "A", STAND } }},
    { 19, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", DOUBLE }, { "7", STAND }, { "8", STAND }, { "9", STAND }, { "10", STAND }, { "A", STAND } }},
    { 18, { { "2", DOUBLE }, { "3", DOUBLE }, { "4", DOUBLE }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", STAND }, { "8", STAND }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
    { 17, { { "2", HIT }, { "3", DOUBLE }, { "4", DOUBLE }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
    { 16, { { "2", HIT }, { "3", HIT }, { "4", DOUBLE }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
    { 15, { { "2", HIT }, { "3", HIT }, { "4", DOUBLE }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
    { 14, { { "2", HIT }, { "3", HIT }, { "4", HIT }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
    { 13, { { "2", HIT }, { "3", HIT }, { "4", HIT }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }}
};

map<string, map<string, bool>> splitting = {
    { "A", { { "2", true }, { "3", true }, { "4", true }, { "5", true }, { "6", true }, { "7", true }, { "8", true }, { "9", true }, { "10", true }, { "A", true } }},
    { "10", { { "2", false }, { "3", false }, { "4", false }, { "5", false }, { "6", false }, { "7", false }, { "8", false }, { "9", false }, { "10", false }, { "A", false } }},
    { "9", { { "2", true }, { "3", true }, { "4", true }, { "5", true }, { "6", true }, { "7", false }, { "8", true }, { "9", true }, { "10", false }, { "A", false } }},
    { "8", { { "2", true }, { "3", true }, { "4", true }, { "5", true }, { "6", true }, { "7", true }, { "8", true }, { "9", true }, { "10", true }, { "A", true } }},
    { "7", { { "2", true }, { "3", true }, { "4", true }, { "5", true }, { "6", true }, { "7", true }, { "8", false }, { "9", false }, { "10", false }, { "A", false } }},
    { "6", { { "2", NULL }, { "3", true }, { "4", true }, { "5", true }, { "6", true }, { "7", false }, { "8", false }, { "9", false }, { "10", false }, { "A", false } }},
    { "5", { { "2", false }, { "3", false }, { "4", false }, { "5", false }, { "6", false }, { "7", false }, { "8", false }, { "9", false }, { "10", false }, { "A", false } }},
    { "4", { { "2", false }, { "3", false }, { "4", false }, { "5", NULL }, { "6", NULL }, { "7", false }, { "8", false }, { "9", false }, { "10", false }, { "A", false } }},
    { "3", { { "2", NULL }, { "3", NULL }, { "4", true }, { "5", true }, { "6", true }, { "7", true }, { "8", false }, { "9", false }, { "10", false }, { "A", false } }},
    { "2", { { "2", NULL }, { "3", NULL }, { "4", true }, { "5", true }, { "6", true }, { "7", true }, { "8", false }, { "9", false }, { "10", false }, { "A", false } }}
};

map<string, int> hi_lo = {
    {"2", 1}, {"3", 1}, {"4", 1}, {"5", 1}, {"6", 1}, {"7", 0}, {"8", 0}, {"9", 0}, {"10", -1}, {"A", -1}
};

class Player
{
    private:

        int bankroll;
        int running_count;
        vector<vector<string>> hands;

        Shoe *shoe;
        RuleBook *rules;
        ScoreHelper score_helper;

        void complete_hand(string, vector<string>);
        int get_true_count();


    public:

        Player(int bankroll, Shoe *shoe, RuleBook *rules) : bankroll(bankroll), shoe(shoe), rules(rules), running_count(0) {}

        void play_hand(string, vector<string>, int);
        int get_bankroll();
        // void deal(vector<string>);
        int make_bet(int);
        vector<vector<string>> get_hands();
        void payout(int);
        void update_count(vector<string>);

};

int Player::get_bankroll() {
    return bankroll;
}

// void Player::deal(vector<string> new_hand) {
//     hands = { new_hand }; 
// }

vector<vector<string>> Player::get_hands() {
    return hands;
}

void Player::play_hand(string dealer_upcard, vector<string> hand, int depth) {

    bool aces = hand[0] == "A" && hand[1] == "A" && depth > 0; // Cannot resplit aces
    bool below_max_splits = hands.size() < rules->get_resplit_limit(); 
    bool can_split = hand[0] == hand[1] && !aces && below_max_splits;
    if (can_split) {

        bool should_split = splitting[hand[0]][dealer_upcard];
        if (should_split == NULL) {
            should_split = rules->get_das();
        }

        if (should_split) {
            vector<string> new_hand_first = { hand[0], shoe->draw() }; 
            vector<string> new_hand_second = { hand[1], shoe->draw() }; 
            play_hand(dealer_upcard, new_hand_first, ++depth);
            play_hand(dealer_upcard, new_hand_second, ++depth);
        }

    } else {
        complete_hand(dealer_upcard, hand);
        hands.push_back(hand);
    }

}

/*void Player::complete_hand(string dealer_upcard, hand) {
    bool aces = hand[0] == "A" && hand[1] == "A"; // Cannot resplit aces
    bool below_max_splits = hands.size() < rules->get_resplit_limit(); 
    bool can_split = hand[0] == hand[1] && !aces && below_max_splits;
    if (can_split) {

        bool should_split = splitting[hand[0]][dealer_upcard];
        if (should_split == NULL && rules->get_das()) {
            should_split = true;
        }

        if (should_split) {
            hands.erase(hands.begin() + hand_index);
            string new_card_first = shoe->draw();
            string new_card_second = shoe->draw();
            hands.push_back({ hand[0], new_card_first });
            hands.push_back({ hand[1], new_card_second });
            complete_hand()
        }

    } 

    tuple<int, bool> score = score_helper.calculate_hand_score(hand);
    tuple<int, bool> score = score
    moves move;
    if (score[1] == true) {
        move = soft_totals[score[0]];
    } else {
        move = hard_totals[score[0]];
    }
    switch (move) {
        case DOUBLE:

            break;
        case STAND:
            return;
        case SURRENDER:
            // return with special something?
            break;
        case HIT:
            return complete
        defabreak
        default:w invalid_argument( "NO CASE FOR MOVE" )
    } int hathrow invalid_argument( "NO CASE FOR MOVE" )
}*/

int Player::make_bet(int betting_unit) {

    int bet = betting_unit;
    int true_count = get_true_count(); 

    // Basic bet spread
    if (true_count > 1 && true_count <= 5) {
        betting_unit *= true_count;
    } else if (true_count > 5) {
        betting_unit *= 5;
    }

    if (bankroll < bet) {
        bet = bankroll;
    }

    bankroll -= bet;
    return bet;
}

int Player::get_true_count() {
    int shoe_size = shoe->get_shoe_size();
    float true_count = floor((float)running_count / (float)shoe_size);
    return (int)true_count;
}

void Player::payout(int cash) {
    bankroll += cash;


void Player::update_count(vector<string> dealer_hand) {
    map <string, int> count_map = hi_lo;
    for (int i = 0; i < dealer_hand.size(); i++) {
        running_count += count_map[dealer_hand[i]];
    }
    for (int i = 0; i < hands.size(); i++) {
        for (int j = 0; j < hands[i].size(); j++) {
            running_count += count_map[hands[i][j]];
        }
    }
}

#endif
