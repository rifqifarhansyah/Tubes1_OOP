#ifndef INVENTORYHOLDERINT_HPP
#define INVENTORYHOLDERINT_HPP

#include "../InventoryHolder.hpp"

class InventoryHolderInt : public InventoryHolder<int> {
    public:
        // Default ctor
        InventoryHolderInt() : InventoryHolder() {}

        // Ctor inventory ukuran n dengan isi default ctor T, tanpa batas maksimal
        InventoryHolderInt(int n) : InventoryHolder(n) {}

        // Ctor inventory ukuran n dengan isi default ctor T, dengan batas maksimal
        InventoryHolderInt(int n, int maxSize) : InventoryHolder(n, maxSize) {}

        // CCtor
        InventoryHolderInt(const InventoryHolderInt& I) : InventoryHolder(I) {}

        // Override method print() dari kelas base InventoryHolder
        void print() {
            if (isEmpty()) {
                std::cout << "Inventory kosong.\n";
                return;
            }

            std::cout << "Inventory berisi " << getSize() << " item:\n";
            for (int i = 0; i < getSize(); i++) {
                std::cout << "[" << i << "]: " << getItem(i) << "\n";
            }
        }
};

#endif
