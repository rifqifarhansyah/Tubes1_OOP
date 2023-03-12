#include "HighCard.hpp"

// ctor by input
HighCard::HighCard(Player c1, TableCard c2) : Combination(c1,c2){
    // this->highestColor = "hijau";
    this->calculateMaxCombination(c1,c2);
}
// cctor
HighCard::HighCard(const HighCard& C) : Combination(C){
    this->highestColor = C.highestColor;
}
// dtor
HighCard::~HighCard(){}

// set value of a combo
void HighCard::setValue(double val){
    this->totalValue = val;
}
// get value of a combo
double HighCard::getValue(Player c1, TableCard c2) const{
    return this->totalValue;
}
// calculate max value of a combo
void HighCard::calculateMaxCombination(Player c1, TableCard c2){
    double max = 0;
    string highColor;
    for(auto it1 = c1.begin(); it1 != c1.end(); it1++){
        if(it1->first >= max){
            max = it1->first;
            highColor = it1->second;
        }
    }
    double num = max * 0.1;
    double color = this->getValueFromColor(highColor) * 0.03;
    this->setValue(num + color);
    this->setHighestColor(highColor);
}
string HighCard::getHighestColor(string c1, string c2) const{
    return this->highestColor;
}
void HighCard::setHighestColor(string s){
    this->highestColor = s;
}
double HighCard::getValueFromColor(string color) const{
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