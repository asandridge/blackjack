#ifndef SHOE_H
#define SHOE_H

#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

string suit [13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "10", "10", "10", "A" };

class Shoe
{
    private:

        vector<string> shoe;

    public:

        Shoe(int decks) {

            shoe.clear();
            int shoe_length = decks * 52;

            for (int i = 0; i < shoe_length; i++) {
                shoe.push_back(suit[i % 13]);
            }

            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::default_random_engine e(seed);
            shuffle(shoe.begin(), shoe.end(), e);

        }

        int get_shoe_size();
        string draw();
        void print();
};

#endif
