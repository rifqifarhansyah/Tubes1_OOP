#include "TwoPair.hpp"

// ctor by input
TwoPair::TwoPair(Player c1, TableCard c2) : Pair(c1,c2){
    this->maxTwoPair = 4.17;
    this->calculateMaxCombination(c1,c2);
}
// cctor
TwoPair::TwoPair(const TwoPair& C) : Pair(C){
    this->highestColor = C.getHighestColor();
}
// dtor
TwoPair::~TwoPair(){}

// calculate max value of a combo
void TwoPair::calculateMaxCombination(Player c1, TableCard c2){
    vector<Card> vec;
    vec = findMaxCombination(c1, c2);
    if(vec.empty()){
        this->Pair::calculateMaxCombination(c1,c2);
    }else{
        double num = vec[0].getNumber() * 0.1;
        double color = findHighestColor(vec);
        this->setHighestNumber(vec[0].getNumber());
        this->setHighestColor(getColorFromValue(color));
        this->setValue(num + color + this->maxPair);
    }
}
vector<Card> TwoPair::findMaxCombination(Player c1, TableCard c2){
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

    sort(allCards.begin(), allCards.end());

    vector<Card> twoPair;
    int count = 0;
    for (int i = allCards.size() - 1; i >= 1; i--) {
        if (allCards[i].getNumber() == allCards[i - 1].getNumber()) {
            twoPair.push_back(allCards[i]);
            if(count == 2){
                break;
            }
        }
    }
    if (count < 2) {
        twoPair.clear();
        return twoPair;
    }

    for (int i = allCards.size() - 1; i >= 1; i--) {
        if (allCards[i].getNumber() != twoPair[0].getNumber() && allCards[i].getNumber() != twoPair[1].getNumber() && allCards[i].getNumber() == allCards[i - 1].getNumber()) {
            twoPair.push_back(allCards[i]);
            twoPair.push_back(allCards[i - 1]);
            break;
        }
    }

    if (twoPair.size() < 4) {
        twoPair.clear();
        return twoPair;
    }

    return twoPair;
}
// set value of a combo
void TwoPair::setValue(double val){
    this->totalValue = val;
}
// get value of a combo
double TwoPair::getValue(Player c1, TableCard c2) const{
    return this->totalValue;
}
void TwoPair::setHighestNumber(double val){
    this->highestNumber = val;
}
double TwoPair::getHighestNumber() const{
    return this->highestNumber;
}
void TwoPair::setHighestColor(string s){
    this->highestColor = s;
}
string TwoPair::getHighestColor() const{
    return this->highestColor;
}

double TwoPair::findHighestColor(vector<Card> c1){
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
double TwoPair::getValueFromColor(string color) const{
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
string TwoPair::getColorFromValue(double result) const{
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
