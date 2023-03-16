#ifndef TWOPAIR_HPP
#define TWOPAIR_HPP

#include "Pair.hpp"

class TwoPair : public Pair {
    public :
        TwoPair();
        // ctor by input
        TwoPair(Player c1, TableCard c2);
        // cctor
        TwoPair(const TwoPair& C);
        //dtor
        ~TwoPair();
        // Find and calculate combination
        virtual void calculateMaxCombination(Player, TableCard);
        virtual vector<Card> findMaxCombination(Player, TableCard);
};
#endif