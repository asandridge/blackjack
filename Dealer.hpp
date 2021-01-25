#ifndef DEALER_H
#define DEALER_H

#include <iostream>
using namespace std;

class Dealer
{
     private:

        vector<string> hand;

     public:

        void complete_hand();
        void hit();

};

#endif
