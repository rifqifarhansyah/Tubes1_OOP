#include "Combination.hpp"

Combination::Combination(Player player, TableCard table){
    this->player = player;
    this->table = table;
    this->totalValue = 0;
}
Combination::Combination(const Combination& C){
    this->player = C.player;
    this->table = C.table;
    this->totalValue = C.totalValue;
}
Combination::~Combination(){}