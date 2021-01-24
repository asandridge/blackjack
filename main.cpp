#include <iostream>
#include <vector>
#include <string>
#include "RulesPrompt.hpp"
#include "Table.hpp"

using namespace std;

int main() {

    RulesPrompt rules_prompt;
    rules_prompt._set_rules();
    rules_prompt._print_rules();
    Table table;

    return 0;
};
