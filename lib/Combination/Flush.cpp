#include "Flush.hpp"

Flush::Flush() : Straight(){}

// ctor by input
Flush::Flush(Player c1, TableCard c2) : Straight(c1,c2){
    // this->maxFlush = 1.39 * 6;
    this->calculateMaxCombination(c1,c2);
}
// cctor
Flush::Flush(const Flush& C) : Straight(C){
    this->highestColor = C.getHighestColor();
}
// dtor
Flush::~Flush(){}

// calculate max value of a combo
void Flush::calculateMaxCombination(Player c1, TableCard c2){
    vector<Card> vec;
    double constant;
    
    if(!findMaxCombination(c1, c2).empty()){
        constant = STRAIGHT;
        vec = findMaxCombination(c1, c2);
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
vector<Card> Flush::findMaxCombination(Player c1, TableCard c2){
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

    vector<Card> flush;
    for (const string& suit : {"merah", "kuning", "biru", "hijau"}) {
        vector<Card> suitCards;
        for (const Card& card : combinations) {
            if (card.getColor() == suit) {
                suitCards.push_back(card);
            }
        }
        if (suitCards.size() >= 5) {
            sort(suitCards.begin(), suitCards.end());
            for (int i = 0; i <= suitCards.size() - 5; i++) {
                if (suitCards[i].getNumber() - suitCards[i + 4].getNumber() == 4) {
                    flush.insert(flush.end(), suitCards.begin() + i, suitCards.begin() + i + 5);
                    return flush;
                }
            }
            flush.insert(flush.end(), suitCards.begin(), suitCards.begin() + 5);
            return flush;
        }
    }
    return flush;
}
vector<Card> Flush::findMaxCombination(TableCard c2){
    vector<Card> combinations;
    vector<Card> player;
    vector<Card> table;
    for (int i = 4; i >= 0; i--)
    {
        table.push_back(c2.getItem(i));
    }
    
    combinations.insert(combinations.end(), player.begin(), player.end());
    combinations.insert(combinations.end(), table.begin(), table.end());

    vector<Card> flush;
    for (const string& suit : {"merah", "kuning", "biru", "hijau"}) {
        vector<Card> suitCards;
        for (const Card& card : combinations) {
            if (card.getColor() == suit) {
                suitCards.push_back(card);
            }
        }
        if (suitCards.size() >= 5) {
            sort(suitCards.begin(), suitCards.end());
            for (int i = 0; i <= suitCards.size() - 5; i++) {
                if (suitCards[i].getNumber() - suitCards[i + 4].getNumber() == 4) {
                    flush.insert(flush.end(), suitCards.begin() + i, suitCards.begin() + i + 5);
                    return flush;
                }
            }
            flush.insert(flush.end(), suitCards.begin(), suitCards.begin() + 5);
            return flush;
        }
    }
    return flush;
}
