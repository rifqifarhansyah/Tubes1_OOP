#include "Pair.hpp"

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
    vec = findMaxCombination(c1, c2);
    
    if(vec.empty()){
        this->HighCard::calculateMaxCombination(c1,c2);
    }else{
        double num = findHighestNumber(vec);
        double color = findHighestColor(vec);
        this->setHighestNumber(num);
        this->setHighestColor(Card::getColorFromValue(color));
        this->setValue(num + color + HIGH_CARD);
    }
}
vector<Card> Pair::findMaxCombination(Player c1, TableCard c2){
    vector<Card> allCards;
    vector<Card> playerCards(2);
    vector<Card> tableCards(5);
    for (int i = playerCards.size() - 1; i >= 0; i--)
    {
        playerCards.push_back(c1.getItem(i));
    }
    for (int i = tableCards.size() - 1; i >= 0; i--)
    {
        tableCards.push_back(c2.getItem(i));
    }
    
    allCards.insert(allCards.end(), playerCards.begin(), playerCards.end());
    allCards.insert(allCards.end(), tableCards.begin(), tableCards.end());

    sort(allCards.begin(), allCards.end());

    vector<Card> pair;
    for (int i = allCards.size() - 1; i >= 1; i--) {
        if (allCards[i].getNumber() == allCards[i - 1].getNumber()) {
            pair.push_back(allCards[i]);
            pair.push_back(allCards[i - 1]);
            break;
        }
    }
    if(pair.size() != 2){
        pair.clear();
    }

    return pair;
}
