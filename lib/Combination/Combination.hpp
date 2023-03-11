#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include <string>
#include "Card.hpp"
using namespace std;

class Combination{
    public:
        Combination(Card c1, Card c2);
        Combination(const Combination& C);
        ~Combination();
        virtual int getValue(Card c1, Card c2) const = 0;

    protected:
        int totalValue;
};
#endif