#ifndef FULLHOUSE_HPP
#define FULLHOUSE_HPP

#include "Flush.hpp"

class FullHouse : public Flush {
    public :
        // ctor by input
        FullHouse(Player c1, TableCard c2);
        // cctor
        FullHouse(const FullHouse& C);
        //dtor
        ~FullHouse();
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
    //     string Card::getColorFromValue(double result) const;
        
    //     // check combo
    //     // bool isTwoPair(Player, TableCard);

    // protected:
    //     double maxFullHouse;
};
#endif