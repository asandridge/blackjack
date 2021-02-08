#ifndef SCORE_HELPER_H
#define SCORE_HELPER_H

#include <vector>
#include <string>
#include <tuple>

#include "../include/Strategy.hpp"

using namespace std;

class ScoreHelper
{

    public:

        static tuple<int, bool> calculate_hand_score(vector<string>);
        static strategy::moves determine_hand_move(string, vector<string>);
        static int calculate_refund(vector<string>, vector<string>, int);

};

#endif
