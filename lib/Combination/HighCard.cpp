#include "HighCard.hpp"

// ctor by input
HighCard::HighCard(Player player, TableCard table) : Combination(player,table){
    this->highestColor = "hijau";
    this->highestNumber = 0;
    this->calculateMaxCombination();
}
// cctor
HighCard::HighCard(const HighCard& C) : Combination(C){
    this->highestColor = C.highestColor;
}
// dtor
HighCard::~HighCard(){}

// calculate max value of a combo
void HighCard::calculateMaxCombination(){
    vector<Card> vec;
    vec = findMaxCombinationAll();
    
    double num = findHighestNumber(vec) * 0.1;
    double color = findHighestColor(vec);
    this->setHighestNumber(num);
    this->setHighestColor(Card::getColorFromValue(color));
    this->setValue(num + color);
    
}
vector<Card> HighCard::findMaxCombinationAll(){
    vector<Card> kartu1;
    for (int i = 1; i >= 0; i--)
    {
        kartu1.push_back(player.getItem(i));
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
double HighCard::getValue() const{
    return this->totalValue;
}
void HighCard::setHighestNumber(double val){
    this->highestNumber = val;
}
double HighCard::getHighestNumber() const{
    return this->highestNumber;
}
double HighCard::findHighestNumber(vector<Card> c){
    double max = c[0].getNumber();
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i].getNumber() > max){
            max = c[i].getNumber();
        }
    }

    return max;
}
void HighCard::setHighestColor(string s){
    this->highestColor = s;
}
string HighCard::getHighestColor() const{
    return this->highestColor;
}

double HighCard::findHighestColor(vector<Card> c){
    double max = 0;
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i].getColor() == "merah" && max <= 0.09){
            max = Card::getValueFromColor(c[i].getColor());
        } else if (c[i].getColor() == "kuning" && max <= 0.06){
            max = Card::getValueFromColor(c[i].getColor());
        } else if (c[i].getColor() == "biru" && max <= 0.03){
            max = Card::getValueFromColor(c[i].getColor());
        } else if (c[i].getColor() == "hijau" && max == 0){
            max = Card::getValueFromColor(c[i].getColor());
        }
    }

    return max;
}