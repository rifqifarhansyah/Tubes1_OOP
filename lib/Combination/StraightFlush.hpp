#ifndef STRAIGHTFLUSH_HPP
#define STRAIGHTFLUSH_HPP

#include "FourOfAKind.hpp"

class StraightFlush : public FourOfAKind {
    public :
        public :
        // ctor by input
        StraightFlush(Player player, TableCard table);
        // cctor
        StraightFlush(const StraightFlush& C);
        //dtor
        ~StraightFlush();
        // Find and calculate combination
        virtual void calculateMaxCombination();
        virtual vector<Card> findMaxCombinationAll();
        virtual vector<Card> findMaxCombinationTable();
        friend bool operator< (StraightFlush& p1, StraightFlush&p2);
        friend bool operator> (StraightFlush& p1, StraightFlush&p2);
};
#endif