#include "FullHouse.hpp"

// ctor by input
FullHouse::FullHouse(Player c1, TableCard c2) : Flush(c1,c2){
    this->maxFullHouse = 1.39 * 7;
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
    vec = findMaxCombination(c1, c2);
    if(vec.empty()){
        this->Flush::calculateMaxCombination(c1,c2);
    }else{
        double num = vec[0].getNumber() * 0.1;
        double color = findHighestColor(vec);
        this->setHighestNumber(vec[0].getNumber());
        this->setHighestColor(getColorFromValue(color));
        this->setValue(num + color + this->maxFlush);
    }
}
vector<Card> FullHouse::findMaxCombination(Player c1, TableCard c2){
    vector<Card> allCards;
    vector<Card> playerCards(2);
    vector<Card> tableCards(5);
    for (int i = playerCards.size() - 1; i >= 0; i--)
    {
        playerCards.push_back(c1.getItem(i));
    }
    for (int i = tableCards.size() - 1; i >= 0; i--)
    {
        tableCards.push_back(c2.getItem(i));
    }
    
    allCards.insert(allCards.end(), playerCards.begin(), playerCards.end());
    allCards.insert(allCards.end(), tableCards.begin(), tableCards.end());

    sort(allCards.begin(), allCards.end(), [](const Card& card1, const Card& card2) 
    {card1.getNumber() > card2.getNumber();});

    vector<Card> fullHouse;
    bool foundThreeOfAKind = false;
    bool foundPair = false;

    for (int i = 0; i < allCards.size() - 1; i++) {
        if (allCards[i].getNumber() == allCards[i + 1].getNumber()) {
            if (!foundThreeOfAKind) {
                foundThreeOfAKind = true;
                fullHouse.clear();
                fullHouse.push_back(allCards[i]);
                fullHouse.push_back(allCards[i + 1]);
            } else if (foundPair && allCards[i].getNumber() != fullHouse[0].getNumber()) {
                fullHouse.push_back(allCards[i]);
                return fullHouse;
            } else if (!foundPair && allCards[i].getNumber() != fullHouse[0].getNumber()) {
                foundPair = true;
                fullHouse.push_back(allCards[i]);
                fullHouse.push_back(allCards[i + 1]);
            }
        } else if (foundThreeOfAKind && foundPair) {
            return fullHouse;
        } else {
            foundThreeOfAKind = false;
            foundPair = false;
        }
    }

    fullHouse.clear();
    return fullHouse;
}
// set value of a combo
void FullHouse::setValue(double val){
    this->totalValue = val;
}
// get value of a combo
double FullHouse::getValue(Player c1, TableCard c2) const{
    return this->totalValue;
}
void FullHouse::setHighestNumber(double val){
    this->highestNumber = val;
}
double FullHouse::getHighestNumber() const{
    return this->highestNumber;
}
void FullHouse::setHighestColor(string s){
    this->highestColor = s;
}
string FullHouse::getHighestColor() const{
    return this->highestColor;
}

double FullHouse::findHighestColor(vector<Card> c1){
    double max = 0;
    for (int i = 0; i < c1.size(); i++)
    {
        if (c1[i].getColor() == "merah" && max < 3){
            max = this->getValueFromColor(c1[i].getColor());
        } else if (c1[i].getColor() == "kuning" && max <= 2){
            max == this->getValueFromColor(c1[i].getColor());
        } else if (c1[i].getColor() == "biru" && max <= 1){
            max = this->getValueFromColor(c1[i].getColor());
        } else if (c1[i].getColor() == "hijau" && max == 0){
            max = this->getValueFromColor(c1[i].getColor());
        }
    }

    return max;
}
double FullHouse::getValueFromColor(string color) const{
    if(color == "merah"){
        return 3;
    } else if(color == "kuning"){
        return 2;
    } else if(color == "biru"){
        return 1;
    } else if(color == "hijau"){
        return 0;
    }
}
string FullHouse::getColorFromValue(double result) const{
    string color;
    if(result == 3){
        color == "merah";
    } else if(result == 2){
        color == "kuning";
    } else if(result == 1){
        color == "biru";
    } else if(result == 0){
        color == "hijau";
    }
    return color;
}
