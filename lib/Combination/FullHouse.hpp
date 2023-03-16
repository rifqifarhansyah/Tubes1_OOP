#ifndef FULLHOUSE_HPP
#define FULLHOUSE_HPP

#include "Flush.hpp"

class FullHouse : public Flush {
    public :
        FullHouse();
        // ctor by input
        FullHouse(Player c1, TableCard c2);
        // cctor
        FullHouse(const FullHouse& C);
        //dtor
        ~FullHouse();
        // Find and calculate combination
        virtual void calculateMaxCombination(Player, TableCard);
        virtual vector<Card> findMaxCombination(Player, TableCard);
        double findMaxThreeOfAKind(const vector<Card>& cards);
    
};
#endif