#include <iostream>
#include <vector>
#include <string>
#include "RulesPrompt.hpp"
#include "Table.hpp"

using namespace std;

int main() {

    RulesPrompt rules_prompt;
    rules_prompt.set_rules();
    rules_prompt.print_rules();

    Table table(
        rules_prompt.get_decks(),
        rules_prompt.get_h17(),
        rules_prompt.get_dos(),
        rules_prompt.get_variants(),
        rules_prompt.get_counting_strategy(),
        rules_prompt.get_blackjack_payout()
    );

    return 0;
};
