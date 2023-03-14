#ifndef MAINDECK_HPP
#define MAINDECK_HPP

#include "../AbstractClasses/InventoryHolder.hpp"
#include "../Card/Card.hpp"
#include "../Player/Player.hpp"
#include "../TableCard/TableCard.hpp"
#include <vector>
using namespace std;

class MainDeck : public InventoryHolder<Card>{
    public:
        MainDeck();
        MainDeck(vector<Card>);
        MainDeck(const MainDeck&);
        MainDeck& operator=(const MainDeck&);
        Card deal();
        Card peek() const;
        void addCard(const Card&);
        void shuffle();
        void print();
        MainDeck& operator+(const Card&);
        MainDeck& operator-(Player&);
        MainDeck& operator-(TableCard&);
};


#endif