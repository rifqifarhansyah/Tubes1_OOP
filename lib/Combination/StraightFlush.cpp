#include "StraightFlush.hpp"

// ctor by input
StraightFlush::StraightFlush(Player c1, TableCard c2) : FourOfAKind(c1,c2){
    this->maxStraightFlush = 1.39 * 9;
    this->calculateMaxCombination(c1,c2);
}
// cctor
StraightFlush::StraightFlush(const StraightFlush& C) : FourOfAKind(C){
    this->highestColor = C.getHighestColor();
}
// dtor
StraightFlush::~StraightFlush(){}

// calculate max value of a combo
void StraightFlush::calculateMaxCombination(Player c1, TableCard c2){
    vector<Card> vec;
    vec = findMaxCombination(c1, c2);
    if(vec.empty()){
        this->FourOfAKind::calculateMaxCombination(c1,c2);
    }else{
        double num = vec[0].getNumber() * 0.1;
        double color = findHighestColor(vec);
        this->setHighestNumber(vec[0].getNumber());
        this->setHighestColor(getColorFromValue(color));
        this->setValue(num + color + this->maxFourOfAKind);
    }
}
vector<Card> StraightFlush::findMaxCombination(Player c1, TableCard c2){
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
    {card1.getNumber() < card2.getNumber();});

    vector<Card> straightFlush;
    for (int i = allCards.size() - 1; i >= 4; i--) {
        if (allCards[i].getColor() == allCards[i - 1].getColor() &&
            allCards[i - 1].getColor() == allCards[i - 2].getColor() &&
            allCards[i - 2].getColor() == allCards[i - 3].getColor() &&
            allCards[i - 3].getColor() == allCards[i - 4].getColor()) {
            // Found a possible straight flush starting with card i
            bool isStraightFlush = true;
            int currentNumber = allCards[i].getNumber();
            for (int j = i - 1; j >= i - 4; j--) {
                if (allCards[j].getNumber() != currentNumber - 1) {
                    isStraightFlush = false;
                    break;
                }
                currentNumber--;
            }
            if (isStraightFlush) {
                straightFlush.push_back(allCards[i]);
                straightFlush.push_back(allCards[i - 1]);
                straightFlush.push_back(allCards[i - 2]);
                straightFlush.push_back(allCards[i - 3]);
                straightFlush.push_back(allCards[i - 4]);
                break;
            }
        }
    }
    return straightFlush;
}
// // set value of a combo
// void StraightFlush::setValue(double val){
//     this->totalValue = val;
// }
// // get value of a combo
// double StraightFlush::getValue(Player c1, TableCard c2) const{
//     return this->totalValue;
// }
// void StraightFlush::setHighestNumber(double val){
//     this->highestNumber = val;
// }
// double StraightFlush::getHighestNumber() const{
//     return this->highestNumber;
// }
// void StraightFlush::setHighestColor(string s){
//     this->highestColor = s;
// }
// string StraightFlush::getHighestColor() const{
//     return this->highestColor;
// }

// double StraightFlush::findHighestColor(vector<Card> c1){
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
// double StraightFlush::getValueFromColor(string color) const{
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
// string StraightFlush::getColorFromValue(double result) const{
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
