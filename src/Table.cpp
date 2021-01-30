#include <iostream>
#include <vector>
#include <string>
#include <tuple>

#include "../include/Table.hpp"

using namespace std;

int Table::play_round() {

    int bet = player.make_bet(betting_unit);

    if (bet != 0) {
        vector<string> player_hand = dealer.deal();
        print_table({ { player_hand, 0 } });
        player.play_hand(dealer.get_up_card(), player_hand, 0);
        dealer.play_hand();
        print_table(player.get_hands());
        dealer.make_refunds(bet);
        player.update_running_count(dealer.get_hand());
    }

    return player.get_bankroll();

}

void Table::print_table(vector<tuple<vector<string>, int>> player_hands) {
    cout << "Player: ";
    vector<string> player_cards;
    for (int i = 0; i < player_hands.size(); i++) {
        cout << "{ ";
        player_cards = get<0>(player_hands[i]);
        for (int j = 0; j < player_cards.size(); j++) {
           cout << player_cards[j]; 
           cout << (j == player_cards.size() - 1 ? "" : ", ");
        }
        cout << " }";
    }
    cout << endl << endl;
    vector<string> dealer_hand = dealer.get_hand();
    cout << "Dealer: { ";
    for (int i = 0; i < dealer_hand.size(); i++) {
        if (i == 0) cout << "*";
        cout << dealer_hand[i];
        cout << (i == dealer_hand.size() - 1 ? "" : ", ");
    }
    cout << " }" << endl << endl;
}
