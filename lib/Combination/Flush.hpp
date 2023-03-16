#ifndef FLUSH_HPP
#define FLUSH_HPP

#include "Straight.hpp"

class Flush : public Straight {
    public :
        // ctor by input
        Flush(Player player, TableCard table);
        // cctor
        Flush(const Flush& C);
        //dtor
        ~Flush();
        // Find and calculate combination
        virtual void calculateMaxCombination();
        virtual vector<Card> findMaxCombinationAll();
        virtual vector<Card> findMaxCombinationTable();
        double findFlushNumbers(vector<Card> c);
    
};
#endif