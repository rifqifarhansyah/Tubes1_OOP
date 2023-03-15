#include "Straight.hpp"

// ctor by input
Straight::Straight(Player c1, TableCard c2) : ThreeOfAKind(c1,c2){
    // this->maxStraight = 6.95;
    this->calculateMaxCombination(c1,c2);
}
// cctor
Straight::Straight(const Straight& C) : ThreeOfAKind(C){
    this->highestColor = C.getHighestColor();
}
// dtor
Straight::~Straight(){}

// calculate max value of a combo
void Straight::calculateMaxCombination(Player c1, TableCard c2){
    vector<Card> vec;
    vec = findMaxCombination(c1, c2);
    if(vec.empty()){
        this->ThreeOfAKind::calculateMaxCombination(c1,c2);
    }else{
        double num = findHighestNumber(vec);
        double color = findHighestColor(vec);
        this->setHighestNumber(num);
        this->setHighestColor(getColorFromValue(color));
        this->setValue(num + color + THREE_OF_A_KIND);
    }
}
vector<Card> Straight::findMaxCombination(Player c1, TableCard c2){
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

    vector<Card> straight;
    int count = 1;
    for (int i = allCards.size() - 1; i > 0; i--) {
        if (allCards[i].getNumber() - allCards[i - 1].getNumber() == 1) {
            count++;
            if (count == 5) {
                straight.push_back(allCards[i - 3]);
                straight.push_back(allCards[i - 2]);
                straight.push_back(allCards[i - 1]);
                straight.push_back(allCards[i]);
                straight.push_back(allCards[i - count]);
                break;
            }
        } else if (allCards[i].getNumber() != allCards[i - 1].getNumber()) {
            count = 1;
        }
    }
    return straight;
}

// // set value of a combo
// void Straight::setValue(double val){
//     this->totalValue = val;
// }
// // get value of a combo
// double Straight::getValue(Player c1, TableCard c2) const{
//     return this->totalValue;
// }
// void Straight::setHighestNumber(double val){
//     this->highestNumber = val;
// }
// double Straight::getHighestNumber() const{
//     return this->highestNumber;
// }
// void Straight::setHighestColor(string s){
//     this->highestColor = s;
// }
// string Straight::getHighestColor() const{
//     return this->highestColor;
// }

// double Straight::findHighestColor(vector<Card> c1){
//     double max = 0;
//     for (int i = 0; i < c1.size(); i++)
//     {
//         if (c1[i].getColor() == "merah" && max < 3){
//             max = this->getValueFromColor(c1[i].getColor());
//         } else if (c1[i].getColor() == "kuning" && max <= 2){
//             max == this->getValueFromColor(c1[i].getColor());
//         } else if (c1[i].getColor() == "biru" && max <= 1){
//             max = this->getValueFromColor(c1[i].getColor());
//         } else if (c1[i].getColor() == "hijau" && max == 0){
//             max = this->getValueFromColor(c1[i].getColor());
//         }
//     }

//     return max;
// }
// double Straight::getValueFromColor(string color) const{
//     if(color == "merah"){
//         return 3;
//     } else if(color == "kuning"){
//         return 2;
//     } else if(color == "biru"){
//         return 1;
//     } else if(color == "hijau"){
//         return 0;
//     }
// }
// string Straight::getColorFromValue(double result) const{
//     string color;
//     if(result == 3){
//         color == "merah";
//     } else if(result == 2){
//         color == "kuning";
//     } else if(result == 1){
//         color == "biru";
//     } else if(result == 0){
//         color == "hijau";
//     }
//     return color;
// }
