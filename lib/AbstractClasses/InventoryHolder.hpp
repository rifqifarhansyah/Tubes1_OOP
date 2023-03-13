#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP
#include <iostream>
#include <vector>

template <class T>
class InventoryHolder{
    protected:
        std::vector<T> inventory;
        int maxSize;
    public:
        // Default ctor
        InventoryHolder() : inventory(0), maxSize(){}

        // Ctor inventory ukuran n dengan isi default ctor T, tanpa batas maksimal
        InventoryHolder(int n) : inventory(n), maxSize(-1){}

        // Ctor inventory ukuran n dengan isi default ctor T, dengan batas maksimal
        InventoryHolder(int n, int maxSize) : inventory(n), maxSize(maxSize) {
            if (maxSize < n) // exception maxSize
            {

            }
        }

        // CCtor
        InventoryHolder(const InventoryHolder& I) : inventory(I.inventory), maxSize(I.maxSize){}

        // Ubah item ke i dengan a
        void setItem(int i, T a){
            if (i < 0 || i >= inventory.size()) // exception out of bounds
            {
                
            }
            inventory[i] = a;
        }

        // Mendapatkan item ke-i
        T getItem(int i) const {
            if (i < 0 || i >= inventory.size()) // exception out of bounds
            {

            }
            return inventory[i];
        }
        
        T getItemFirst() const {
            return *inventory.begin();
        }

        T getItemLast() const {
            return *inventory.rbegin();
        }

        // Mendapatkan size inventory saat ini
        int getSize() const {
            return inventory.size();
        }

        // Mendapatkan size maksimal
        int getMaxSize() const {
            return maxSize;
        }

        // Cek kosong
        bool isEmpty() const {
            return inventory.empty();
        }

        // Cek penuh
        bool isFull() const {
            return inventory.size() == maxSize;
        }

        // Insert item ke posisi pertama
        void insertFirst(T a){
            if (isFull()) //exception sudah penuh
            {

            }
            else
                inventory.insert(inventory.begin(),a);
        }

        // Insert item ke indeks ke-i [0..inventory.size()-1]
        void insertAt(int i, T a){
            if (isFull()) //exception sudah penuh 
            {

            }
            else if (i < 0 || i >= inventory.size()) // exeption out of bounds
            {

            }
            else
                inventory.insert(inventory.begin()+i,a);
        }

        void insertLast(T a){
            if (isFull()) //exception sudah penuh
            {

            }
            else
                inventory.push_back(a);
        }
        void deleteFirst(){
            if (isEmpty()) //exception kosong
            {

            }
            else
                inventory.erase(inventory.begin());
        }
        void deleteAt(int i){
            if (isEmpty()) //exception kosong
            {

            }
            else if (i < 0 || i >= inventory.size()) //exception out of bounds
            {

            }
            else
                inventory.erase(inventory.begin()+i);
        }
        void deleteLast(){
            if (isEmpty()) //exception kosong
            {

            }
            else
                inventory.pop_back();
        }

        void clear(){
            inventory.clear();
        }

        virtual void print() = 0;
};

#endif