#ifndef SHOE_H
#define SHOE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Shoe
{
    private:

        vector<string> shoe;
        string suit [13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "10", "10", "10", "A" };

    public:

        Shoe(int decks) {

            this->shoe.clear();
            int shoe_length = decks * 52;

            for (int i = 0; i < shoe_length; i++) {
                this->shoe.push_back(this->suit[i % 13]);
            }

            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::default_random_engine e(seed);
            shuffle(this->shoe.begin(), this->shoe.end(), e);

        }

        string draw() {
            string card = this->shoe.back();
            this->shoe.pop_back();
            return card;
        }

        void print() {
            for (int i = 0; i < shoe.size(); i++) {
                cout << shoe[i] << " ";
            }
            cout << endl;
        }

        int get_shoe_size() {
            return shoe.size();
        }
};

#endif
