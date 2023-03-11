#ifndef STRAIGHTFLUSH_HPP
#define STRAIGHTFLUSH_HPP

#include "FourOfAKind.hpp"

class StraightFlush : FourOfAKind {
    public :
        // ctor by input
        StraightFlush(Card c1, Card c2);
        // cctor
        StraightFlush(const StraightFlush& C);
        //dtor
        ~StraightFlush();
        // get value of a combo
        virtual int getValue(Card c1, Card c2) const;
    // protected:
    //     int StraightValue;
};
#endif