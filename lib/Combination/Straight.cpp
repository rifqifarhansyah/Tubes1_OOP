#include "Straight.hpp"

// ctor by input
Straight::Straight(Player c1, TableCard c2) : ThreeOfAKind(c1,c2){
    // this->maxStraight = 6.95;
    this->calculateMaxCombination(c1,c2);
}
// cctor
Straight::Straight(const Straight& C) : ThreeOfAKind(C){
    this->highestColor = C.getHighestColor();
}
// dtor
Straight::~Straight(){}

// calculate max value of a combo
void Straight::calculateMaxCombination(Player c1, TableCard c2){
    vector<Card> vec;
    double constant;
    
    if(!findMaxCombination(c1, c2).empty()){
        constant = THREE_OF_A_KIND;
        vec = findMaxCombination(c1, c2);
    }else if(!ThreeOfAKind::findMaxCombination(c1, c2).empty()){
        constant = TWO_PAIR;
        vec = ThreeOfAKind::findMaxCombination(c1, c2);
    }else if(!TwoPair::findMaxCombination(c1, c2).empty()){
        constant = PAIR;
        vec = TwoPair::findMaxCombination(c1, c2);
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
vector<Card> Straight::findMaxCombination(Player c1, TableCard c2){
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

    vector<Card> straight;
    int i = allCards.size() - 1;

    while (i >= 4) {
        if (allCards[i].getNumber() - 1 == allCards[i - 1].getNumber() &&
            allCards[i - 1].getNumber() - 1 == allCards[i - 2].getNumber() &&
            allCards[i - 2].getNumber()- 1 == allCards[i - 3].getNumber()&&
            allCards[i - 3].getNumber() - 1 == allCards[i - 4].getNumber()) {
            straight.push_back(allCards[i]);
            straight.push_back(allCards[i - 1]);
            straight.push_back(allCards[i - 2]);
            straight.push_back(allCards[i - 3]);
            straight.push_back(allCards[i - 4]);
            break;
        }
        i--;
    }
    return straight;
}
