#ifndef RULES_PROMPT_H
#define RULES_PROMPT_H

#include <iostream>
#include <map>
using namespace std;

vector<string> deck_choices = { "2", "4", "6", "8" };
vector<string> counting_choices = { "Hi-Lo" };
vector<string> payout_choices = { "3:2", "6:5" };

class RulesPrompt
{
    private:

        int decks;
        bool h17;
        bool dos;
        bool variants;
        string counting_strategy;
        string blackjack_payout;

        bool get_yes_no(string);
        string get_choice(string, vector<string>);

    public:

        void set_rules();
        int get_decks();
        bool get_h17();
        bool get_dos();
        bool get_variants();
        string get_counting_strategy();
        string get_blackjack_payout();
        void print_rules();

};


    bool RulesPrompt::get_yes_no(string prompt) {
        string rule;
        cout << "Do you want to play " << prompt << " (y/n)" << endl;
        cin >> rule;
        while (rule != "n" && rule != "y") {
            cout << "Please enter y or n." << endl;
            cin >> rule;
        }
        return rule == "y";
    }

    string RulesPrompt::get_choice(string prompt, vector<string> choice_vector) {

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

    void RulesPrompt::set_rules() {

        cout << endl << "Default rules: 6 decks, H17, DOS, variants, Hi-Lo counting, 3:2 blackjack payout" << endl;
        bool default_rules = get_yes_no("with default rules?");

        if (!default_rules) {

            this->decks = stoi(get_choice("How many decks", deck_choices));
            this->h17 = get_yes_no("H17 (hit on seventeen)?");
            this->dos = get_yes_no("with DOS (double on split)?");
            this->variants = get_yes_no("with count-based variants?");
            this->counting_strategy = get_choice("What counting strategy", counting_choices);
            this->blackjack_payout = get_choice("What blackjack payout", payout_choices);

        } else {

            cout << endl << "Rules will be set to defaults." << endl;
            decks = 6;
            h17 = true;
            dos = true;
            variants = true;
            counting_strategy = counting_choices[0];
            blackjack_payout = payout_choices[0];
        }
    }

    int RulesPrompt::get_decks() {
        return decks;
    }

    bool RulesPrompt::get_h17() {
        return h17;
    }

    bool RulesPrompt::get_dos() {
        return dos;
    }

    bool RulesPrompt::get_variants() {
        return variants;
    }

    string RulesPrompt::get_counting_strategy() {
        return counting_strategy;
    }

    string RulesPrompt::get_blackjack_payout() {
        return blackjack_payout;
    }

    void RulesPrompt::print_rules() {
        cout << endl;
        cout << "Current rules:" << endl;
        cout << "   Decks: " << this->decks << endl;
        cout << "   H17: " << (this->h17 ? "True" : "False") << endl;
        cout << "   DOS: " << (this->dos ? "True" : "False") << endl;
        cout << "   Variants: " << (this->variants ? "True" : "False") << endl;
        cout << "   Counting Strategy: " << counting_strategy << endl;
        cout << "   Blackjack Payout: " << blackjack_payout << endl;
    }

#endif
