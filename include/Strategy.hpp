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

}

#endif