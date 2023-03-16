#include "FourOfAKind.hpp"

FourOfAKind::FourOfAKind() : FullHouse() {}

// ctor by input
FourOfAKind::FourOfAKind(Player c1, TableCard c2) : FullHouse(c1,c2){
    // this->maxFourOfAKind = 1.39 * 8;
    this->calculateMaxCombination(c1,c2);
}
// cctor
FourOfAKind::FourOfAKind(const FourOfAKind& C) : FullHouse(C){
    this->highestColor = C.getHighestColor();
}
// dtor
FourOfAKind::~FourOfAKind(){}

// calculate max value of a combo
void FourOfAKind::calculateMaxCombination(Player c1, TableCard c2){
    vector<Card> vec;
    double constant;
    
    if(!findMaxCombination(c1, c2).empty()){
        constant = FULLHOUSE;
        vec = findMaxCombination(c1, c2);
    }else if(!FullHouse::findMaxCombination(c1, c2).empty()){
        constant = FLUSH;
        vec = FullHouse::findMaxCombination(c1, c2);
    }else if(!Flush::findMaxCombination(c1, c2).empty()){
        constant = STRAIGHT;
        vec = Flush::findMaxCombination(c1, c2);
    }else if(!Straight::findMaxCombination(c1, c2).empty()){
        constant = THREE_OF_A_KIND;
        vec = Straight::findMaxCombination(c1, c2);
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
vector<Card> FourOfAKind::findMaxCombination(Player c1, TableCard c2){
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

    vector<Card> fourOfAKind;
    int count = 0;
    for (int i = combinations.size() - 1; i >= 3; i--) {
        if (combinations[i].getNumber() == combinations[i - 1].getNumber() && combinations[i-1].getNumber() == combinations[i-2].getNumber()
        && combinations[i-2].getNumber() == combinations[i-3].getNumber()) {
            fourOfAKind.push_back(combinations[i]);
            fourOfAKind.push_back(combinations[i-1]);
            fourOfAKind.push_back(combinations[i-2]);
            fourOfAKind.push_back(combinations[i-3]);
            break;
        }
    }
    if (fourOfAKind.size() < 4) {
        fourOfAKind.clear();
    }
    return fourOfAKind;
}