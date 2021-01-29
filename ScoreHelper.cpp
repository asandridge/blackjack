#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>

#include "ScoreHelper.hpp"
#include "Moves.hpp"

using namespace std;

map<int, map<string, moves::moves>> hard_totals = {
    { 21, { { "2", moves::STAND }, { "3", moves::STAND }, { "4", moves::STAND }, { "5", moves::STAND }, { "6", moves::STAND }, { "7", moves::STAND }, { "8", moves::STAND }, { "9", moves::STAND }, { "10", moves::STAND }, { "A", moves::STAND } }},
    { 20, { { "2", moves::STAND }, { "3", moves::STAND }, { "4", moves::STAND }, { "5", moves::STAND }, { "6", moves::STAND }, { "7", moves::STAND }, { "8", moves::STAND }, { "9", moves::STAND }, { "10", moves::STAND }, { "A", moves::STAND } }},
    { 19, { { "2", moves::STAND }, { "3", moves::STAND }, { "4", moves::STAND }, { "5", moves::STAND }, { "6", moves::STAND }, { "7", moves::STAND }, { "8", moves::STAND }, { "9", moves::STAND }, { "10", moves::STAND }, { "A", moves::STAND } }},
    { 18, { { "2", moves::STAND }, { "3", moves::STAND }, { "4", moves::STAND }, { "5", moves::STAND }, { "6", moves::STAND }, { "7", moves::STAND }, { "8", moves::STAND }, { "9", moves::STAND }, { "10", moves::STAND }, { "A", moves::STAND } }},
    { 17, { { "2", moves::STAND }, { "3", moves::STAND }, { "4", moves::STAND }, { "5", moves::STAND }, { "6", moves::STAND }, { "7", moves::STAND }, { "8", moves::STAND }, { "9", moves::STAND }, { "10", moves::STAND }, { "A", moves::STAND } }},
    { 16, { { "2", moves::STAND }, { "3", moves::STAND }, { "4", moves::STAND }, { "5", moves::STAND }, { "6", moves::STAND }, { "7", moves::HIT }, { "8", moves::HIT }, { "9", moves::SURRENDER }, { "10", moves::SURRENDER }, { "A", moves::SURRENDER } }},
    { 15, { { "2", moves::STAND }, { "3", moves::STAND }, { "4", moves::STAND }, { "5", moves::STAND }, { "6", moves::STAND }, { "7", moves::HIT }, { "8", moves::HIT }, { "9", moves::HIT }, { "10", moves::SURRENDER }, { "A", moves::HIT } }},
    { 14, { { "2", moves::STAND }, { "3", moves::STAND }, { "4", moves::STAND }, { "5", moves::STAND }, { "6", moves::STAND }, { "7", moves::HIT }, { "8", moves::HIT }, { "9", moves::HIT }, { "10", moves::HIT }, { "A", moves::HIT } }},
    { 13, { { "2", moves::STAND }, { "3", moves::STAND }, { "4", moves::STAND }, { "5", moves::STAND }, { "6", moves::STAND }, { "7", moves::HIT }, { "8", moves::HIT }, { "9", moves::HIT }, { "10", moves::HIT }, { "A", moves::HIT } }},
    { 12, { { "2", moves::HIT }, { "3", moves::HIT }, { "4", moves::STAND }, { "5", moves::STAND }, { "6", moves::STAND }, { "7", moves::HIT }, { "8", moves::HIT }, { "9", moves::HIT }, { "10", moves::HIT }, { "A", moves::HIT } }},
    { 11, { { "2", moves::DOUBLE }, { "3", moves::DOUBLE }, { "4", moves::DOUBLE }, { "5", moves::DOUBLE }, { "6", moves::DOUBLE }, { "7", moves::DOUBLE }, { "8", moves::DOUBLE }, { "9", moves::DOUBLE }, { "10", moves::DOUBLE }, { "A", moves::DOUBLE } }},
    { 10, { { "2", moves::DOUBLE }, { "3", moves::DOUBLE }, { "4", moves::DOUBLE }, { "5", moves::DOUBLE }, { "6", moves::DOUBLE }, { "7", moves::DOUBLE }, { "8", moves::DOUBLE }, { "9", moves::DOUBLE }, { "10", moves::HIT }, { "A", moves::HIT } }},
    { 9, { { "2", moves::HIT }, { "3", moves::DOUBLE }, { "4", moves::DOUBLE }, { "5", moves::DOUBLE }, { "6", moves::DOUBLE }, { "7", moves::HIT }, { "8", moves::HIT }, { "9", moves::HIT }, { "10", moves::HIT }, { "A", moves::HIT } }},
    { 8, { { "2", moves::HIT }, { "3", moves::HIT }, { "4", moves::HIT }, { "5", moves::HIT }, { "6", moves::HIT }, { "7", moves::HIT }, { "8", moves::HIT }, { "9", moves::HIT }, { "10", moves::HIT }, { "A", moves::HIT } }},
    { 7, { { "2", moves::HIT }, { "3", moves::HIT }, { "4", moves::HIT }, { "5", moves::HIT }, { "6", moves::HIT }, { "7", moves::HIT }, { "8", moves::HIT }, { "9", moves::HIT }, { "10", moves::HIT }, { "A", moves::HIT } }},
    { 6, { { "2", moves::HIT }, { "3", moves::HIT }, { "4", moves::HIT }, { "5", moves::HIT }, { "6", moves::HIT }, { "7", moves::HIT }, { "8", moves::HIT }, { "9", moves::HIT }, { "10", moves::HIT }, { "A", moves::HIT } }},
    { 5, { { "2", moves::HIT }, { "3", moves::HIT }, { "4", moves::HIT }, { "5", moves::HIT }, { "6", moves::HIT }, { "7", moves::HIT }, { "8", moves::HIT }, { "9", moves::HIT }, { "10", moves::HIT }, { "A", moves::HIT } }},
    { 4, { { "2", moves::HIT }, { "3", moves::HIT }, { "4", moves::HIT }, { "5", moves::HIT }, { "6", moves::HIT }, { "7", moves::HIT }, { "8", moves::HIT }, { "9", moves::HIT }, { "10", moves::HIT }, { "A", moves::HIT } }}
};

map<int, map<string, moves::moves>> soft_totals = {
    { 21, { { "2", moves::STAND }, { "3", moves::STAND }, { "4", moves::STAND }, { "5", moves::STAND }, { "6", moves::STAND }, { "7", moves::STAND }, { "8", moves::STAND }, { "9", moves::STAND }, { "10", moves::STAND }, { "A", moves::STAND } }},
    { 20, { { "2", moves::STAND }, { "3", moves::STAND }, { "4", moves::STAND }, { "5", moves::STAND }, { "6", moves::STAND }, { "7", moves::STAND }, { "8", moves::STAND }, { "9", moves::STAND }, { "10", moves::STAND }, { "A", moves::STAND } }},
    { 19, { { "2", moves::STAND }, { "3", moves::STAND }, { "4", moves::STAND }, { "5", moves::STAND }, { "6", moves::DOUBLE }, { "7", moves::STAND }, { "8", moves::STAND }, { "9", moves::STAND }, { "10", moves::STAND }, { "A", moves::STAND } }},
    { 18, { { "2", moves::DOUBLE }, { "3", moves::DOUBLE }, { "4", moves::DOUBLE }, { "5", moves::DOUBLE }, { "6", moves::DOUBLE }, { "7", moves::STAND }, { "8", moves::STAND }, { "9", moves::HIT }, { "10", moves::HIT }, { "A", moves::HIT } }},
    { 17, { { "2", moves::HIT }, { "3", moves::DOUBLE }, { "4", moves::DOUBLE }, { "5", moves::DOUBLE }, { "6", moves::DOUBLE }, { "7", moves::HIT }, { "8", moves::HIT }, { "9", moves::HIT }, { "10", moves::HIT }, { "A", moves::HIT } }},
    { 16, { { "2", moves::HIT }, { "3", moves::HIT }, { "4", moves::DOUBLE }, { "5", moves::DOUBLE }, { "6", moves::DOUBLE }, { "7", moves::HIT }, { "8", moves::HIT }, { "9", moves::HIT }, { "10", moves::HIT }, { "A", moves::HIT } }},
    { 15, { { "2", moves::HIT }, { "3", moves::HIT }, { "4", moves::DOUBLE }, { "5", moves::DOUBLE }, { "6", moves::DOUBLE }, { "7", moves::HIT }, { "8", moves::HIT }, { "9", moves::HIT }, { "10", moves::HIT }, { "A", moves::HIT } }},
    { 14, { { "2", moves::HIT }, { "3", moves::HIT }, { "4", moves::HIT }, { "5", moves::DOUBLE }, { "6", moves::DOUBLE }, { "7", moves::HIT }, { "8", moves::HIT }, { "9", moves::HIT }, { "10", moves::HIT }, { "A", moves::HIT } }},
    { 13, { { "2", moves::HIT }, { "3", moves::HIT }, { "4", moves::HIT }, { "5", moves::DOUBLE }, { "6", moves::DOUBLE }, { "7", moves::HIT }, { "8", moves::HIT }, { "9", moves::HIT }, { "10", moves::HIT }, { "A", moves::HIT } }}
};


tuple<int, bool> ScoreHelper::calculate_hand_score(vector<string> hand) {

    int sum = 0;
    bool first_ace = false;

    for (int i = 0; i < hand.size(); i++) {
       if (hand[i] == "A") {
           if (!first_ace) {
               sum += 11;
               first_ace = true;
           } else {
               sum += 1;
           }
       } else {
           sum += stoi(hand[i]);
       }
    }

    bool is_soft_hand = first_ace && sum <= 21 && sum > 12; // a 'soft 12' would be two aces, and should be counted as a hard 12

    return { sum, is_soft_hand };

}

moves::moves ScoreHelper::determine_hand_move(string dealer_upcard, vector<string> player_hand) {

    tuple<int, bool> player_hand_score = calculate_hand_score(player_hand);

    bool is_soft_hand = get<1>(player_hand_score);
    map<int, map<string, moves::moves>> strategy_chart = is_soft_hand ? soft_totals : hard_totals;

    return strategy_chart[get<0>(player_hand_score)][dealer_upcard];

}

int ScoreHelper::calculate_refund(vector<string> dealer_hand, vector<string> player_hand, int blackjack_payout) {

    tuple<int, bool> dealer_score = calculate_hand_score(dealer_hand);
    tuple<int, bool> player_score = calculate_hand_score(player_hand);

    int dealer_count = get<0>(dealer_score);
    int player_count = get<0>(player_score);

    bool dealer_blackjack = dealer_count == 21 && get<1>(dealer_score);
    bool player_blackjack = player_count == 21 && get<1>(player_score);

    if (player_blackjack) { 
        if (!dealer_blackjack) {
            return 1 + blackjack_payout;
        } else {
            return 1; // tie
        }
    } else if (player_count > dealer_count) {
        return 2;
    } else if (player_count == dealer_count) {
        return 1;
    } else {
        return 0;
    }
}