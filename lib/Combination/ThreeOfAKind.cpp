#include "ThreeOfAKind.hpp"

// ctor by input
ThreeOfAKind::ThreeOfAKind(Player c1, TableCard c2) : TwoPair(c1,c2){
    // this->maxThreeOfAKind = 5.56;
    this->calculateMaxCombination(c1,c2);
}
// cctor
ThreeOfAKind::ThreeOfAKind(const ThreeOfAKind& C) : TwoPair(C){
    this->highestColor = C.getHighestColor();
}
// dtor
ThreeOfAKind::~ThreeOfAKind(){}

// calculate max value of a combo
void ThreeOfAKind::calculateMaxCombination(Player c1, TableCard c2){
    vector<Card> vec;
    double constant;
    
    if(!findMaxCombination(c1, c2).empty()){
        constant = TWO_PAIR;
        vec = findMaxCombination(c1, c2);
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
vector<Card> ThreeOfAKind::findMaxCombination(Player c1, TableCard c2){
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

    vector<Card> ThreeOfAKind;
    int count = 0;
    for (int i = combinations.size() - 1; i >= 2; i--) {
        if (combinations[i].getNumber() == combinations[i - 1].getNumber() && combinations[i-1].getNumber() == combinations[i-2].getNumber()) {
            ThreeOfAKind.push_back(combinations[i]);
            ThreeOfAKind.push_back(combinations[i-1]);
            ThreeOfAKind.push_back(combinations[i-2]);
            break;
        }
    }
    if (ThreeOfAKind.size() < 3) {
        ThreeOfAKind.clear();
    }
    return ThreeOfAKind;
}
