#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h
#include <tuple>

#include "Player.hpp"
#include "Moves.hpp"

using namespace std;

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

int Player::get_bankroll() {
    return bankroll;
}

// void Player::deal(vector<string> new_hand) {
//     hands = { new_hand }; 
// }

vector<tuple<vector<string>, int>> Player::get_hands() {
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
        bool after_split = depth > 0;
        int bet = complete_hand(dealer_upcard, &hand, after_split, true);
        hands.push_back({ hand, bet });
    }

}

int Player::complete_hand(string dealer_upcard, vector<string> *hand, bool after_split, bool hand_first_move) {

    moves::moves move = score_helper.determine_hand_move(dealer_upcard, *hand);

    bool cannot_double = !rules->get_das() && after_split;
    bool cannot_surrender = !hand_first_move; 
    if ((move == DOUBLE && cannot_double) ||
        (move == SURRENDER && cannot_surrender)) { // default to hit if current move is not allowed based on current game state
        move = moves::HIT;
    }

    switch (move) {
        case DOUBLE:
            hit(hand);
            return 2;
        case SURRENDER:
            return 0;
        case STAND:
            return 1;
        case HIT:
            hit(hand);
            return complete_hand(dealer_upcard, hand, after_split, false);
        default:
            throw invalid_argument( "NO CASE FOR DETERMINED MOVE" );
    }
}

void Player::hit(vector<string> *hand) {
    string new_card = shoe->draw();
    hand->push_back(new_card);
}

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
}

void Player::update_running_count(vector<string> dealer_hand) {

    map <string, int> count_map;
    if (rules->get_counting_strategy() == "Hi-Lo") {
        count_map = hi_lo;
    } else {
        count_map = hi_lo;
    }

    for (int i = 0; i < dealer_hand.size(); i++) {
        running_count += count_map[dealer_hand[i]];
    }
    for (int i = 0; i < hands.size(); i++) {
        vector<string> hand_cards = get<0>(hands[i]);
        for (int j = 0; j < hand_cards.size(); j++) {
            running_count += count_map[hand_cards[j]];
        }
    }
}