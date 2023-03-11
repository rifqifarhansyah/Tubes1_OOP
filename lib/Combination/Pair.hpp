#ifndef PAIR_HPP
#define PAIR_HPP

#include "HighCard.hpp"

class Pair : HighCard {
    public :
        // ctor by input
        Pair(Card c1, Card c2);
        // cctor
        Pair(const Pair& C);
        //dtor
        ~Pair();
        // get value of a combo
        virtual int getValue(Card c1, Card c2) const;
    // protected:
    //     int PairValue;
};
#endif