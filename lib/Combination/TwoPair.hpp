#ifndef TWOPAIR_HPP
#define TWOPAIR_HPP

#include "Pair.hpp"

class TwoPair : public Pair {
    public :
        TwoPair();
        // ctor by input
        TwoPair(Player player, TableCard table);
        // cctor
        TwoPair(const TwoPair& C);
        //dtor
        ~TwoPair();
        // Find and calculate combination
        virtual void calculateMaxCombination();
        virtual vector<Card> findMaxCombinationAll();
};
#endif