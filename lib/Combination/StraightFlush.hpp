#ifndef STRAIGHTFLUSH_HPP
#define STRAIGHTFLUSH_HPP

#include "FourOfAKind.hpp"

class StraightFlush : public FourOfAKind {
    public :
        public :
        // ctor by input
        StraightFlush(Player c1, TableCard c2);
        // cctor
        StraightFlush(const StraightFlush& C);
        //dtor
        ~StraightFlush();
        // Find and calculate combination
        virtual void calculateMaxCombination(Player, TableCard);
        virtual vector<Card> findMaxCombination(Player, TableCard);
        virtual vector<Card> findMaxCombination(TableCard);
        friend bool operator< (Player& p1, Player&p2);
        friend bool operator> (Player& p1, Player&p2);
};
#endif