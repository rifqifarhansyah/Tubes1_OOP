#ifndef PAIR_HPP
#define PAIR_HPP

#include "HighCard.hpp"

class Pair : public HighCard {
    public :
        // ctor by input
        Pair(Player c1, TableCard c2);
        // cctor
        Pair(const Pair& C);
        //dtor
        ~Pair();
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
        // bool isPair(Player, TableCard);

    protected:
        double maxPair;
};
#endif