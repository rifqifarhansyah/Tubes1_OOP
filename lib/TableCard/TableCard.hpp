// TableCard.hpp

#ifndef TABLECARD_HPP
#define TABLECARD_HPP

#include "../Card/Card.hpp"
#include "../AbstractClasses/InventoryHolder.hpp"

class TableCard : public InventoryHolder<Card> {
    private:
        int t_count;
    public:
        // constructor, copy constructor, destructor
        TableCard(); // default ctor
        TableCard(std::vector<Card>); // user-defined ctor
        TableCard(const TableCard&); // cctor
        ~TableCard(); // dtor

        // setter, getter
        void setTCards(int, Card); // mengubah 1 kartu sesuai indeks pada TableCard
        void setTCards(std::vector<Card>); // mengubah semua kartu TableCard
        void setTCount(int); // mengubah jumlah kartu TableCard
        Card getTCards(int); // mendapat 1 kartu sesuai indeks pada TableCard
        std::vector<Card> getTCards(); // mendapat semua kartu TableCard
        int getTCount(); // mendapat jumlah kartu TableCard

        // other
        void addTCards(Card); // menambahkan 1 kartu pada TableCard
        void addTCards(std::vector<Card>); // menambah semua kartu TableCard
        void removeTCards(); // menghapus 1 kartu pada TableCard
        void clearTCards(); // menghapus semua kartu TableCard
        void print(); // menampilkan semua kartu TableCard
};

#endif