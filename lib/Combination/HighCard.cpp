#include "HighCard.hpp"

// ctor by input
HighCard::HighCard(Player c1, TableCard c2) : Combination(c1,c2){
    this->highestColor = "Hijau";
    this->highestNumber = 0;
    this->calculateMaxCombination(c1,c2);
}
// cctor
HighCard::HighCard(const HighCard& C) : Combination(C){
    this->highestColor = C.highestColor;
}
// dtor
HighCard::~HighCard(){}

// calculate max value of a combo
void HighCard::calculateMaxCombination(Player c1, TableCard c2){
    vector<Card> vec;
    vec = findMaxCombination(c1, c2);
    
    double num = vec[0].getNumber() * 0.1;
    double color = this->getValueFromColor(vec[0].getColor()) * 0.03;
    this->setHighestNumber(vec[0].getNumber());
    this->setHighestColor(vec[0].getColor());
    this->setValue(num + color);
    
}
vector<Card> HighCard::findMaxCombination(Player c1, TableCard c2){
    vector<Card> kartu1(2);
    for (int i = kartu1.size() - 1; i >= 0; i--)
    {
        kartu1.push_back(c1.getItem(i));
    }
    if(kartu1[0].getNumber() > kartu1[1].getNumber())
    {
        kartu1.pop_back();
    }
    else
    {
        kartu1.erase(kartu1.begin());
    }

    return kartu1;
}
// set value of a combo
void HighCard::setValue(double val){
    this->totalValue = val;
}
// get value of a combo
double HighCard::getValue(Player c1, TableCard c2) const{
    return this->totalValue;
}

void HighCard::setHighestNumber(double val){
    this->highestNumber = val;
}
double HighCard::getHighestNumber() const{
    return this->highestNumber;
}
void HighCard::setHighestColor(string s){
    this->highestColor = s;
}
string HighCard::getHighestColor() const{
    return this->highestColor;
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