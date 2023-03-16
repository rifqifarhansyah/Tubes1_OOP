// TableCard.cpp

#include "TableCard.hpp"
#include <iostream>
using namespace std;

// constructor, copy constructor, destructor

// default ctor
TableCard::TableCard() : InventoryHolder<Card>(0,5) {
    // cout << "TableCard default ctor" << endl;
}

// user-defined ctor
TableCard::TableCard(std::vector<Card> cards) : InventoryHolder<Card>(cards.size(), 5) {
    setCards(cards);
    // cout << "TableCard user-defined ctor" << endl;
}

// cctor
TableCard::TableCard(const TableCard& copy) : InventoryHolder<Card>(copy) {
    setCards(copy.inventory);
    // cout << "TableCard cctor" << endl;
}

// dtor
TableCard::~TableCard() {
    // cout << "TableCard dtor" << endl;
}

// setter, getter
// mengubah semua kartu TableCard
void TableCard::setCards(std::vector<Card> cards) {
    for (int i = 0; i < cards.size(); i++) {
        try {
            setItem(i, cards[i]);
        } catch (InventoryException(error)) {
            error.displayMessage();
        }
    }
}
// mendapat semua kartu TableCard
std::vector<Card> TableCard::getCards() {
    return inventory;
}

// operation, output
// menambah 1 kartu pada indeks terakhir
void TableCard::draw(Card card) {
    try {
        insertLast(card);
    } catch (InventoryException(error)) {
        error.displayMessage();
    }
}
// menghapus 1 kartu sesuai indeks
void TableCard::remove() {
    try {
        deleteLast();
    } catch (InventoryException(error)) {
        error.displayMessage();
    }
}
// menghapus semua kartu TableCard
void TableCard::clear() {
    InventoryHolder::clear();
}
// menampilkan semua kartu TableCard
void TableCard::print() {
    try {
        if (!isEmpty()) {
            cout << "Kartu TableCard:" << endl;
            for (int i = 0; i < getSize(); i++) {
                cout << i+1 << ". Kartu " << inventory[i] << endl;
            }
        } else {
            throw InventoryException(3);
        }
    } catch (InventoryException(error)) {
        error.displayMessage();
    }
}