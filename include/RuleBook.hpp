#ifndef RULE_BOOK_H
#define RULE_BOOK_H

#include <string>
#include <vector>

using namespace std;

class RuleBook
{
    private:

        int rounds;
        int decks;
        bool h17;
        bool das;
        bool variants;
        string counting_strategy;
        float blackjack_payout;
        int resplit_limit;

        void read_rules();
        void validate_rule(string);

    public:

        RuleBook() : rounds(10000), decks(6), h17(true), das(true), variants(true), counting_strategy("hilo"), blackjack_payout(1.5), resplit_limit(4) {
            read_rules();
        }

        int get_rounds();
        int get_decks();
        bool get_h17();
        bool get_das();
        bool get_variants();
        map<string, int> get_counting_strategy();
        float get_blackjack_payout();
        int get_resplit_limit();
        void print_rules();

};

#endif
