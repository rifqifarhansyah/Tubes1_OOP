// TableCard.cpp

#include "TableCard.hpp"
#include <iostream>
using namespace std;

// constructor, copy constructor, destructor

// default ctor
TableCard::TableCard() : InventoryHolder<Card>(0,5) {
    t_count = 0;
    cout << "TableCard default ctor" << endl;
}

// user-defined ctor
TableCard::TableCard(std::vector<Card> cards) : InventoryHolder<Card>(cards.size(), 5) {
    t_count = cards.size();
    for (int i = 0; i < t_count; i++) {
        inventory[i] = cards[i];
    }
    cout << "TableCard user-defined ctor" << endl;
}

// cctor
TableCard::TableCard(const TableCard& copy) : InventoryHolder<Card>(copy) {
    t_count = copy.t_count;
    for (int i = 0; i < t_count; i++) {
        inventory[i] = copy.inventory[i];
    }
    cout << "TableCard cctor" << endl;
}

// dtor
TableCard::~TableCard() {
    cout << "TableCard dtor" << endl;
}

// setter, getter

// mengubah 1 kartu sesuai indeks pada TableCard
void TableCard::setTCards(int idx, Card card) {
    setItem(idx, card);
}
// mengubah semua kartu TableCard
void TableCard::setTCards(std::vector<Card> cards) {
    for (int idx = 0; idx < cards.size(); idx++) {
        setItem(idx, cards[idx]);
    }
}
// mengubah jumlah kartu TableCard
void TableCard::setTCount(int n) {
    t_count = n;
}
// mendapat 1 kartu sesuai indeks pada TableCard
Card TableCard::getTCards(int idx) {
    return getItem(idx);
}
// mendapat semua kartu TableCard
std::vector<Card> TableCard::getTCards() {
    return inventory;
}
// mendapat jumlah kartu TableCard
int TableCard::getTCount() {
    return t_count;
}

// other

// menambahkan 1 kartu pada TableCard
void TableCard::addTCards(Card card) {
    insertLast(card);
    t_count++;
}
// menambah semua kartu TableCard
void TableCard::addTCards(std::vector<Card> cards) {
    for (int idx = 0; idx < cards.size(); idx++) {
        setItem(idx, cards[idx]);
    }
    t_count += cards.size();
}
// menghapus 1 kartu pada TableCard
void TableCard::removeTCards() {
    t_count--;
}
// menghapus semua kartu TableCard
void TableCard::clearTCards() {
    t_count = 0;
}
// menampilkan semua kartu TableCard
void TableCard::print() {
    cout << "Isi TableCard:" << endl;
    for (int i = 0; i < getSize(); i++) {
        cout << i+1 << ". Kartu " << "{PLACEHOLDER}" << endl;
    }
}