#ifndef STRAIGHT_HPP
#define STRAIGHT_HPP

#include "ThreeOfAKind.hpp"

class Straight : public ThreeOfAKind {
    public :
        // ctor by input
        Straight(Player c1, TableCard c2);
        // cctor
        Straight(const Straight& C);
        //dtor
        ~Straight();
        // Find and calculate combination
        virtual void calculateMaxCombination(Player, TableCard);
        virtual vector<Card> findMaxCombination(Player, TableCard);
        // set and get totalValue
        void setValue(double);
        double getValue(Player, TableCard) const;
        // set and get highestNumber
        virtual void setHighestNumber(double);
        virtual double getHighestNumber() const;
        // set and get highestColor
        virtual void setHighestColor(string);
        virtual string getHighestColor() const;
        double findHighestColor(vector<Card>);
        virtual double getValueFromColor(string) const;
        string getColorFromValue(double result) const;
        
        // check combo
        // bool isTwoPair(Player, TableCard);

    protected:
        double maxStraight;
};
#endif