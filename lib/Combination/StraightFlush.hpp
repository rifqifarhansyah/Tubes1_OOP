#ifndef STRAIGHTFLUSH_HPP
#define STRAIGHTFLUSH_HPP

#include "FourOfAKind.hpp"

class StraightFlush : FourOfAKind {
    public :
        // ctor by input
        StraightFlush(Player c1, Player c2);
        // cctor
        StraightFlush(const StraightFlush& C);
        //dtor
        ~StraightFlush();
        // get value of a combo
        virtual int getValue(Player c1, Player c2) const;
    // protected:
    //     int StraightValue;
};
#endif