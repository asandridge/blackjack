#include <iostream>
#include <vector>
#include <string>

#include "Shoe.hpp"

using namespace std;

string Shoe::draw() {
    string card = this->shoe.back();
    this->shoe.pop_back();
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