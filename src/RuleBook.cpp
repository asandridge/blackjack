#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <regex>

#include "../include/RuleBook.hpp"

using namespace std;

map<string, map<string, int>> counting_strategies = {
    { "hilo", { {"2", 1}, {"3", 1}, {"4", 1}, {"5", 1}, {"6", 1}, {"7", 0}, {"8", 0}, {"9", 0}, {"10", -1}, {"A", -1} }}
};
map<string, vector<string>> input_choices = {
    { "rounds", {} },
    { "decks", { "2", "4", "6", "8" } },
    { "h17", { "true", "false" } },
    { "das", { "true", "false" } },
    { "variants", { "true", "false" } },
    { "counting_strategy", { "hilo" } },
    { "blackjack_payout", { "1.5", "1.2" } },
    { "resplit_limit", { "2", "3", "4" } }
};

void RuleBook::validate_rule(string rule) {

    std::regex pattern ("[a-z0-9_]+:[a-z0-9\\.]+");
    if (std::regex_match(rule, pattern)) {

        string rule_name = rule.substr(0, rule.find(":"));
        string rule_value = rule.substr(rule.find(":") + 1);

        if (input_choices.find(rule_name) != input_choices.end()) {

            if (rule_name == "rounds" && stoi(rule_value) > 0) {

                rounds = stoi(rule_value);
                return;

            } else {

                for (int i = 0; i < input_choices[rule_name].size(); i++) {
                    if (rule_value == input_choices[rule_name][i]) {
                        if (rule_name == "decks") decks = stoi(rule_value);
                        else if (rule_name == "h17") h17 = rule_value == "true";
                        else if (rule_name == "das") das = rule_value == "true";
                        else if (rule_name == "variants") variants = rule_value == "true";
                        else if (rule_name == "counting_strategy") counting_strategies[rule_value];
                        else if (rule_name == "blackjack_payout") blackjack_payout = stof(rule_value);
                        else if (rule_name == "resplit_limit") resplit_limit = stoi(rule_value);
                        return;
                    }
                }
            }

            throw std::invalid_argument( rule_value + " is an invalid value for rule: " + rule_name );
        }
        throw std::invalid_argument( rule_name + " is an invalid rule." );
    }
    throw std::invalid_argument( "Rule does not match correct syntax: " + rule );
}

void RuleBook::read_rules() {

    string rule;
    fstream input_file;
    input_file.open("options.txt", ios::in);
    while (getline(input_file, rule)) {
        validate_rule(rule);
    }
    input_file.close();

}

int RuleBook::get_rounds() {
    return rounds;
}

int RuleBook::get_decks() {
    return decks;
}

bool RuleBook::get_h17() {
    return h17;
}

bool RuleBook::get_das() {
    return das;
}

bool RuleBook::get_variants() {
    return variants;
}

map<string, int> RuleBook::get_counting_strategy() {
    return counting_strategies[counting_strategy];
}

float RuleBook::get_blackjack_payout() {
    return blackjack_payout;
}

int RuleBook::get_resplit_limit() {
    return resplit_limit;
}

void RuleBook::print_rules() {
    cout << endl;
    cout << "Current rules:" << endl;
    cout << "   Decks: " << this->decks << endl;
    cout << "   H17: " << (this->h17 ? "True" : "False") << endl;
    cout << "   DAS: " << (this->das ? "True" : "False") << endl;
    cout << "   Variants: " << (this->variants ? "True" : "False") << endl;
    cout << "   Counting Strategy: " << counting_strategy << endl;
    cout << "   Blackjack Payout: " << blackjack_payout << endl;
    cout << "   Resplit Limit: " << resplit_limit << endl;
    cout << endl;
}
