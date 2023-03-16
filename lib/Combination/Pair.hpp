#ifndef PAIR_HPP
#define PAIR_HPP

#include "HighCard.hpp"

class Pair : public HighCard {
    public :
        // ctor by input
        Pair(Player player, TableCard table);
        // cctor
        Pair(const Pair& C);
        //dtor
        ~Pair();
        // Find and calculate combination
        virtual void calculateMaxCombination();
        virtual vector<Card> findMaxCombinationAll();
};
#endif