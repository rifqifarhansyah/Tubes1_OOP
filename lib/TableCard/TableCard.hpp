// TableCard.hpp

#ifndef TABLECARD_HPP
#define TABLECARD_HPP

#include "../Card/Card.hpp"
#include "../AbstractClasses/InventoryHolder.hpp"

class TableCard : public InventoryHolder<Card> {
    private:
    public:
        // constructor, copy constructor, destructor
        TableCard(); // default ctor
        TableCard(std::vector<Card>); // user-defined ctor
        TableCard(const TableCard&); // cctor
        ~TableCard(); // dtor

        // setter, getter
        void setCards(std::vector<Card>); // mengubah semua kartu TableCard
        std::vector<Card> getCards(); // mendapat semua kartu TableCard
        int getSize(); // mendapat ukuran inventory

        // operation, output
        void draw(Card); // menambah 1 kartu pada indeks terakhir
        void remove(); // menghapus 1 kartu pada indeks terakhir
        void print(); // menampilkan semua kartu TableCard
};

#endif