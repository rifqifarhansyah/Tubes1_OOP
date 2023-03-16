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
    double maxFlush = findHighestNumber(vec);
    double num = findFlushNumbers(vec);
    double color = findHighestColor(vec);
    this->setHighestNumber(maxFlush);
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
        vector<Card> colors;
        for (const Card& card : combinations) {
            if (card.getColor() == suit) {
                colors.push_back(card);
            }
        }
        if (colors.size() >= 5) {
            sort(colors.begin(), colors.end());
            for (int i = 0; i <= colors.size() - 5; i++) {
                if (colors[i].getNumber() - colors[i + 4].getNumber() == 4) {
                    flush.insert(flush.end(), colors.begin() + i, colors.begin() + i + 5);
                    return flush;
                }
            }
            flush.insert(flush.end(), colors.begin(), colors.begin() + 5);
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
    combinations.insert(combinations.end(), tableCard.begin(), tableCard.end());

    vector<Card> flush;
    for (const string& suit : {"merah", "kuning", "biru", "hijau"}) {
        vector<Card> colors;
        for (const Card& card : combinations) {
            if (card.getColor() == suit) {
                colors.push_back(card);
            }
        }
        if (colors.size() >= 5) {
            sort(colors.begin(), colors.end());
            for (int i = 0; i <= colors.size() - 5; i++) {
                if (colors[i].getNumber() - colors[i + 4].getNumber() == 4) {
                    flush.insert(flush.end(), colors.begin() + i, colors.begin() + i + 5);
                    return flush;
                }
            }
            flush.insert(flush.end(), colors.begin(), colors.begin() + 5);
            return flush;
        }
    }
    return flush;
}
double Flush::findFlushNumbers(vector<Card> c){
    double val = 0;
    double constant = 0.1;
    for (int i = 0; i < c.size(); i++)
    {
        val += c[i].getNumber() * constant;
        constant = constant * 0.1;
    }
    return val;
}