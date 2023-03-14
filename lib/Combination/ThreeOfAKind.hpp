#ifndef THREEOFAKIND_HPP
#define THREEOFAKIND_HPP

#include "TwoPair.hpp"

class ThreeOfAKind : public TwoPair {
    public :
        // ctor by input
        ThreeOfAKind(Player c1, TableCard c2);
        // cctor
        ThreeOfAKind(const Pair& C);
        //dtor
        ~ThreeOfAKind();
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
        double maxThreeOfAKind;
};
#endif