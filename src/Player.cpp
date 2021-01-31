#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h>
#include <tuple>

#include "../include/Player.hpp"
#include "../include/Strategy.hpp"

using namespace std;

int Player::get_bankroll() {
    return bankroll;
}

void Player::deal() {
    hands = {}; 
}

vector<tuple<vector<string>, int>> Player::get_hands() {
    return hands;
}

void Player::play_hand(string dealer_upcard, vector<string> hand, int depth) {

    bool aces = hand[0] == "A" && hand[1] == "A" && depth > 0; // Cannot resplit aces
    bool below_max_splits = hands.size() < rules->get_resplit_limit(); 
    bool can_split = hand[0] == hand[1] && !aces && below_max_splits;
    if (can_split) {

        strategy::splitting_moves should_split = strategy::splitting_strategy[hand[0]][dealer_upcard];
        if (should_split == strategy::SPLIT_DAS && rules->get_das()) {
            should_split = strategy::SPLIT_TRUE;
        }

        if (should_split == strategy::SPLIT_TRUE) {
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

    strategy::moves move = score_helper.determine_hand_move(dealer_upcard, *hand);

    bool cannot_double = !rules->get_das() && after_split;
    bool cannot_surrender = !hand_first_move; 
    if ((move == strategy::DOUBLE && cannot_double) ||
        (move == strategy::SURRENDER && cannot_surrender)) { // default to hit if current move is not allowed based on current game state
        move = strategy::HIT;
    }

    switch (move) {
        case strategy::DOUBLE:
            cout << "DOUBLE" << endl;
            hit(hand);
            return 2;
        case strategy::SURRENDER:
            cout << "SURRENDER" << endl;
            return -1;
        case strategy::STAND:
            cout << "STAND" << endl;
            return 1;
        case strategy::HIT:
            cout << "HIT" << endl;
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

int Player::place_bet(int betting_unit) {

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

    map <string, int> count_map = rules->get_counting_strategy();

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