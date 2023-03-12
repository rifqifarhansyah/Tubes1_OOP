#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include <string>
#include <vector>
#include "PlayerCard.hpp"
#include "TableCard.hpp"
using namespace std;

class Combination : public Player, public TableCard{
    public:
        Combination(Player , TableCard );
        Combination(const Combination&);
        ~Combination();
        virtual double getValue(Player, TableCard) const = 0;
    protected:
        double totalValue;
};
#endif