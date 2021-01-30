#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h>
#include <tuple>

#include "../include/Player.hpp"
#include "../include/Moves.hpp"

using namespace std;

map<string, map<string, moves::splitting>> splitting = {
    { "A", { { "2", moves::SPLIT_TRUE }, { "3", moves::SPLIT_TRUE }, { "4", moves::SPLIT_TRUE }, { "5", moves::SPLIT_TRUE }, { "6", moves::SPLIT_TRUE }, { "7", moves::SPLIT_TRUE }, { "8", moves::SPLIT_TRUE }, { "9", moves::SPLIT_TRUE }, { "10", moves::SPLIT_TRUE }, { "A", true } }},
    { "10", { { "2", moves::SPLIT_FALSE }, { "3", moves::SPLIT_FALSE }, { "4", moves::SPLIT_FALSE }, { "5", moves::SPLIT_FALSE }, { "6", moves::SPLIT_FALSE }, { "7", moves::SPLIT_FALSE }, { "8", moves::SPLIT_FALSE }, { "9", moves::SPLIT_FALSE }, { "10", moves::SPLIT_FALSE }, { "A", false } }},
    { "9", { { "2", moves::SPLIT_TRUE }, { "3", moves::SPLIT_TRUE }, { "4", moves::SPLIT_TRUE }, { "5", moves::SPLIT_TRUE }, { "6", moves::SPLIT_TRUE }, { "7", moves::SPLIT_FALSE }, { "8", moves::SPLIT_TRUE }, { "9", moves::SPLIT_TRUE }, { "10", moves::SPLIT_FALSE }, { "A", false } }},
    { "8", { { "2", moves::SPLIT_TRUE }, { "3", moves::SPLIT_TRUE }, { "4", moves::SPLIT_TRUE }, { "5", moves::SPLIT_TRUE }, { "6", moves::SPLIT_TRUE }, { "7", moves::SPLIT_TRUE }, { "8", moves::SPLIT_TRUE }, { "9", moves::SPLIT_TRUE }, { "10", moves::SPLIT_TRUE }, { "A", true } }},
    { "7", { { "2", moves::SPLIT_TRUE }, { "3", moves::SPLIT_TRUE }, { "4", moves::SPLIT_TRUE }, { "5", moves::SPLIT_TRUE }, { "6", moves::SPLIT_TRUE }, { "7", moves::SPLIT_TRUE }, { "8", moves::SPLIT_FALSE }, { "9", moves::SPLIT_FALSE }, { "10", moves::SPLIT_FALSE }, { "A", false } }},
    { "6", { { "2", moves::SPLIT_DAS }, { "3", moves::SPLIT_TRUE }, { "4", moves::SPLIT_TRUE }, { "5", moves::SPLIT_TRUE }, { "6", moves::SPLIT_TRUE }, { "7", moves::SPLIT_FALSE }, { "8", moves::SPLIT_FALSE }, { "9", moves::SPLIT_FALSE }, { "10", moves::SPLIT_FALSE }, { "A", false } }},
    { "5", { { "2", moves::SPLIT_FALSE }, { "3", moves::SPLIT_FALSE }, { "4", moves::SPLIT_FALSE }, { "5", moves::SPLIT_FALSE }, { "6", moves::SPLIT_FALSE }, { "7", moves::SPLIT_FALSE }, { "8", moves::SPLIT_FALSE }, { "9", moves::SPLIT_FALSE }, { "10", moves::SPLIT_FALSE }, { "A", false } }},
    { "4", { { "2", moves::SPLIT_FALSE }, { "3", moves::SPLIT_FALSE }, { "4", moves::SPLIT_FALSE }, { "5", moves::SPLIT_DAS }, { "6", moves::SPLIT_DAS }, { "7", moves::SPLIT_FALSE }, { "8", moves::SPLIT_FALSE }, { "9", moves::SPLIT_FALSE }, { "10", moves::SPLIT_FALSE }, { "A", false } }},
    { "3", { { "2", moves::SPLIT_DAS }, { "3", moves::SPLIT_DAS }, { "4", moves::SPLIT_TRUE }, { "5", moves::SPLIT_TRUE }, { "6", moves::SPLIT_TRUE }, { "7", moves::SPLIT_TRUE }, { "8", moves::SPLIT_FALSE }, { "9", moves::SPLIT_FALSE }, { "10", moves::SPLIT_FALSE }, { "A", false } }},
    { "2", { { "2", moves::SPLIT_DAS }, { "3", moves::SPLIT_DAS }, { "4", moves::SPLIT_TRUE }, { "5", moves::SPLIT_TRUE }, { "6", moves::SPLIT_TRUE }, { "7", moves::SPLIT_TRUE }, { "8", moves::SPLIT_FALSE }, { "9", moves::SPLIT_FALSE }, { "10", moves::SPLIT_FALSE }, { "A", false } }}
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

        moves::splitting should_split = splitting[hand[0]][dealer_upcard];
        if (should_split == moves::SPLIT_DAS && rules->get_das()) {
            should_split = moves::SPLIT_TRUE;
        }

        if (should_split == moves::SPLIT_TRUE) {
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
    if ((move == moves::DOUBLE && cannot_double) ||
        (move == moves::SURRENDER && cannot_surrender)) { // default to hit if current move is not allowed based on current game state
        move = moves::HIT;
    }

    switch (move) {
        case moves::DOUBLE:
            hit(hand);
            return 2;
        case moves::SURRENDER:
            return 0;
        case moves::STAND:
            return 1;
        case moves::HIT:
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
    vector<string> hand_cards;
    for (int i = 0; i < hands.size(); i++) {
        hand_cards = get<0>(hands[i]);
        for (int j = 0; j < hand_cards.size(); j++) {
            running_count += count_map[hand_cards[j]];
        }
    }
}