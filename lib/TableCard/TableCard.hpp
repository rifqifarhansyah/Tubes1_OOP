// TableCard.hpp

#ifndef TABLECARD_HPP
#define TABLECARD_HPP

#include "Card.hpp"
#include "InventoryHolder.hpp"

class TableCard {
    private:
        Card* t_cards;
        int t_count;
    public:
        // constructor, copy constructor, destructor
        TableCard(); // default ctor
        TableCard(int, Card*); // user-defined ctor
        TableCard(const TableCard&); // cctor
        ~TableCard(); // dtor

        // setter, getter
        void setTCards(Card*); // set t_cards
        void setTCount(int); // set t_count
        Card* getTCards(); // get t_cards
        int getTCount(); // get t_count

        // other
        void addTCard(); // menambahkan 1 kartu pada TableCard
        void removeTCard(); // Menghapus 1 kartu pada TableCard
        void clearTCard(); // Menghapus semua kartu pada TableCard
};

#endif