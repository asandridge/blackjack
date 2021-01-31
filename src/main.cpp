#include <iostream>
#include <vector>
#include <string>
#include <regex>

#include "RuleBook.cpp"
#include "Table.cpp"

using namespace std;

int main() {

    string max_hands;
    cout << "How many hands do you want to play?" << endl;
    cin >> max_hands;
    regex regex_pattern("[0-9]+");
    while (!regex_match(max_hands, regex_pattern)) {
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
        cout << "========= Round: " << (hands + 1) << " =========" << endl << endl;
        player_bankroll = table.play_round();
        cout << "Bankroll: " << player_bankroll << endl << endl;
        hands++;
    }

    cout << "Final Player Bankroll: " << player_bankroll << endl;

    return 0;
};
