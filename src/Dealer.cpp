#include <vector>
#include <string>
#include <tuple>

#include "../include/Dealer.hpp"

using namespace std;

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

void Dealer::play_hand() {

    tuple<int, bool> score = score_helper.calculate_hand_score(hand);
    int count = get<0>(score);
    bool is_soft_hand = get<1>(score);

    if (count < 17 || (count == 17 && is_soft_hand && rules->get_h17())) {
        hit();
        play_hand();
    }
    return;
}

void Dealer::make_refunds(int bet) {

    vector<tuple<vector<string>, int>> player_hands = player->get_hands();
    int blackjack_payout = rules->get_blackjack_payout();
    vector<string> cards;
    int in_game_bet;
    int refund_multiplier;

    for (int i = 0; i < player_hands.size(); i++) {
        cards = get<0>(player_hands[i]);
        in_game_bet = get<1>(player_hands[i]);
        refund_multiplier = score_helper.calculate_refund(hand, cards, blackjack_payout);
        player->payout(in_game_bet * refund_multiplier * bet);
    }

}