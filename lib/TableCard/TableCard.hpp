// TableCard.hpp

#ifndef TABLECARD_HPP
#define TABLECARD_HPP

#include "../Card/Card.hpp"
#include "../AbstractClasses/InventoryHolder.hpp"
#include "../Exception/inventoryExceptionInterface.hpp"
#include "../Exception/tableCardExceptionInterface.hpp"

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

        // operation, output
        void draw(Card); // menambah 1 kartu pada indeks terakhir
        void remove(); // menghapus 1 kartu pada indeks terakhir
        void clear(); // menghapus semua kartu TableCard
        void print(); // menampilkan semua kartu TableCard
};

#endif