#include "Flush.hpp"

// ctor by input
Flush::Flush(Player c1, TableCard c2) : Straight(c1,c2){
    this->maxFlush = 5.56;
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
    vec = findMaxCombination(c1, c2);
    if(vec.empty()){
        this->Straight::calculateMaxCombination(c1,c2);
    }else{
        double num = vec[0].getNumber() * 0.1;
        double color = findHighestColor(vec);
        this->setHighestNumber(vec[0].getNumber());
        this->setHighestColor(getColorFromValue(color));
        this->setValue(num + color + this->maxStraight);
    }
}
vector<Card> Flush::findMaxCombination(Player c1, TableCard c2){
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

    vector<Card> flush;
    int count = 0;
    for (int i = allCards.size() - 1; i >= 2; i--) {
        if (allCards[i].getNumber() == allCards[i - 1].getNumber() && allCards[i-1].getNumber() == allCards[i-2].getNumber()) {
            flush.push_back(allCards[i]);
            flush.push_back(allCards[i-1]);
            flush.push_back(allCards[i-2]);
            break;
        }
    }
    if (flush.size() < 3) {
        flush.clear();
    }
    return flush;
}
// set value of a combo
void Flush::setValue(double val){
    this->totalValue = val;
}
// get value of a combo
double Flush::getValue(Player c1, TableCard c2) const{
    return this->totalValue;
}
void Flush::setHighestNumber(double val){
    this->highestNumber = val;
}
double Flush::getHighestNumber() const{
    return this->highestNumber;
}
void Flush::setHighestColor(string s){
    this->highestColor = s;
}
string Flush::getHighestColor() const{
    return this->highestColor;
}

double Flush::findHighestColor(vector<Card> c1){
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
double Flush::getValueFromColor(string color) const{
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
string Flush::getColorFromValue(double result) const{
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
