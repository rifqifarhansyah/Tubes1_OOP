#ifndef STRAIGHT_HPP
#define STRAIGHT_HPP

#include "ThreeOfAKind.hpp"

class Straight : ThreeOfAKind {
    public :
        // ctor by input
        Straight(Player c1, Player c2);
        // cctor
        Straight(const Straight& C);
        //dtor
        ~Straight();
        // get value of a combo
        virtual int getValue(Player c1, Player c2) const;
    // protected:
    //     int StraightValue;
};
#endif