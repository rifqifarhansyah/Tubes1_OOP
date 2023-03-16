#ifndef STRAIGHT_HPP
#define STRAIGHT_HPP

#include "ThreeOfAKind.hpp"

class Straight : public ThreeOfAKind {
    public :
        // ctor by input
        Straight(Player player, TableCard table);
        // cctor
        Straight(const Straight& C);
        //dtor
        ~Straight();
        // Find and calculate combination
        virtual void calculateMaxCombination();
        virtual vector<Card> findMaxCombinationAll();
};
#endif