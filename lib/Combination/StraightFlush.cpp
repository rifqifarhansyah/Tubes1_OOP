#include "StraightFlush.hpp"

// ctor by input
StraightFlush::StraightFlush(Player player, TableCard table) : FourOfAKind(player,table){
    this->calculateMaxCombination();
}
// cctor
StraightFlush::StraightFlush(const StraightFlush& C) : FourOfAKind(C){
    this->highestColor = C.getHighestColor();
}
// dtor
StraightFlush::~StraightFlush(){}

// calculate max value of a combo
void StraightFlush::calculateMaxCombination(){
    vector<Card> vec;
    double constant;
    
    if(!findMaxCombinationAll().empty()){
        constant = FOUR_OF_A_KIND;
        vec = findMaxCombinationAll();
    }else if(!FourOfAKind::findMaxCombinationAll().empty()){
        constant = FULLHOUSE;
        vec = FourOfAKind::findMaxCombinationAll();
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
vector<Card> StraightFlush::findMaxCombinationAll(){
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
    
    combinations.insert(combinations.end(), tableCard.begin(), tableCard.end());

    sort(combinations.begin(), combinations.end());

    vector<Card> straightFlush;
    for (int i = combinations.size() - 1; i >= 4; i--) {
        if (combinations[i].getColor() == combinations[i - 1].getColor() &&
            combinations[i - 1].getColor() == combinations[i - 2].getColor() &&
            combinations[i - 2].getColor() == combinations[i - 3].getColor() &&
            combinations[i - 3].getColor() == combinations[i - 4].getColor()) {
                
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
vector<Card> StraightFlush::findMaxCombinationTable(){
    vector<Card> combinations;
    vector<Card> playerCard;
    vector<Card> tableCard;
    for (int i = 4; i >= 0; i--)
    {
        tableCard.push_back(table.getItem(i));
    }
    
    combinations.insert(combinations.end(), playerCard.begin(), playerCard.end());
    combinations.insert(combinations.end(), tableCard.begin(), tableCard.end());

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

