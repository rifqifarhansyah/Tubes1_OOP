#ifndef THREEOFAKIND_HPP
#define THREEOFAKIND_HPP

#include "TwoPair.hpp"

class ThreeOfAKind : TwoPair {
    public :
        // ctor by input
        ThreeOfAKind(Player c1, Player c2);
        // cctor
        ThreeOfAKind(const ThreeOfAKind& C);
        //dtor
        ~ThreeOfAKind();
        // get value of a combo
        virtual int getValue(Player c1, Player c2) const;
    // protected:
    //     int ThreeOfAKindValue;
};
#endif