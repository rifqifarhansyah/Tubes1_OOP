#include "Pair.hpp"

Pair::Pair() : HighCard(){}

// ctor by input
Pair::Pair(Player c1, TableCard c2) : HighCard(c1,c2){
    // this->maxPair = 2.78;
    this->calculateMaxCombination(c1,c2);
}
// cctor
Pair::Pair(const Pair& C) : HighCard(C){
    this->highestColor = C.highestColor;
}
// dtor
Pair::~Pair(){}

// calculate max value of a combo
void Pair::calculateMaxCombination(Player c1, TableCard c2){
    vector<Card> vec;
    double constant;
    
    if(!findMaxCombination(c1, c2).empty()){
        // vec = this->HighCard::findMaxCombination(c1,c2);
        // double num = findHighestNumber(vec) * 0.1;
        // double color = findHighestColor(vec);
        // this->setHighestNumber(num);
        // this->setHighestColor(Card::getColorFromValue(color));
        // this->setValue(num + color + HIGH_CARD);
        constant = HIGH_CARD;
        vec = findMaxCombination(c1, c2);

    }else if(!HighCard::findMaxCombination(c1, c2).empty()){
        constant = 0;
        vec = HighCard::findMaxCombination(c1, c2);
    }
    double num = findHighestNumber(vec) * 0.1;
    double color = findHighestColor(vec);
    this->setHighestNumber(num);
    this->setHighestColor(Card::getColorFromValue(color));
    this->setValue(num + color + constant);
    
}
vector<Card> Pair::findMaxCombination(Player c1, TableCard c2){
    vector<Card> combinations;
    vector<Card> player;
    vector<Card> table;
    for (int i = 1; i >= 0; i--)
    {
        player.push_back(c1.getItem(i));
    }
    for (int i = 4; i >= 0; i--)
    {
        table.push_back(c2.getItem(i));
    }
    
    combinations.insert(combinations.end(), player.begin(), player.end());
    combinations.insert(combinations.end(), table.begin(), table.end());

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
