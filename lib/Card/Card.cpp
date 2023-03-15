#include "Card.hpp"
#include <iostream> 

Card::Card() {
    this->number = 0 ;
    this->color = "" ;
}
Card::Card(int number,string color) { 
    this->number = number ;
    this->color = color ; 
}
Card::Card(const Card& other) { 
    this->number = other.number ;
    this->color = other.color ; 
} 
Card& Card::operator=(const Card& other) { 
    this->number = other.number ; 
    this->color = other.color ; 
    return *this ; 
}
int Card::getNumber() const{ 
    return this->number ; 
}
string Card::getColor() const {
    return this->color ; 
}
double Card::getValueFromColor(string s){
    double constant = 0.03;
    double val;
    if(s == "Merah"){
        val = 3;
    } else if(s == "Kuning"){
        val = 2;
    } else if(s == "Biru"){
        val = 1;
    } else if(s == "Hijau"){
        val = 0;
    }
    return val * constant;
}
string Card::getColorFromValue(double result){
    string color;
    if(result == 0.09){
        color == "Merah";
    } else if(result == 0.06){
        color == "Kuning";
    } else if(result == 0.03){
        color == "Biru";
    } else if(result == 0){
        color == "Hijau";
    }
    return color;
}
double Card::getValue() { 
    double value = this->number / 10 ;   
    if (this->color == "Hijau") {
        return value  ;
    }
    else if (this->color == "Biru") {
        return value + 0.03 ;
    }
    else if (this->color == "Kuning") {
        return value + 0.06 ;
    }
    else { // Merah
        return value + 0.09 ;
    }
}

ostream& operator<<(ostream& out, const Card& card){
    out << card.number << " (" << card.color << ")";
    return out;
}
bool operator<(Card& c1, Card&c2){
    if(c1.getNumber() == c2.getNumber()){
        return c1.getValueFromColor(c1.getColor()) < c2.getValueFromColor(c2.getColor());
    }else{
        return c1.getNumber() < c2.getNumber();
    }
}
bool operator>(Card& c1, Card&c2){
    if(c1.getNumber() == c2.getNumber()){
        return c1.getValueFromColor(c1.getColor()) > c2.getValueFromColor(c2.getColor());
    }else{
        return c1.getNumber() > c2.getNumber();
    }
}