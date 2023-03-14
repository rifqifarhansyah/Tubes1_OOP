#include "MainDeck.hpp"
#include <iostream>
#include <random>
using namespace std;

MainDeck::MainDeck(): InventoryHolder(0,52){
    for (int i = 1;i <= 13;i++){
        Card c(i,string("merah"));
        insertLast(c);
    }
    for (int i = 1;i <= 13;i++){
        Card c(i,string("kuning"));
        insertLast(c);
    }
    for (int i = 1;i <= 13;i++){
        Card c(i,string("hijau"));
        insertLast(c);
    }
    for (int i = 1;i <= 13;i++){
        Card c(i,string("biru"));
        insertLast(c);
    }
}

MainDeck::MainDeck(vector<Card> cards) : InventoryHolder(cards.size(),52){
    for (int i = 0;i < cards.size();i++){
        setItem(i,cards[i]);
    }
}
MainDeck::MainDeck(const MainDeck& otherDeck) : InventoryHolder(otherDeck.getSize(),52){
    for (int i = 0;i < otherDeck.getSize();i++){
        setItem(i,otherDeck.getItem(i));
    }
}

MainDeck& MainDeck::operator=(const MainDeck& otherDeck){
    for (int i = 0;i < otherDeck.getSize();i++){
        setItem(i,otherDeck.getItem(i));
    }
    inventory.resize(otherDeck.getSize());
    return *this;
}

Card MainDeck::deal(){
    Card dealed = getItemLast();
    deleteLast();
    return dealed;
}

Card MainDeck::peek() const {
    return getItemLast();
}

void MainDeck::addCard(const Card& card){
    insertLast(card);
}

void MainDeck::shuffle(){
    for (int i = 0;i < getSize();i++){
        int randIdx = rand()%(getSize()-i)+i;
        swap(inventory[i],inventory[randIdx]);
    }
}
void MainDeck::print(){
    cout << "Dek saat ini : " << endl;
    for (int i = getSize()-1;i >= 0;i--){
        cout << getSize()-i << ". ";
        getItem(i).print();
        cout << endl;
    }
}
MainDeck& MainDeck::operator+(const Card& card){
    addCard(card);
    return *this;
}
MainDeck& MainDeck::operator-(Player& player){
    player.addCard(getItemLast());
    deleteLast();
    return *this;
}

MainDeck& MainDeck::operator-(TableCard& table){
    table.draw(getItemLast());
    deleteLast();
    return *this;
}
