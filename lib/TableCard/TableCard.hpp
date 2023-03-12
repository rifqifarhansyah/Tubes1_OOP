// TableCard.hpp

#ifndef TABLECARD_HPP
#define TABLECARD_HPP

#include "../Card/Card.hpp"
#include "../AbstractClasses/InventoryHolder.hpp"

class TableCard {
    private:
        Card* t_cards;
        int t_count;
        const int t_max = 5;
    public:
        // constructor, copy constructor, destructor
        TableCard(); // default ctor
        TableCard(int, Card*); // user-defined ctor
        TableCard(const TableCard&); // cctor
        ~TableCard(); // dtor

        // setter, getter
        void setTCards(int, Card); // mengubah 1 kartu sesuai indeks pada TableCard
        void setTCards(Card*); // mengubah semua kartu TableCard
        void setTCount(int); // mengubah jumlah kartu TableCard
        Card getTCards(int); // mendapat 1 kartu sesuai indeks pada TableCard
        Card* getTCards(); // mendapat semua kartu TableCard
        int getTCount(); // mendapat jumlah kartu TableCard

        // other
        void addTCards(Card); // menambahkan 1 kartu pada TableCard
        void addTCards(Card*); // menambah semua kartu TableCard
        void removeTCards(); // menghapus 1 kartu pada TableCard
        void clearTCards(); // menghapus semua kartu TableCard
        void showTCards(); // menampilkan semua kartu TableCard
};

#endif