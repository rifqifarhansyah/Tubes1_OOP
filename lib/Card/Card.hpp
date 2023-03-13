#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <iostream>
#include <map>
using namespace std;

class Card{
    private:
        int number;
        string color;
    public:
        Card();
        Card(int, string);
        Card(const Card&);
        Card& operator=(const Card& ) ; 
        int getNumber();
        string getColor();
        double getValue();
        void print();
        friend ostream& operator<<(ostream& out, const Card&);
        
};

#endif