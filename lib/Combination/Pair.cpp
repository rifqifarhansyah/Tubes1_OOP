#include "Pair.hpp"

Pair::Pair() : HighCard(){}

// ctor by input
Pair::Pair(Player player, TableCard table) : HighCard(player,table){
    // this->maxPair = 2.78;
    this->calculateMaxCombination();
}
// cctor
Pair::Pair(const Pair& C) : HighCard(C){
    this->highestColor = C.highestColor;
}
// dtor
Pair::~Pair(){}

// calculate max value of a combo
void Pair::calculateMaxCombination(){
    vector<Card> vec;
    double constant;
    
    if(!findMaxCombinationAll().empty()){
        constant = HIGH_CARD;
        vec = findMaxCombinationAll();

    }else if(!HighCard::findMaxCombinationAll().empty()){
        constant = 0;
        vec = HighCard::findMaxCombinationAll();
    }
    double num = findHighestNumber(vec) * 0.1;
    double color = findHighestColor(vec);
    this->setHighestNumber(num);
    this->setHighestColor(Card::getColorFromValue(color));
    this->setValue(num + color + constant);
    
}
vector<Card> Pair::findMaxCombinationAll(){
    vector<Card> combinations;
    vector<Card> playerCard;
    vector<Card> tableCard;
    for (int i = 1; i >= 0; i--)
    {
        playerCard.push_back(player.getItem(i));
    }
    for (int i = 4; i >= 0; i--)
    {
        tableCard.push_back(table.getItem(i));
    }
    
    combinations.insert(combinations.end(), playerCard.begin(), playerCard.end());
    combinations.insert(combinations.end(), tableCard.begin(), tableCard.end());

    sort(combinations.begin(), combinations.end());

    vector<Card> pair;
    for (int i = combinations.size() - 1; i >= 1; i--) {
        if (combinations[i].getNumber() == combinations[i - 1].getNumber()) {
            pair.push_back(combinations[i]);
            pair.push_back(combinations[i - 1]);
            break;
        }
    }
    if(pair.size() != 2){
        pair.clear();
        
    }

    return pair;
}
