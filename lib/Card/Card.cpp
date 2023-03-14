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