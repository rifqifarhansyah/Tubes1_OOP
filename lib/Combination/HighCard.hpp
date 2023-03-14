#ifndef HIGHCARD_HPP
#define HIGHCARD_HPP

#include "Combination.hpp"

class HighCard : public Combination {
    public:
        // ctor by input
        HighCard(Player c1, TableCard c2);
        // cctor
        HighCard(const HighCard& C);
        //dtor
        ~HighCard();
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
        virtual double getValueFromColor(string) const;
    protected:
        double highestNumber;
        string highestColor;
        double maxHighCard;
};
#endif