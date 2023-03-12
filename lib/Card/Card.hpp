#ifndef CARD_HPP
#define CARD_HPP

#include <string>
using namespace std;

class Card{
    private:
        int number;
        string color;
    public:
        Card();
        Card(int, string);
        Card(const Card&);
        int getNumber();
        string getColor();
        double getValue();
};

#endif