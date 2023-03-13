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
        // get value of a combo
        double getValue(Player, TableCard) const;
        void setValue(double);
        virtual void calculateMaxCombination(Player, TableCard);
        virtual vector<vector<double,string>> findMaxCombination(Player, TableCard);
        virtual string getHighestColor(string, string) const;
        virtual void setHighestColor(string);
        virtual void findHighestColor(vector<string>, vector<string>);
        virtual double getValueFromColor(string) const;
        bool isPair(Player, TableCard);
    // protected:
    //     int PairValue;
};
#endif