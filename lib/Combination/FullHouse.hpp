#ifndef FULLHOUSE_HPP
#define FULLHOUSE_HPP

#include "Flush.hpp"

class FullHouse : public Flush {
    public :
        FullHouse();
        // ctor by input
        FullHouse(Player player, TableCard table);
        // cctor
        FullHouse(const FullHouse& C);
        //dtor
        ~FullHouse();
        // Find and calculate combination
        virtual void calculateMaxCombination();
        virtual vector<Card> findMaxCombinationAll();
        double findMaxThreeOfAKind(const vector<Card>& cards);
    
};
#endif