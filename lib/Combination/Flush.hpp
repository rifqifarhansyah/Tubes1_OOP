#ifndef FLUSH_HPP
#define FLUSH_HPP

#include "Straight.hpp"

class Flush : Straight {
    public :
        // ctor by input
        Flush(Player c1, Player c2);
        // cctor
        Flush(const Flush& C);
        //dtor
        ~Flush();
        // get value of a combo
        virtual int getValue(Player c1, Player c2) const;
    // protected:
    //     int StraightValue;
};
#endif