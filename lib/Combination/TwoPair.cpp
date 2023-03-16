#include "TwoPair.hpp"

TwoPair::TwoPair() : Pair(){}

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

    vector<Card> twoPair;
    int count = 0;
    for (int i = combinations.size() - 1; i >= 1; i--) {
        if (combinations[i].getNumber() == combinations[i - 1].getNumber()) {
            twoPair.push_back(combinations[i]);
            twoPair.push_back(combinations[i-1]);
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

    for (int i = combinations.size() - 1; i >= 1; i--) {
        if (combinations[i].getNumber() != twoPair[0].getNumber() && combinations[i].getNumber() != twoPair[1].getNumber() && combinations[i].getNumber() == combinations[i - 1].getNumber()) {
            twoPair.push_back(combinations[i]);
            twoPair.push_back(combinations[i - 1]);
            break;
        }
    }

    if (twoPair.size() < 4) {
        twoPair.clear();
        return twoPair;
    }

    return twoPair;
}