#include "FullHouse.hpp"

// ctor by input
FullHouse::FullHouse(Player c1, TableCard c2) : Flush(c1,c2){
    // this->maxFullHouse = 1.39 * 7;
    this->calculateMaxCombination(c1,c2);
}
// cctor
FullHouse::FullHouse(const FullHouse& C) : Flush(C){
    this->highestColor = C.getHighestColor();
}
// dtor
FullHouse::~FullHouse(){}

// calculate max value of a combo
void FullHouse::calculateMaxCombination(Player c1, TableCard c2){
    vector<Card> vec;
    double constant;
    
    if(!findMaxCombination(c1, c2).empty()){
        constant = FLUSH;
        vec = findMaxCombination(c1, c2);
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
    double num = findMaxThreeOfAKind(vec) * 0.1;
    double color = findHighestColor(vec);
    this->setHighestNumber(num);
    this->setHighestColor(Card::getColorFromValue(color));
    this->setValue(num + color + constant);
}
vector<Card> FullHouse::findMaxCombination(Player c1, TableCard c2){
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