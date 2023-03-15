#include "ThreeOfAKind.hpp"

// ctor by input
ThreeOfAKind::ThreeOfAKind(Player c1, TableCard c2) : TwoPair(c1,c2){
    // this->maxThreeOfAKind = 5.56;
    this->calculateMaxCombination(c1,c2);
}
// cctor
ThreeOfAKind::ThreeOfAKind(const ThreeOfAKind& C) : TwoPair(C){
    this->highestColor = C.getHighestColor();
}
// dtor
ThreeOfAKind::~ThreeOfAKind(){}

// calculate max value of a combo
void ThreeOfAKind::calculateMaxCombination(Player c1, TableCard c2){
    vector<Card> vec;
    vec = findMaxCombination(c1, c2);
    if(vec.empty()){
        this->TwoPair::calculateMaxCombination(c1,c2);
    }else{
        double num = findHighestNumber(vec);
        double color = findHighestColor(vec);
        this->setHighestNumber(num);
        this->setHighestColor(Card::getColorFromValue(color));
        this->setValue(num + color + TWO_PAIR);
    }
}
vector<Card> ThreeOfAKind::findMaxCombination(Player c1, TableCard c2){
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

    vector<Card> ThreeOfAKind;
    int count = 0;
    for (int i = allCards.size() - 1; i >= 2; i--) {
        if (allCards[i].getNumber() == allCards[i - 1].getNumber() && allCards[i-1].getNumber() == allCards[i-2].getNumber()) {
            ThreeOfAKind.push_back(allCards[i]);
            ThreeOfAKind.push_back(allCards[i-1]);
            ThreeOfAKind.push_back(allCards[i-2]);
            break;
        }
    }
    if (ThreeOfAKind.size() < 3) {
        ThreeOfAKind.clear();
    }
    return ThreeOfAKind;
}
// // set value of a combo
// void ThreeOfAKind::setValue(double val){
//     this->totalValue = val;
// }
// // get value of a combo
// double ThreeOfAKind::getValue(Player c1, TableCard c2) const{
//     return this->totalValue;
// }
// void ThreeOfAKind::setHighestNumber(double val){
//     this->highestNumber = val;
// }
// double ThreeOfAKind::getHighestNumber() const{
//     return this->highestNumber;
// }
// void ThreeOfAKind::setHighestColor(string s){
//     this->highestColor = s;
// }
// string ThreeOfAKind::getHighestColor() const{
//     return this->highestColor;
// }

// double ThreeOfAKind::findHighestColor(vector<Card> c1){
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
// double ThreeOfAKind::getValueFromColor(string color) const{
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
// string ThreeOfAKind::Card::getColorFromValue(double result) const{
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
