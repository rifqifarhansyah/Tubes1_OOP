#ifndef THREEOFAKIND_HPP
#define THREEOFAKIND_HPP

#include "TwoPair.hpp"

class ThreeOfAKind : public TwoPair {
    public :
        ThreeOfAKind();
        // ctor by input
        ThreeOfAKind(Player player, TableCard table);
        // cctor
        ThreeOfAKind(const ThreeOfAKind& C);
        //dtor
        ~ThreeOfAKind();
        // Find and calculate combination
        virtual void calculateMaxCombination();
        virtual vector<Card> findMaxCombinationAll();
        friend bool operator< (const ThreeOfAKind& p1, const ThreeOfAKind&p2);
        friend bool operator> (const ThreeOfAKind& p1, const ThreeOfAKind&p2);
};
#endif