#include "Straight.hpp"

Straight::Straight() : ThreeOfAKind(){}

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

    vector<Card> straight;
    int i = combinations.size() - 1;

    while (i >= 4) {
        if (combinations[i].getNumber() - 1 == combinations[i - 1].getNumber() &&
            combinations[i - 1].getNumber() - 1 == combinations[i - 2].getNumber() &&
            combinations[i - 2].getNumber()- 1 == combinations[i - 3].getNumber()&&
            combinations[i - 3].getNumber() - 1 == combinations[i - 4].getNumber()) {
            straight.push_back(combinations[i]);
            straight.push_back(combinations[i - 1]);
            straight.push_back(combinations[i - 2]);
            straight.push_back(combinations[i - 3]);
            straight.push_back(combinations[i - 4]);
            break;
        }
        i--;
    }
    return straight;
}
