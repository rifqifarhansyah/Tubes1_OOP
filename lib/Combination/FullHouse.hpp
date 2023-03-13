#ifndef FULLHOUSE_HPP
#define FULLHOUSE_HPP

#include "Flush.hpp"

class FullHouse : Flush {
    public :
        // ctor by input
        FullHouse(PlayerCard c1, PlayerCard c2);
        // cctor
        FullHouse(const FullHouse& C);
        //dtor
        ~FullHouse();
        // get value of a combo
        virtual int getValue(PlayerCard c1, PlayerCard c2) const;
    // protected:
    //     int StraightValue;
};
#endif