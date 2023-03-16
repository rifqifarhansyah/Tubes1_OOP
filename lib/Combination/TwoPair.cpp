#include "TwoPair.hpp"

// ctor by input
TwoPair::TwoPair(Player c1, TableCard c2) : Pair(c1,c2){
    // this->maxTwoPair = 4.17;
    this->calculateMaxCombination(c1,c2);
}
// cctor
TwoPair::TwoPair(const TwoPair& C) : Pair(C){
    this->highestColor = C.getHighestColor();
}
// dtor
TwoPair::~TwoPair(){}

// calculate max value of a combo
void TwoPair::calculateMaxCombination(Player c1, TableCard c2){
    vector<Card> vec;
    double constant;
    
    if(!findMaxCombination(c1, c2).empty()){
        constant = PAIR;
        vec = findMaxCombination(c1, c2);
    }else if(!Pair::findMaxCombination(c1, c2).empty()){
        constant = HIGH_CARD;
        vec = Pair::findMaxCombination(c1, c2);
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
vector<Card> TwoPair::findMaxCombination(Player c1, TableCard c2){
    vector<Card> allCards;
    vector<Card> playerCards;
    vector<Card> tableCards;
    for (int i = 1; i >= 0; i--)
    {
        playerCards.push_back(c1.getItem(i));
    }
    for (int i = 4; i >= 0; i--)
    {
        tableCards.push_back(c2.getItem(i));
    }
    
    allCards.insert(allCards.end(), playerCards.begin(), playerCards.end());
    allCards.insert(allCards.end(), tableCards.begin(), tableCards.end());

    sort(allCards.begin(), allCards.end());

    vector<Card> twoPair;
    int count = 0;
    for (int i = allCards.size() - 1; i >= 1; i--) {
        if (allCards[i].getNumber() == allCards[i - 1].getNumber()) {
            twoPair.push_back(allCards[i]);
            twoPair.push_back(allCards[i-1]);
            count += 2;
            if(count == 2){
                break;
            }
        }
    }
    if (count < 2) {
        twoPair.clear();
        return twoPair;
    }

    for (int i = allCards.size() - 1; i >= 1; i--) {
        if (allCards[i].getNumber() != twoPair[0].getNumber() && allCards[i].getNumber() != twoPair[1].getNumber() && allCards[i].getNumber() == allCards[i - 1].getNumber()) {
            twoPair.push_back(allCards[i]);
            twoPair.push_back(allCards[i - 1]);
            break;
        }
    }

    if (twoPair.size() < 4) {
        twoPair.clear();
        return twoPair;
    }

    return twoPair;
}