#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include <string>
#include <vector>
#include <algorithm>
#include "../Player/Player.hpp"
#include "../TableCard/TableCard.hpp"
using namespace std;

const double HIGH_CARD = 0;
const double PAIR = HIGH_CARD + 10;
const double TWO_PAIR = PAIR * 2 + 5;
const double THREE_OF_A_KIND = TWO_PAIR + 20;
const double STRAIGHT = THREE_OF_A_KIND + 15;
const double FLUSH = STRAIGHT + 10;
const double FULLHOUSE = FLUSH + THREE_OF_A_KIND + TWO_PAIR;
const double FOUR_OF_A_KIND = FULLHOUSE + 40;
const double STRAIGHT_FLUSH = FOUR_OF_A_KIND + STRAIGHT + FLUSH;

class Combination{
    public:
        Combination(Player , TableCard );
        Combination(const Combination&);
        ~Combination();
        virtual double getValue(Player, TableCard) const = 0;
    protected:
        double totalValue;
};
#endif