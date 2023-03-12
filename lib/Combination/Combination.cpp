#include "Combination.hpp"

Combination::Combination(Player c1, TableCard c2){
    this->totalValue = 0;
}
Combination::Combination(const Combination& C){
    this->totalValue = C.totalValue;
}
Combination::~Combination(){}