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
    int aces = 0;
    bool is_soft_hand = false;

    for (int i = 0; i < hand.size(); i++) { // Hard totals
        if (hand[i] == "A") {
            aces++;
        } else {
            sum += stoi(hand[i]);
        }
    }

    if (sum + 11 + aces - 1 <= 21) { // First ace can count as 11, soft hand
        sum += 11 + (aces - 1);
        is_soft_hand = true;
    } else {
        sum += aces;
    }

    if (sum > 21) sum = 0;

    return { sum, is_soft_hand };

}

strategy::moves ScoreHelper::determine_hand_move(string dealer_upcard, vector<string> player_hand) {

    tuple<int, bool> player_hand_score = calculate_hand_score(player_hand);
    cout << "Player hand score: " << get<0>(player_hand_score) << endl;
    cout << "Dealer upcard: " << dealer_upcard << endl;

    if (get<0>(player_hand_score) == 0) {
        return strategy::STAND;
    }

    bool is_soft_hand = get<1>(player_hand_score);
    map<int, map<string, strategy::moves>> strategy_chart = is_soft_hand ? strategy::soft_totals : strategy::hard_totals;

    return strategy_chart[get<0>(player_hand_score)][dealer_upcard];

}

int ScoreHelper::calculate_refund(vector<string> dealer_hand, vector<string> player_hand, int blackjack_payout) {

    tuple<int, bool> dealer_score = calculate_hand_score(dealer_hand);
    tuple<int, bool> player_score = calculate_hand_score(player_hand);

    int dealer_count = get<0>(dealer_score);
    int player_count = get<0>(player_score);

    cout << "Player Score: " << player_count << endl;
    cout << "Dealer Score: " << dealer_count << endl;

    bool dealer_blackjack = dealer_count == 21 && get<1>(dealer_score);
    bool player_blackjack = player_count == 21 && get<1>(player_score);

    if (player_count == 0) return -1; // player always loses on bust
    else if (player_blackjack && !dealer_blackjack) return blackjack_payout;
    else if (dealer_blackjack && !player_blackjack) return -1;
    else if (player_blackjack && dealer_blackjack) return 0; // two blackjacks tie
    else if (player_count > dealer_count) return 1;
    else if (player_count == dealer_count) return 0;
    else return -1;
}