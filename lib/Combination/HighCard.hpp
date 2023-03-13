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
        // get value of a combo
        double getValue(Player, TableCard) const;
        void setValue(double);
        virtual vector<vector<double,string>> findMaxCombination(Player, TableCard);
        virtual void calculateMaxCombination(Player, TableCard);
        virtual string getHighestColor(string, string) const;
        virtual void setHighestColor(string);
        virtual double getValueFromColor(string) const;
    protected:
        string highestColor;
};
#endif