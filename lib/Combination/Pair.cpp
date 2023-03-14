#include "Pair.hpp"

// ctor by input
Pair::Pair(Player c1, TableCard c2) : HighCard(c1,c2){
    this->maxPair = 2.78;
    this->calculateMaxCombination(c1,c2);
}
// cctor
Pair::Pair(const Pair& C) : HighCard(C){
    this->highestColor = C.highestColor;
}
// dtor
Pair::~Pair(){}

// calculate max value of a combo
void Pair::calculateMaxCombination(Player c1, TableCard c2){
    vector<Card> vec;
    vec = findMaxCombination(c1, c2);
    
    if(vec.empty()){
        this->HighCard::calculateMaxCombination(c1,c2);
    }else{
        double num = vec[0].getNumber() * 0.1;
        double color = findHighestColor(vec);
        this->setHighestNumber(vec[0].getNumber());
        this->setHighestColor(getColorFromValue(color));
        this->setValue(num + color + this->maxPair);
    }
}
vector<Card> Pair::findMaxCombination(Player c1, TableCard c2){
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

    vector<Card> pair;
    for (int i = allCards.size() - 1; i >= 1; i--) {
        if (allCards[i].getNumber() == allCards[i - 1].getNumber()) {
            pair.push_back(allCards[i]);
            pair.push_back(allCards[i - 1]);
            break;
        }
    }
    if(pair.size() != 2){
        pair.clear();
    }

    return pair;
}
// set value of a combo
void Pair::setValue(double val){
    this->totalValue = val;
}
// get value of a combo
double Pair::getValue(Player c1, TableCard c2) const{
    return this->totalValue;
}
void Pair::setHighestNumber(double val){
    this->highestNumber = val;
}
double Pair::getHighestNumber() const{
    return this->highestNumber;
}
void Pair::setHighestColor(string s){
    this->highestColor = s;
}
string Pair::getHighestColor() const{
    return this->highestColor;
}

double Pair::findHighestColor(vector<Card> c1){
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
string Pair::getColorFromValue(double result) const{
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
// bool Pair::isPair(Player c1, TableCard c2){
//     double max = 0;
//     string highColor;
//     bool check = false;
//     int maxcardplayer = c1.getSize();
//     int maxcardtable = c2.getSize();
//     for(int i=0;i<maxcardplayer;i++)
//     {
//         for(int j=0;j<maxcardtable;j++)
//         {
//             if((c1.getItem(i)).getNumber()==(c2.getItem(i)).getNumber())
//             {
//                 check = true;
//                 break;
//             }
//         }
//     }

//     return check;
// }