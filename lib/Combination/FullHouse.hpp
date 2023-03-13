#ifndef FULLHOUSE_HPP
#define FULLHOUSE_HPP

#include "Flush.hpp"

class FullHouse : Flush {
    public :
        // ctor by input
        FullHouse(Player c1, Player c2);
        // cctor
        FullHouse(const FullHouse& C);
        //dtor
        ~FullHouse();
        // get value of a combo
        virtual int getValue(Player c1, Player c2) const;
    // protected:
    //     int StraightValue;
};
#endif