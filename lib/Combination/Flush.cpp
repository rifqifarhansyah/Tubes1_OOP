#include "Flush.hpp"

// ctor by input
Flush::Flush(Player player, TableCard table) : Straight(player,table){
    // this->maxFlush = 1.39 * 6;
    this->calculateMaxCombination();
}
// cctor
Flush::Flush(const Flush& C) : Straight(C){
    this->highestColor = C.getHighestColor();
}
// dtor
Flush::~Flush(){}

// calculate max value of a combo
void Flush::calculateMaxCombination(){
    vector<Card> vec;
    double constant;
    
    if(!findMaxCombinationAll().empty()){
        constant = STRAIGHT;
        vec = findMaxCombinationAll();
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
vector<Card> Flush::findMaxCombinationAll(){
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
vector<Card> Flush::findMaxCombinationTable(){
    vector<Card> combinations;
    vector<Card> playerCard;
    vector<Card> tableCard;
    for (int i = 4; i >= 0; i--)
    {
        tableCard.push_back(table.getItem(i));
    }
    
    combinations.insert(combinations.end(), playerCard.begin(), playerCard.end());
    combinations.insert(combinations.end(), tableCard.begin(), tableCard.end());

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
vector<Card> Flush::findFlushNumbers(vector<Card> c){
    
}