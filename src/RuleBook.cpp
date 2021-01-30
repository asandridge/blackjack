#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "../include/RuleBook.hpp"

using namespace std;

vector<string> deck_choices = { "2", "4", "6", "8" };
vector<string> counting_choices = { "Hi-Lo" };
vector<string> payout_choices = { "1.5", "1.2" };
vector<string> resplit_choices = { "2", "3", "4" };

bool RuleBook::get_yes_no(string prompt) {
    string rule;
    cout << "Do you want to play " << prompt << " (y/n)" << endl;
    cin >> rule;
    while (rule != "n" && rule != "y") {
        cout << "Please enter y or n." << endl;
        cin >> rule;
    }
    return rule == "y";
}

string RuleBook::get_choice(string prompt, vector<string> choice_vector) {

    string choice_string = "";
    for (vector<string>::iterator it = choice_vector.begin(); it != choice_vector.end(); ++it) {
        choice_string.append(*it);
        choice_string.append("/");
    }
    choice_string = choice_string.substr(0, choice_string.size() - 1);

    string rule;
    cout << prompt << " do you want to use? (" << choice_string << ")" << endl;
    cin >> rule;
    while (count(choice_vector.begin(), choice_vector.end(), rule) == 0) {
        cout << "Please enter a valid option." << endl;
        cin >> rule;
    }

    return rule;
}

void RuleBook::set_rules() {

    cout << endl << "Default rules: 6 decks, H17, DAS, variants, Hi-Lo counting, 3:2 blackjack payout, resplit to 4 hands" << endl;
    bool default_rules = get_yes_no("with default rules?");

    if (!default_rules) {

        decks = stoi(get_choice("How many decks", deck_choices));
        h17 = get_yes_no("H17 (hit on seventeen)?");
        das = get_yes_no("with DAS (double after split)?");
        variants = get_yes_no("with count-based variants?");
        counting_strategy = get_choice("What counting strategy", counting_choices);
        blackjack_payout = stof(get_choice("What blackjack payout", payout_choices));
        resplit_limit = stoi(get_choice("What resplit limit", resplit_choices));

    } else {

        cout << endl << "Rules will be set to defaults." << endl;
        decks = stoi(deck_choices[2]);
        h17 = true;
        das = true;
        variants = true;
        counting_strategy = counting_choices[0];
        blackjack_payout = stof(payout_choices[0]);
        resplit_limit = stoi(resplit_choices[2]);
    }
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

string RuleBook::get_counting_strategy() {
    return counting_strategy;
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