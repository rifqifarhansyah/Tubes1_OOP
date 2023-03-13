// TableCard.cpp

#include "TableCard.hpp"
#include <iostream>
using namespace std;

// constructor, copy constructor, destructor

// default ctor
TableCard::TableCard() : InventoryHolder<Card>(0,5) {
    cout << "TableCard default ctor" << endl;
}

// user-defined ctor
TableCard::TableCard(std::vector<Card> cards) : InventoryHolder<Card>(cards.size(), 5) {
    setItem(cards);
    cout << "TableCard user-defined ctor" << endl;
}

// cctor
TableCard::TableCard(const TableCard& copy) : InventoryHolder<Card>(copy) {
    setItem(copy.inventory);
    cout << "TableCard cctor" << endl;
}

// dtor
TableCard::~TableCard() {
    cout << "TableCard dtor" << endl;
}

// setter, getter
// mengubah semua kartu TableCard
void TableCard::setItem(std::vector<Card> cards) {
    for (int i = 0; i < cards.size(); i++) {
        InventoryHolder::setItem(i, cards[i]);
    }
}
// mendapat semua kartu TableCard
std::vector<Card> TableCard::getItem() {
    return inventory;
}
// mendapat ukuran inventory
int TableCard::getSize() {
    return InventoryHolder::getSize();
}

// operation, output
// menambah 1 kartu pada indeks terakhir
void TableCard::draw(Card card) {
    InventoryHolder::insertLast(card);
}
// menghapus 1 kartu sesuai indeks
void TableCard::remove() {
    InventoryHolder::deleteLast();
}
// menampilkan semua kartu TableCard
void TableCard::print() {
    cout << "Kartu TableCard:" << endl;
    for (int i = 0; i < getSize(); i++) {
        cout << i+1 << ". Kartu " << inventory[i] << endl;
    }
}