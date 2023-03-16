#ifndef STRAIGHT_HPP
#define STRAIGHT_HPP

#include "ThreeOfAKind.hpp"

class Straight : public ThreeOfAKind {
    public :
        Straight();
        // ctor by input
        Straight(Player c1, TableCard c2);
        // cctor
        Straight(const Straight& C);
        //dtor
        ~Straight();
        // Find and calculate combination
        virtual void calculateMaxCombination(Player, TableCard);
        virtual vector<Card> findMaxCombination(Player, TableCard);
};
#endif