#ifndef TWOPAIR_HPP
#define TWOPAIR_HPP

#include "Pair.hpp"

class TwoPair : public Pair {
    public :
        // ctor by input
        TwoPair(Player c1, TableCard c2);
        // cctor
        TwoPair(const Pair& C);
        //dtor
        ~TwoPair();
        // Find and calculate combination
        virtual void calculateMaxCombination(Player, TableCard);
        virtual vector<Card> findMaxCombination(Player, TableCard);
    //     // set and get totalValue
    //     void setValue(double);
    //     double getValue(Player, TableCard) const;
    //     // set and get highestNumber
    //     virtual void setHighestNumber(double);
    //     virtual double getHighestNumber() const;
    //     // set and get highestColor
    //     virtual void setHighestColor(string);
    //     virtual string getHighestColor() const;
    //     double findHighestColor(vector<Card>);
    //     virtual double getValueFromColor(string) const;
    //     string getColorFromValue(double result) const;
        
    //     // check combo
    //     // bool isTwoPair(Player, TableCard);

    // protected:
    //     double maxTwoPair;
};
#endif