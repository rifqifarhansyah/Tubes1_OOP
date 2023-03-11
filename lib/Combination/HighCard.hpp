#ifndef HIGHCARD_HPP
#define HIGHCARD_HPP

#include "Combination.hpp"

class HighCard : Combination {
    public :
        // ctor by input
        HighCard(Card c1, Card c2);
        // cctor
        HighCard(const Combination& C);
        //dtor
        ~HighCard();
        // get value of a combo
        virtual int getValue(Card c1, Card c2) const;
    protected:
        string highestColor;
};
#endif