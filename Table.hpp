#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

#include "Player.hpp"
#include "Dealer.hpp"
#include "Shoe.hpp"
#include "ScoreHelper.hpp"

using namespace std;

class Table
{
    private:

        int betting_unit;

        Player player;
        Dealer dealer;
        Shoe shoe;
        RuleBook rules;
        ScoreHelper score_helper;

        void finish_round(int);
        void refund_bets(int, tuple<int, bool>, tuple<int, bool>);

    public:

        Table(RuleBook *rules) :
            rules(*rules),
            shoe(Shoe(rules->get_decks())),
            player(1000, &shoe, rules),
            dealer(&shoe, rules, &player),
            betting_unit(10)
            {}

        int play_round();
        void print_hands();
};

int Table::play_round() {
    int bet = player.make_bet(betting_unit);
    if (bet != 0) {
        vector<string> player_hand = dealer.deal();
        //print_hands();
        player.play_hand(dealer.get_up_card(), player_hand, 0);
        dealer.complete_hand();
        finish_round(bet);
    }
    return player.get_bankroll();
}

void Table::print_hands() {
    cout << "Dealer: { *, " << (dealer.get_up_card()) << " }" << endl;
    cout << "Player: ";
    vector<vector<string>> player_cards = player.get_hands();
    for (int i = 0; i < player_cards.size(); i++) {
        cout << "{ ";
        for (int j = 0; j < player_cards[i].size(); j++) {
           cout << player_cards[i][j]; 
           cout << (j == player_cards[i].size() - 1 ? "" : ", ");
        }
        cout << " }" << endl << endl;
    }
}

void Table::finish_round(int bet) {

    vector<string> dealer_hand = dealer.get_hand();
    vector<vector<string>> player_hands = player.get_hands();
    tuple<int, bool> dealer_score = score_helper.calculate_hand_score(dealer_hand);

    for (int i = 0; i < player_hands.size(); i++) {
        tuple<int, bool> hand_score = score_helper.calculate_hand_score(player_hands[i]);
        refund_bets(bet, dealer_score, hand_score);
    }

    player.update_count(dealer_hand);
}

void Table::refund_bets(int bet, tuple<int, bool> dealer_score, tuple<int, bool> player_score) {

    int dealer_count = get<0>(dealer_score);
    int player_count = get<0>(player_score);
    bool dealer_blackjack = dealer_count == 21 && get<1>(dealer_score);
    bool player_blackjack = player_count == 21 && get<1>(player_score);

    if (player_blackjack) { 
        if (!dealer_blackjack) {
            player.payout(bet + bet * rules.get_blackjack_payout());
        } else {
            player.payout(bet);
        }
    } else if (player_count > dealer_count) {
        player.payout(bet * 2);
    } else if (player_count == dealer_count) {
        player.payout(bet);
    }
}

#endif
