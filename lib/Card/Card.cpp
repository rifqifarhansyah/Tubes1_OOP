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
    if(s == "merah"){
        val = 3;
    } else if(s == "kuning"){
        val = 2;
    } else if(s == "biru"){
        val = 1;
    } else if(s == "hijau"){
        val = 0;
    }
    return val * constant;
}
string Card::getColorFromValue(double result){
    string color;
    if(result == 0.09){
        color == "merah";
    } else if(result == 0.06){
        color == "kuning";
    } else if(result == 0.03){
        color == "biru";
    } else if(result == 0){
        color == "hijau";
    }
    return color;
}
double Card::getValue() { 
    double value = this->number / 10 ;   
    if (this->color == "hijau") {
        return value  ;
    }
    else if (this->color == "biru") {
        return value + 0.03 ;
    }
    else if (this->color == "kuning") {
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