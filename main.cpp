#include <iostream>
#include <vector>
#include <string>
#include "RuleBook.hpp"
#include "Table.hpp"

using namespace std;

int main() {

    string max_hands;
    cout << "How many hands do you want to play?" << endl;
    cin >> max_hands;
    while (stoi(max_hands) < 1) {
        cout << "Please enter a positive integer" << endl;
        cin >> max_hands;
    }

    RuleBook rule_book;
    rule_book.set_rules();
    rule_book.print_rules();
    RuleBook *rules = &rule_book;

    Table table(rules);

    int hands = 0;
    int player_bankroll;
    while (hands < stoi(max_hands)) {
        player_bankroll = table.play_round();
        hands++;
    }

    cout << "Final Player Bankroll: " << player_bankroll << endl;

    return 0;
};
