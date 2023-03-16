#include "FourOfAKind.hpp"

// ctor by input
FourOfAKind::FourOfAKind(Player player, TableCard table) : FullHouse(player,table){
    // this->maxFourOfAKind = 1.39 * 8;
    this->calculateMaxCombination();
}
// cctor
FourOfAKind::FourOfAKind(const FourOfAKind& C) : FullHouse(C){
    this->highestColor = C.getHighestColor();
}
// dtor
FourOfAKind::~FourOfAKind(){}

// calculate max value of a combo
void FourOfAKind::calculateMaxCombination(){
    vector<Card> vec;
    double constant;
    
    if(!findMaxCombinationAll().empty()){
        constant = FULLHOUSE;
        vec = findMaxCombinationAll();
    }else if(!FullHouse::findMaxCombinationAll().empty()){
        constant = FLUSH;
        vec = FullHouse::findMaxCombinationAll();
    }else if(!Flush::findMaxCombinationAll().empty()){
        constant = STRAIGHT;
        vec = Flush::findMaxCombinationAll();
    }else if(!Straight::findMaxCombinationAll().empty()){
        constant = THREE_OF_A_KIND;
        vec = Straight::findMaxCombinationAll();
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
vector<Card> FourOfAKind::findMaxCombinationAll(){
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