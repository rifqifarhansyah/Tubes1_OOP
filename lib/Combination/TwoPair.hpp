#ifndef TWOPAIR_HPP
#define TWOPAIR_HPP

#include "Pair.hpp"

class TwoPair : Pair {
    public :
        // ctor by input
        TwoPair(Player c1, Player c2);
        // cctor
        TwoPair(const TwoPair& C);
        //dtor
        ~TwoPair();
        // get value of a combo
        virtual int getValue(Player c1, Player c2) const;
    // protected:
    //     int TwoPairValue;
};
#endif