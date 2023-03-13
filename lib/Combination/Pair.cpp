#include "Pair.hpp"

// Create findMaxCombination and isPair Method
// update calculateMaxCombination using above methods

// ctor by input
Pair::Pair(Player c1, TableCard c2) : HighCard(c1,c2){
    this->calculateMaxCombination(c1,c2);
}
// cctor
Pair::Pair(const Pair& C) : HighCard(C){
    this->highestColor = C.highestColor;
}
// dtor
Pair::~Pair(){}

// set value of a combo
void Pair::setValue(double val){
    this->totalValue = val;
}
// get value of a combo
double Pair::getValue(Player c1, TableCard c2) const{
    return this->totalValue;
}
// calculate max value of a combo
void Pair::calculateMaxCombination(Player c1, TableCard c2){
    double max = 0;
    string highColor;
    for(auto it1 = c1.begin(); it1 != c1.end(); it1++){
        for(auto it2 = c2.begin(); it2 != c2.end(); it2++){
            if(it1->first == it2->first){
                max = it1->first;
                highColor = this->getHighestColor(it1->second, it2->second);
            }
        } 
    }
    double num = max * 0.1;
    double color = this->getValueFromColor(highColor) * 0.03;
    this->setValue(num + color);
    this->setHighestColor(highColor);
}
string Pair::getHighestColor(string c1, string c2) const{
    return this->highestColor;
}
void Pair::setHighestColor(string s){
    this->highestColor = s;
}
void Pair::findHighestColor(vector<string> c1, vector<string> c2){
    // string highColor;
    // if (c1 == "merah" || c2 == "merah"){
    //     highColor = c1;
    // } else if (c1 == "kuning" || c2 == "kuning"){
    //     highColor == c1;
    // } else if (c1 == "biru" || c2 == "biru"){
    //     highColor = c1;
    // } else if (c1 == "hijau" || c2 == "hijau"){
    //     highColor = c1;
    // }
    // return highColor;
}
double Pair::getValueFromColor(string color) const{
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