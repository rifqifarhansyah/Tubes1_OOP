#include "ThreeOfAKind.hpp"

ThreeOfAKind::ThreeOfAKind() : TwoPair(){}

// ctor by input
ThreeOfAKind::ThreeOfAKind(Player player, TableCard table) : TwoPair(player,table){
    // this->maxThreeOfAKind = 5.56;
    this->calculateMaxCombination();
}
// cctor
ThreeOfAKind::ThreeOfAKind(const ThreeOfAKind& C) : TwoPair(C){
    this->highestColor = C.getHighestColor();
}
// dtor
ThreeOfAKind::~ThreeOfAKind(){}

// calculate max value of a combo
void ThreeOfAKind::calculateMaxCombination(){
    vector<Card> vec;
    double constant;
    
    if(!findMaxCombinationAll().empty()){
        constant = TWO_PAIR;
        vec = findMaxCombinationAll();
    }else if(!TwoPair::findMaxCombinationAll().empty()){
        constant = PAIR;
        vec = TwoPair::findMaxCombinationAll();
    }else if(!Pair::findMaxCombinationAll().empty()){
        constant = HIGH_CARD;
        vec = Pair::findMaxCombinationAll();
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
vector<Card> ThreeOfAKind::findMaxCombinationAll(){
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
bool operator< (const ThreeOfAKind& p1, const ThreeOfAKind&p2){
    return (p1.getValue() < p2.getValue());
}
bool operator> (const ThreeOfAKind& p1, const ThreeOfAKind&p2){
    return (p1.getValue() > p2.getValue());
}
