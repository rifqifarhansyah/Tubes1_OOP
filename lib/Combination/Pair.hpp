#ifndef PAIR_HPP
#define PAIR_HPP

#include "HighCard.hpp"

class Pair : public HighCard {
    public :
        Pair();
        // ctor by input
        Pair(Player c1, TableCard c2);
        // cctor
        Pair(const Pair& C);
        //dtor
        ~Pair();
        // Find and calculate combination
        virtual void calculateMaxCombination(Player, TableCard);
        virtual vector<Card> findMaxCombination(Player, TableCard);
};
#endif