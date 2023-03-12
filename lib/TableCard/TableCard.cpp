// TableCard.cpp

#include "TableCard.hpp"
#include <iostream>
using namespace std;

// constructor, copy constructor, destructor
TableCard::TableCard() {
    t_count = 0;
    t_cards = new Card[t_max];
    cout << "TableCard dibuat menggunakan default ctor" << endl;
} // default ctor
TableCard::TableCard(int n, Card* cards) {
    t_count = n;
    t_cards = new Card[t_max];
    for (int i = 0; i < t_count; i++) {
        t_cards[i] = cards[i];
    }
    cout << "TableCard dibuat menggunakan user-defined ctor" << endl;
} // user-defined ctor
TableCard::TableCard(const TableCard& other) {
    t_count = other.t_count;
    t_cards = new Card[t_max];
    for (int i = 0; i < t_count; i++) {
        t_cards[i] = other.t_cards[i];
    }
    cout << "TableCard disalin menggunakan cctor" << endl;
} // cctor
TableCard::~TableCard() {
    delete[] t_cards;
    cout << "TableCard dihapus menggunakan dtor" << endl;
} // dtor

// setter, getter
void TableCard::setTCards(Card* cards) {
    for (int i = 0; i < t_count; i++) {
        t_cards[i] = cards[i];
    }
} // mengubah semua kartu TableCard
void TableCard::setTCards(int idx, Card card) {
    t_cards[idx] = card;
} // mengubah 1 kartu sesuai indeks pada TableCard
void TableCard::setTCount(int n) {
    t_count = n;
} // mengubah jumlah kartu TableCard
Card TableCard::getTCards(int idx) {
    return t_cards[idx];
} // mendapat 1 kartu sesuai indeks pada TableCard
Card* TableCard::getTCards() {
    return t_cards;
} // mendapat semua kartu TableCard
int TableCard::getTCount() {
    return t_count;
} // mendapat jumlah kartu TableCard

// other
void TableCard::addTCards(Card card) {
    t_cards[t_count] = card;
    t_count++;
} // menambahkan 1 kartu pada TableCard
void TableCard::addTCards(Card* cards) {
    for (int i = 0; i < sizeof(cards); i++) {
        t_cards[i+t_count] = cards[i];
    }
    t_count += sizeof(cards);
} // menambah semua kartu TableCard
void TableCard::removeTCards() {
    TableCard temp(t_count, t_cards);
    delete[] t_cards;
    t_count--;
    t_cards = new Card[t_max];
    for (int i = 0; i < t_count; i++) {
        t_cards[i] = temp.t_cards[i];
    }
    delete[] temp.t_cards;
} // menghapus 1 kartu pada TableCard
void TableCard::clearTCards() {
    delete[] t_cards;
    t_count = 0;
    t_cards = new Card[t_max];
} // menghapus semua kartu TableCard
void TableCard::showTCards() {
    cout << "Isi TableCard:" << endl;
    for (int i = 0; i < t_count; i++) {
        cout << i+1 << ". Kartu " << "{PLACEHOLDER}" << endl;
    }
} // menampilkan semua kartu TableCard