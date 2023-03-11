#ifndef STRAIGHT_HPP
#define STRAIGHT_HPP

#include "ThreeOfAKind.hpp"

class Straight : ThreeOfAKind {
    public :
        // ctor by input
        Straight(Card c1, Card c2);
        // cctor
        Straight(const Straight& C);
        //dtor
        ~Straight();
        // get value of a combo
        virtual int getValue(Card c1, Card c2) const;
    // protected:
    //     int StraightValue;
};
#endif