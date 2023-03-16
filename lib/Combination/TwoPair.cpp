#include "TwoPair.hpp"

TwoPair::TwoPair() : Pair(){}

// ctor by input
TwoPair::TwoPair(Player player, TableCard table) : Pair(player,table){
    // this->maxTwoPair = 4.17;
    this->calculateMaxCombination();
}
// cctor
TwoPair::TwoPair(const TwoPair& C) : Pair(C){
    this->highestColor = C.getHighestColor();
}
// dtor
TwoPair::~TwoPair(){}

// calculate max value of a combo
void TwoPair::calculateMaxCombination(){
    vector<Card> vec;
    double constant;
    
    if(!findMaxCombinationAll().empty()){
        constant = PAIR;
        vec = findMaxCombinationAll();
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
vector<Card> TwoPair::findMaxCombinationAll(){
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