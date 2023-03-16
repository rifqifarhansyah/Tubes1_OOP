#include "Straight.hpp"

Straight::Straight() : ThreeOfAKind(){}

// ctor by input
Straight::Straight(Player player, TableCard table) : ThreeOfAKind(player,table){
    // this->maxStraight = 6.95;
    this->calculateMaxCombination();
}
// cctor
Straight::Straight(const Straight& C) : ThreeOfAKind(C){
    this->highestColor = C.getHighestColor();
}
// dtor
Straight::~Straight(){}

// calculate max value of a combo
void Straight::calculateMaxCombination(){
    vector<Card> vec;
    double constant;
    
    if(!findMaxCombinationAll().empty()){
        constant = THREE_OF_A_KIND;
        vec = findMaxCombinationAll();
    }else if(!ThreeOfAKind::findMaxCombinationAll().empty()){
        constant = TWO_PAIR;
        vec = ThreeOfAKind::findMaxCombinationAll();
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
vector<Card> Straight::findMaxCombinationAll(){
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
