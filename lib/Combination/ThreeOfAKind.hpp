#ifndef THREEOFAKIND_HPP
#define THREEOFAKIND_HPP

#include "TwoPair.hpp"

class ThreeOfAKind : public TwoPair {
    public :
        ThreeOfAKind();
        // ctor by input
        ThreeOfAKind(Player c1, TableCard c2);
        // cctor
        ThreeOfAKind(const ThreeOfAKind& C);
        //dtor
        ~ThreeOfAKind();
        // Find and calculate combination
        virtual void calculateMaxCombination(Player, TableCard);
        virtual vector<Card> findMaxCombination(Player, TableCard);
};
#endif