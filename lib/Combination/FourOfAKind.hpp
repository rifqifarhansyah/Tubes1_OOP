#ifndef FOUROFAKIND_HPP
#define FOUROFAKIND_HPP

#include "FullHouse.hpp"

class FourOfAKind : public FullHouse {
    public :
        // ctor by input
        FourOfAKind();
        FourOfAKind(Player player, TableCard table);
        // cctor
        FourOfAKind(const FourOfAKind& C);
        //dtor
        ~FourOfAKind();
        // Find and calculate combination
        virtual void calculateMaxCombination(Player, TableCard);
        virtual vector<Card> findMaxCombination(Player, TableCard);
};
#endif