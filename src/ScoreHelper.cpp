#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>

#include "../include/ScoreHelper.hpp"
#include "../include/Strategy.hpp"

using namespace std;

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

    if (sum > 21) sum = 0;
    bool is_soft_hand = first_ace && sum <= 21 && sum > 12; // a 'soft 12' would be two aces, and should be counted as a hard 12

    return { sum, is_soft_hand };

}

strategy::moves ScoreHelper::determine_hand_move(string dealer_upcard, vector<string> player_hand) {

    tuple<int, bool> player_hand_score = calculate_hand_score(player_hand);

    bool is_soft_hand = get<1>(player_hand_score);
    map<int, map<string, strategy::moves>> strategy_chart = is_soft_hand ? strategy::soft_totals : strategy::hard_totals;

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
    } else if (player_count == dealer_count && player_count != 0) { // player loses automatically on bust
        return 1;
    } else {
        return 0;
    }
}