#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

#include "RuleBook.cpp"
#include "Table.cpp"

using namespace std;

int main() {

    RuleBook rule_book;
    rule_book.print_rules();
    RuleBook *rules = &rule_book;

    Table table(rules);

    int round = 0;
    int total_rounds = rules->get_rounds();
    int average_advantage = 0;
    int round_advantage;

    for (int i = 0; i < total_rounds; i++) {

        // cout << "========= Round: " << (round + 1) << " =========" << endl << endl;

        for (int j = 0; j < 1; j++) {
            table.play_round();
        }

        round_advantage = table.get_player_bankroll() - 100; // Note: this assumes the player starts with $100

        average_advantage += round_advantage;

        table.reset();

    }

    average_advantage /= total_rounds;
    cout << "House Edge: " << -(average_advantage) << endl;

    return 0;
};
