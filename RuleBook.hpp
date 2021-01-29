#ifndef RULE_BOOK_H
#define RULE_BOOK_H

#include <string>
#include <vector>

using namespace std;

class RuleBook
{
    private:

        int decks;
        bool h17;
        bool das;
        bool variants;
        string counting_strategy;
        float blackjack_payout;
        int resplit_limit;

        bool get_yes_no(string);
        string get_choice(string, vector<string>);

    public:

        void set_rules();
        int get_decks();
        bool get_h17();
        bool get_das();
        bool get_variants();
        string get_counting_strategy();
        float get_blackjack_payout();
        int get_resplit_limit();
        void print_rules();

};

#endif
