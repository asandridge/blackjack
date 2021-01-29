#include <iostream>
#include <vector>
#include <string>
#include <tuple>

#include "Table.hpp"

using namespace std;

int Table::play_round() {

    int bet = player.make_bet(betting_unit);

    if (bet != 0) {
        vector<string> player_hand = dealer.deal();
        //print_hands();
        player.play_hand(dealer.get_up_card(), player_hand, 0);
        dealer.play_hand();
        dealer.make_refunds(bet);
        player.update_running_count(dealer.get_hand());
    }

    return player.get_bankroll();

}

void Table::print_table() {
    cout << "Dealer: { *, " << (dealer.get_up_card()) << " }" << endl;
    cout << "Player: ";
    vector<tuple<vector<string>, int>> player_hands = player.get_hands();
    for (int i = 0; i < player_hands.size(); i++) {
        cout << "{ ";
        vector<string> player_cards = get<0>(player_hands[i]);
        for (int j = 0; j < player_cards.size(); j++) {
           cout << player_cards[i][j]; 
           cout << (j == player_cards[i].size() - 1 ? "" : ", ");
        }
        cout << " }" << endl << endl;
    }
}
