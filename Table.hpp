#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

#include "Player.hpp"
#include "Dealer.hpp"
#include "Shoe.hpp"

using namespace std;

class Table
{
     private:

        Player player;
        Dealer dealer;
        Shoe shoe;

     public:

        Table() : shoe(6) {

        }

};

#endif
