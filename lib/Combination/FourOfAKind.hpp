#ifndef FOUROFAKIND_HPP
#define FOUROFAKIND_HPP

#include "FullHouse.hpp"

class FourOfAKind : FullHouse {
    public :
        // ctor by input
        FourOfAKind(PlayerCard c1, PlayerCard c2);
        // cctor
        FourOfAKind(const FourOfAKind& C);
        //dtor
        ~FourOfAKind();
        // get value of a combo
        virtual int getValue(PlayerCard c1, PlayerCard c2) const;
    // protected:
    //     int StraightValue;
};
#endif