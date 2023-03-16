#include "FullHouse.hpp"

// ctor by input
FullHouse::FullHouse(Player player, TableCard table) : Flush(player,table){
    // this->maxFullHouse = 1.39 * 7;
    this->calculateMaxCombination();
}
// cctor
FullHouse::FullHouse(const FullHouse& C) : Flush(C){
    this->highestColor = C.getHighestColor();
}
// dtor
FullHouse::~FullHouse(){}

// calculate max value of a combo
void FullHouse::calculateMaxCombination(){
    vector<Card> vec;
    double constant;
    
    if(!findMaxCombinationAll().empty()){
        constant = FLUSH;
        vec = findMaxCombinationAll();
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
    double num = findMaxThreeOfAKind(vec) * 0.1;
    double color = findHighestColor(vec);
    this->setHighestNumber(num);
    this->setHighestColor(Card::getColorFromValue(color));
    this->setValue(num + color + constant);
}
vector<Card> FullHouse::findMaxCombinationAll(){
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
    

    vector<Card> fullHouse;
    // Find three-of-a-kind
    for (int i = combinations.size() - 1; i >= 2; i--) {
        if (combinations[i].getNumber() == combinations[i - 1].getNumber() &&
            combinations[i - 1].getNumber() == combinations[i - 2].getNumber()) {
            fullHouse.push_back(combinations[i]);
            fullHouse.push_back(combinations[i - 1]);
            fullHouse.push_back(combinations[i - 2]);
            break;
        }
    }

    if (fullHouse.size() < 3) {
        fullHouse.clear();
        return fullHouse;
    }

    // Find pair
    for (int i = combinations.size() - 1; i >= 1; i--) {
        if (combinations[i].getNumber() == fullHouse[0].getNumber()) {
            continue;
        }
        if (combinations[i].getNumber() == combinations[i - 1].getNumber()) {
            fullHouse.push_back(combinations[i]);
            fullHouse.push_back(combinations[i - 1]);
            return fullHouse;
        }
    }

    fullHouse.clear();
    return fullHouse;
}

double FullHouse::findMaxThreeOfAKind(const vector<Card>& cards) {
    int maxThreeOfAKind = 0;
    for (int i = 0; i < cards.size() - 2; i++) {
        if (cards[i].getNumber() == cards[i + 1].getNumber() &&
            cards[i + 1].getNumber() == cards[i + 2].getNumber()) {
            int threeOfAKind = cards[i].getNumber();
        }
    }
    return maxThreeOfAKind;
}