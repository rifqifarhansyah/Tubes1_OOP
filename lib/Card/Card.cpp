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
int Card::getNumber() { 
    return this->number ; 
}
string Card::getColor() {
    return this->color ; 
}
double Card::getValue() { 
    double value = this->number / 10 ;   
    if (this->color == "Hijau") {
        return value  ;
    }
    if (this->color == "Biru") {
        return value + 0.03 ;
    }
    if (this->color == "Kuning") {
        return value + 0.06 ;
    }
    if (this->color == "Merah") {
        return value + 0.09 ;
    }


}