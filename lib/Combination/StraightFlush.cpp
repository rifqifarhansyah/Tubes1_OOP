#include "StraightFlush.hpp"

StraightFlush::StraightFlush() : FourOfAKind(){}

// ctor by input
StraightFlush::StraightFlush(Player c1, TableCard c2) : FourOfAKind(c1,c2){
    this->calculateMaxCombination(c1,c2);
}
// cctor
StraightFlush::StraightFlush(const StraightFlush& C) : FourOfAKind(C){
    this->highestColor = C.getHighestColor();
}
// dtor
StraightFlush::~StraightFlush(){}

// calculate max value of a combo
void StraightFlush::calculateMaxCombination(Player c1, TableCard c2){
    vector<Card> vec;
    double constant;
    
    if(!findMaxCombination(c1, c2).empty()){
        constant = FOUR_OF_A_KIND;
        vec = findMaxCombination(c1, c2);
    }else if(!FourOfAKind::findMaxCombination(c1, c2).empty()){
        constant = FULLHOUSE;
        vec = FourOfAKind::findMaxCombination(c1, c2);
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
vector<Card> StraightFlush::findMaxCombination(Player c1, TableCard c2){
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

    vector<Card> straightFlush;
    for (int i = combinations.size() - 1; i >= 4; i--) {
        if (combinations[i].getColor() == combinations[i - 1].getColor() &&
            combinations[i - 1].getColor() == combinations[i - 2].getColor() &&
            combinations[i - 2].getColor() == combinations[i - 3].getColor() &&
            combinations[i - 3].getColor() == combinations[i - 4].getColor()) {
            // Found a possible straight flush starting with card i
            bool isStraightFlush = true;
            int currentNumber = combinations[i].getNumber();
            for (int j = i - 1; j >= i - 4; j--) {
                if (combinations[j].getNumber() != currentNumber - 1) {
                    isStraightFlush = false;
                    break;
                }
                currentNumber--;
            }
            if (isStraightFlush) {
                straightFlush.push_back(combinations[i]);
                straightFlush.push_back(combinations[i - 1]);
                straightFlush.push_back(combinations[i - 2]);
                straightFlush.push_back(combinations[i - 3]);
                straightFlush.push_back(combinations[i - 4]);
                break;
            }
        }
    }
    return straightFlush;
}
vector<Card> StraightFlush::findMaxCombination(TableCard c2){
    vector<Card> combinations;
    vector<Card> player;
    vector<Card> table;
    for (int i = 4; i >= 0; i--)
    {
        table.push_back(c2.getItem(i));
    }
    
    combinations.insert(combinations.end(), player.begin(), player.end());
    combinations.insert(combinations.end(), table.begin(), table.end());

    sort(combinations.begin(), combinations.end());

    vector<Card> straightFlush;
    for (int i = combinations.size() - 1; i >= 4; i--) {
        if (combinations[i].getColor() == combinations[i - 1].getColor() &&
            combinations[i - 1].getColor() == combinations[i - 2].getColor() &&
            combinations[i - 2].getColor() == combinations[i - 3].getColor() &&
            combinations[i - 3].getColor() == combinations[i - 4].getColor()) {
            // Found a possible straight flush starting with card i
            bool isStraightFlush = true;
            int currentNumber = combinations[i].getNumber();
            for (int j = i - 1; j >= i - 4; j--) {
                if (combinations[j].getNumber() != currentNumber - 1) {
                    isStraightFlush = false;
                    break;
                }
                currentNumber--;
            }
            if (isStraightFlush) {
                straightFlush.push_back(combinations[i]);
                straightFlush.push_back(combinations[i - 1]);
                straightFlush.push_back(combinations[i - 2]);
                straightFlush.push_back(combinations[i - 3]);
                straightFlush.push_back(combinations[i - 4]);
                break;
            }
        }
    }
    return straightFlush;
}
bool operator< (StraightFlush& p1, StraightFlush&p2){
    return (p1.getValue() < p2.getValue());
}
bool operator> (StraightFlush& p1, StraightFlush&p2){
    return (p1.getValue() > p2.getValue());
}

