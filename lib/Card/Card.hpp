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
        int getNumber() const;
        string getColor() const;
        double getValueFromColor(string s) const;
        string getColorFromValue(double result) const;
        double getValue();
        void print();
        friend ostream& operator<<(ostream& out, const Card&);
        friend bool operator< (Card& c1, Card&c2);
        friend bool operator> (Card& c1, Card&c2);

        
};

#endif