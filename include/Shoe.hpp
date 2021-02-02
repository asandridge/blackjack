#ifndef SHOE_H
#define SHOE_H

#include "Deck.hpp"

using namespace std;

class Shoe
{
    private:

        vector<string> shoe;
        vector<string> discard;

    public:

        Shoe(int decks) {

            int shoe_length = decks * deck::deck_size;

            for (int i = 0; i < shoe_length; i++) {
                discard.push_back(deck::suit[i % 13]);
            }

            reshuffle();
        }

        int get_shoe_size();
        string draw();
        void print();
        void reshuffle();
};

#endif
