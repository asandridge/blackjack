#ifndef RULES_PROMPT_H
#define RULES_PROMPT_H

#include <iostream>
using namespace std;

enum counting_strategies{ HILO };
enum blackjack_payouts{ three_two, six_five };

bool is_numeric(string str) {
   for (int i = 0; i < str.length(); i++)
      if (isdigit(str[i]) == false)
         return false; //when one non numeric value is found, return false
      return true;
}

class RulesPrompt
{
    private:
        int decks;
        bool h17;
        bool dos;
        bool variants;
        counting_strategies counting_strategy;
        blackjack_payouts blackjack_payout;

    public:

        void _set_rules() {
            cout << "Default rules: 6 decks, H17, DOS, variants, HI:LO, 3:2 blackjack" << endl;
            string custom_rules = _get_yes_no("with custom rules?");

            if (custom_rules == "y") {
                string decks;
                string h17;
                string dos;
                string variants;
                string count_strat;
                string blackjack_pay;

                cout << "How many decks? (1-8)" << endl;
                cin >> decks;
                while (!is_numeric(decks) || stoi(decks) > 8 || stoi(decks) < 1) {
                    cout << "Please enter a numeric value <= 8." << endl;
                    cin >> decks;
                }
                h17 = _get_yes_no("H17 (hit on seventeen)?");
                dos = _get_yes_no("DOS (double on split)?");
                variants = _get_yes_no("with count based variants?");

                cout << "What counting strategy do you want to use? (HILO)" << endl;
                cin >> count_strat;
                while (count_strat != "HILO") {
                    cout << "Please enter a valid counting strategy." << endl;
                    cin >> count_strat;
                }

                cout << "What blackjack payout do you want to use? (3:2/6:5)" << endl;
                cin >> blackjack_pay;
                while (blackjack_pay != "3:2" && blackjack_pay != "6:5") {
                    cout << "Please enter a valid payout." << endl;
                    cin >> blackjack_pay;
                }

                this->decks = stoi(decks);
                this->h17 = h17 == "y";
                this->dos = dos == "y";
                this->variants = variants == "y";
                this->counting_strategy = HILO;
                this->blackjack_payout = "3:2" ? three_two : six_five;

            } else {
                cout << "Rules will be set to defaults." << endl;
                decks = 6;
                h17 = true;
                dos = true;
                variants = true;
                counting_strategy = HILO;
                blackjack_payout = three_two;
            }
        }

        //_get_rules() {
        //    return [decks, h17, dos, variants, counting_strategy, blackjack_payout];
        //}

        string _get_yes_no(string prompt) {
            string rule;
            cout << "Do you want to play " << prompt << " (y/n)" << endl;
            cin >> rule;
            while (rule != "n" && rule != "y") {
                cout << "Please enter y or n." << endl;
                cin >> rule;
            }
            return rule;
        }

        void _print_rules() {
            cout << endl;
            cout << "Current rules:" << endl;
            cout << "   Decks: " << this->decks << endl;
            cout << "   H17: " << this->h17 << endl;
            cout << "   DOS: " << this->dos << endl;
            cout << "   Variants: " << this->variants << endl;
            cout << "   Counting Strategy: " << this->counting_strategy << endl;
            cout << "   Blackjack Payout: " << this->blackjack_payout << endl;
        }

};

#endif
