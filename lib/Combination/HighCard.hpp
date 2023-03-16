#ifndef HIGHCARD_HPP
#define HIGHCARD_HPP

#include "Combination.hpp"

class HighCard : public Combination {
    public:
        HighCard();
        // ctor by input
        HighCard(Player player, TableCard table);
        // cctor
        HighCard(const HighCard& C);
        //dtor
        ~HighCard();
        // Find and calculate combination
        virtual void calculateMaxCombination();
        virtual vector<Card> findMaxCombinationAll();
        // set and get totalValue
        void setValue(double);
        double getValue() const;
        // set and get highestNumber
        virtual void setHighestNumber(double);
        virtual double getHighestNumber() const;
        virtual double findHighestNumber(vector<Card>);
        // set and get highestColor
        virtual void setHighestColor(string);
        virtual string getHighestColor() const;
        double findHighestColor(vector<Card>);
    protected:
        double highestNumber;
        string highestColor;
};
#endif