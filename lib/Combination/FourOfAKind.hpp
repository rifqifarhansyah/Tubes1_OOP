#ifndef FOUROFAKIND_HPP
#define FOUROFAKIND_HPP

#include "FullHouse.hpp"

class FourOfAKind : public FullHouse {
    public :
        // ctor by input
        FourOfAKind(Player c1, TableCard c2);
        // cctor
        FourOfAKind(const FourOfAKind& C);
        //dtor
        ~FourOfAKind();
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
        double maxFourOfAKind;
};
#endif