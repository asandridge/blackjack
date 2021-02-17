#include <vector>
#include <string>
#include <tuple>

#include "../include/Dealer.hpp"
#include "../include/Deck.hpp"
#include "../include/Strategy.hpp"

using namespace std;

void Dealer::deal() {
    if (shoe->get_shoe_size() < (rules->get_decks() * deck::deck_size) / 4) { // reshuffle at 75%
        shoe->reshuffle();
        player->reshuffle();
    }
    string dealer_first_card = shoe->draw();
    string dealer_second_card = shoe->draw();
    string player_first_card = shoe->draw();
    string player_second_card = shoe->draw();

    hand = { dealer_first_card, dealer_second_card };
    player->deal({ player_first_card, player_second_card });
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

    tuple<int, bool> score = strategy::calculate_hand_score(hand);
    int count = get<0>(score);
    bool is_soft_hand = get<1>(score);

    if ((count > 0 && count < 17) || (count == 17 && is_soft_hand && rules->get_h17())) {
        hit();
        play_hand();
    }
    return;
}

void Dealer::make_refunds(int bet) {

    vector<tuple<vector<string>, int>> player_hands = player->get_hands();
    int blackjack_payout = rules->get_blackjack_payout();
    vector<string> current_hand;
    int in_game_multiplier; // doubling and surrendering change the bet
    int refund_multiplier; // refund depends on blackjacks, ties, and wins

    for (int i = 0; i < player_hands.size(); i++) {
        current_hand = get<0>(player_hands[i]);
        in_game_multiplier = get<1>(player_hands[i]);
        if (in_game_multiplier < 0) { // this is a surrender
            player->payout(in_game_multiplier * bet);
        } else {
            refund_multiplier = strategy::calculate_refund(hand, current_hand, blackjack_payout);
            player->payout(in_game_multiplier * refund_multiplier * bet);
        }
    }

}
