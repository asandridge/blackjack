#ifndef STRATEGY_H
#define STRATEGY_H
namespace strategy
{

    enum moves
    {
        HIT,
        STAND,
        DOUBLE,
        SURRENDER
    };

    enum splitting_moves
    {
        SPLIT_TRUE,
        SPLIT_FALSE,
        SPLIT_DAS
    };

    map<int, map<string, moves>> hard_totals = {
        { 21, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", STAND }, { "8", STAND }, { "9", STAND }, { "10", STAND }, { "A", STAND } }},
        { 20, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", STAND }, { "8", STAND }, { "9", STAND }, { "10", STAND }, { "A", STAND } }},
        { 19, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", STAND }, { "8", STAND }, { "9", STAND }, { "10", STAND }, { "A", STAND } }},
        { 18, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", STAND }, { "8", STAND }, { "9", STAND }, { "10", STAND }, { "A", STAND } }},
        { 17, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", STAND }, { "8", STAND }, { "9", STAND }, { "10", STAND }, { "A", STAND } }},
        { 16, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", HIT }, { "8", HIT }, { "9", SURRENDER }, { "10", SURRENDER }, { "A", SURRENDER } }},
        { 15, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", SURRENDER }, { "A", HIT } }},
        { 14, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
        { 13, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
        { 12, { { "2", HIT }, { "3", HIT }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
        { 11, { { "2", DOUBLE }, { "3", DOUBLE }, { "4", DOUBLE }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", DOUBLE }, { "8", DOUBLE }, { "9", DOUBLE }, { "10", DOUBLE }, { "A", DOUBLE } }},
        { 10, { { "2", DOUBLE }, { "3", DOUBLE }, { "4", DOUBLE }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", DOUBLE }, { "8", DOUBLE }, { "9", DOUBLE }, { "10", HIT }, { "A", HIT } }},
        { 9, { { "2", HIT }, { "3", DOUBLE }, { "4", DOUBLE }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
        { 8, { { "2", HIT }, { "3", HIT }, { "4", HIT }, { "5", HIT }, { "6", HIT }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
        { 7, { { "2", HIT }, { "3", HIT }, { "4", HIT }, { "5", HIT }, { "6", HIT }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
        { 6, { { "2", HIT }, { "3", HIT }, { "4", HIT }, { "5", HIT }, { "6", HIT }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
        { 5, { { "2", HIT }, { "3", HIT }, { "4", HIT }, { "5", HIT }, { "6", HIT }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
        { 4, { { "2", HIT }, { "3", HIT }, { "4", HIT }, { "5", HIT }, { "6", HIT }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }}
    };

    map<int, map<string, moves>> soft_totals = {
        { 21, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", STAND }, { "8", STAND }, { "9", STAND }, { "10", STAND }, { "A", STAND } }},
        { 20, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", STAND }, { "7", STAND }, { "8", STAND }, { "9", STAND }, { "10", STAND }, { "A", STAND } }},
        { 19, { { "2", STAND }, { "3", STAND }, { "4", STAND }, { "5", STAND }, { "6", DOUBLE }, { "7", STAND }, { "8", STAND }, { "9", STAND }, { "10", STAND }, { "A", STAND } }},
        { 18, { { "2", DOUBLE }, { "3", DOUBLE }, { "4", DOUBLE }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", STAND }, { "8", STAND }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
        { 17, { { "2", HIT }, { "3", DOUBLE }, { "4", DOUBLE }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
        { 16, { { "2", HIT }, { "3", HIT }, { "4", DOUBLE }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
        { 15, { { "2", HIT }, { "3", HIT }, { "4", DOUBLE }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
        { 14, { { "2", HIT }, { "3", HIT }, { "4", HIT }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }},
        { 13, { { "2", HIT }, { "3", HIT }, { "4", HIT }, { "5", DOUBLE }, { "6", DOUBLE }, { "7", HIT }, { "8", HIT }, { "9", HIT }, { "10", HIT }, { "A", HIT } }}
    };

    map<string, map<string, splitting_moves>> splitting_strategy = {
        { "A", { { "2", SPLIT_TRUE }, { "3", SPLIT_TRUE }, { "4", SPLIT_TRUE }, { "5", SPLIT_TRUE }, { "6", SPLIT_TRUE }, { "7", SPLIT_TRUE }, { "8", SPLIT_TRUE }, { "9", SPLIT_TRUE }, { "10", SPLIT_TRUE }, { "A", SPLIT_TRUE } }},
        { "10", { { "2", SPLIT_FALSE }, { "3", SPLIT_FALSE }, { "4", SPLIT_FALSE }, { "5", SPLIT_FALSE }, { "6", SPLIT_FALSE }, { "7", SPLIT_FALSE }, { "8", SPLIT_FALSE }, { "9", SPLIT_FALSE }, { "10", SPLIT_FALSE }, { "A", SPLIT_FALSE } }},
        { "9", { { "2", SPLIT_TRUE }, { "3", SPLIT_TRUE }, { "4", SPLIT_TRUE }, { "5", SPLIT_TRUE }, { "6", SPLIT_TRUE }, { "7", SPLIT_FALSE }, { "8", SPLIT_TRUE }, { "9", SPLIT_TRUE }, { "10", SPLIT_FALSE }, { "A", SPLIT_FALSE } }},
        { "8", { { "2", SPLIT_TRUE }, { "3", SPLIT_TRUE }, { "4", SPLIT_TRUE }, { "5", SPLIT_TRUE }, { "6", SPLIT_TRUE }, { "7", SPLIT_TRUE }, { "8", SPLIT_TRUE }, { "9", SPLIT_TRUE }, { "10", SPLIT_TRUE }, { "A", SPLIT_TRUE } }},
        { "7", { { "2", SPLIT_TRUE }, { "3", SPLIT_TRUE }, { "4", SPLIT_TRUE }, { "5", SPLIT_TRUE }, { "6", SPLIT_TRUE }, { "7", SPLIT_TRUE }, { "8", SPLIT_FALSE }, { "9", SPLIT_FALSE }, { "10", SPLIT_FALSE }, { "A", SPLIT_FALSE } }},
        { "6", { { "2", SPLIT_DAS }, { "3", SPLIT_TRUE }, { "4", SPLIT_TRUE }, { "5", SPLIT_TRUE }, { "6", SPLIT_TRUE }, { "7", SPLIT_FALSE }, { "8", SPLIT_FALSE }, { "9", SPLIT_FALSE }, { "10", SPLIT_FALSE }, { "A", SPLIT_FALSE } }},
        { "5", { { "2", SPLIT_FALSE }, { "3", SPLIT_FALSE }, { "4", SPLIT_FALSE }, { "5", SPLIT_FALSE }, { "6", SPLIT_FALSE }, { "7", SPLIT_FALSE }, { "8", SPLIT_FALSE }, { "9", SPLIT_FALSE }, { "10", SPLIT_FALSE }, { "A", SPLIT_FALSE } }},
        { "4", { { "2", SPLIT_FALSE }, { "3", SPLIT_FALSE }, { "4", SPLIT_FALSE }, { "5", SPLIT_DAS }, { "6", SPLIT_DAS }, { "7", SPLIT_FALSE }, { "8", SPLIT_FALSE }, { "9", SPLIT_FALSE }, { "10", SPLIT_FALSE }, { "A", SPLIT_FALSE } }},
        { "3", { { "2", SPLIT_DAS }, { "3", SPLIT_DAS }, { "4", SPLIT_TRUE }, { "5", SPLIT_TRUE }, { "6", SPLIT_TRUE }, { "7", SPLIT_TRUE }, { "8", SPLIT_FALSE }, { "9", SPLIT_FALSE }, { "10", SPLIT_FALSE }, { "A", SPLIT_FALSE } }},
        { "2", { { "2", SPLIT_DAS }, { "3", SPLIT_DAS }, { "4", SPLIT_TRUE }, { "5", SPLIT_TRUE }, { "6", SPLIT_TRUE }, { "7", SPLIT_TRUE }, { "8", SPLIT_FALSE }, { "9", SPLIT_FALSE }, { "10", SPLIT_FALSE }, { "A", SPLIT_FALSE } }}
    };


    tuple<int, bool> calculate_hand_score(vector<string> hand) {

        int sum = 0;
        int aces = 0;
        bool is_soft_hand = false;

        for (int i = 0; i < hand.size(); i++) { // Hard totals
            if (hand[i] == "A") {
                aces++;
            } else {
                sum += stoi(hand[i]);
            }
        }

        if (sum + 11 + aces - 1 <= 21) { // First ace can count as 11, soft hand
            sum += 11 + (aces - 1);
            is_soft_hand = true;
        } else {
            sum += aces;
        }

        if (sum > 21) sum = 0;

        return { sum, is_soft_hand };

    }

    strategy::moves determine_hand_move(string dealer_upcard, vector<string> player_hand) {

        tuple<int, bool> player_hand_score = calculate_hand_score(player_hand);
        // cout << "Player hand score: " << get<0>(player_hand_score) << endl;
        // cout << "Dealer upcard: " << dealer_upcard << endl;

        if (get<0>(player_hand_score) == 0) {
            return strategy::STAND;
        }

        bool is_soft_hand = get<1>(player_hand_score);
        map<int, map<string, strategy::moves>> strategy_chart = is_soft_hand ? strategy::soft_totals : strategy::hard_totals;

        return strategy_chart[get<0>(player_hand_score)][dealer_upcard];

    }

    int calculate_refund(vector<string> dealer_hand, vector<string> player_hand, int blackjack_payout) {

        tuple<int, bool> dealer_score = calculate_hand_score(dealer_hand);
        tuple<int, bool> player_score = calculate_hand_score(player_hand);

        int dealer_count = get<0>(dealer_score);
        int player_count = get<0>(player_score);

        // cout << "Player Score: " << player_count << endl;
        // cout << "Dealer Score: " << dealer_count << endl;

        bool dealer_blackjack = dealer_count == 21 && get<1>(dealer_score);
        bool player_blackjack = player_count == 21 && get<1>(player_score);

        if (player_count == 0) return -1; // player always loses on bust
        else if (player_blackjack && !dealer_blackjack) return blackjack_payout;
        else if (dealer_blackjack && !player_blackjack) return -1;
        else if (player_blackjack && dealer_blackjack) return 0; // two blackjacks tie
        else if (player_count > dealer_count) return 1;
        else if (player_count == dealer_count) return 0;
        else return -1;
    }

}

#endif
