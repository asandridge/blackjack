#ifndef SCORE_HELPER_H
#define SCORE_HELPER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ScoreHelper
{
    private:

    public:

        tuple<int, bool> calculate_hand_score(vector<string>);
        int calculate_winner(vector<string>, vector<string>);

};


tuple<int, bool> ScoreHelper::calculate_hand_score(vector<string> hand) {

    int sum = 0;
    bool first_ace = false;

    for (int i = 0; i < hand.size(); i++) {
       if (hand[i] == "A") {
           if (!first_ace) {
               sum += 11;
               first_ace = true;
           } else {
               sum += 1;
           }
       } else {
           sum += stoi(hand[i]);
       }
    }

    bool is_soft_hand = first_ace && sum <= 21 && sum > 12; // a 'soft 12' would be two aces, and should be counted as a hard 12

    return { sum, is_soft_hand };

}

#endif