#ifndef FLUSH_HPP
#define FLUSH_HPP

#include "Straight.hpp"

class Flush : public Straight {
    public :
        // ctor by input
        Flush(Player c1, TableCard c2);
        // cctor
        Flush(const Flush& C);
        //dtor
        ~Flush();
        // Find and calculate combination
        virtual void calculateMaxCombination(Player, TableCard);
        virtual vector<Card> findMaxCombination(Player, TableCard);
        virtual vector<Card> findMaxCombination(TableCard);
    
};
#endif