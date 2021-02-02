#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

#include "../include/Shoe.hpp"

using namespace std;

string Shoe::draw() {
    string card = shoe.back();
    shoe.pop_back();
    return card;
}

void Shoe::print() {
    for (int i = 0; i < shoe.size(); i++) {
        cout << shoe[i] << " ";
    }
    cout << endl;
}

int Shoe::get_shoe_size() {
    return shoe.size();
}

void Shoe::reshuffle() {

    shoe = discard;
    discard.clear();

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    shuffle(shoe.begin(), shoe.end(), e);

}