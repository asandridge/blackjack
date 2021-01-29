#ifndef SCORE_HELPER_H
#define SCORE_HELPER_H

#include <vector>
#include <string>
#include <tuple>

#include "Moves.hpp"

using namespace std;

class ScoreHelper
{

    public:

        tuple<int, bool> calculate_hand_score(vector<string>);
        moves::moves determine_hand_move(string, vector<string>);
        int calculate_refund(vector<string>, vector<string>, int);

};

#endif