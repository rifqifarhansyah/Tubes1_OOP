#include <iostream>
#include "InventoryHolderInt.hpp"

// main function
int main()
{
    try {
        // create an inventory holder of integers with maximum size of 5
        InventoryHolderInt myInventory(0);

        // delete first isEmpty exception test
        myInventory.deleteFirst();

        // insert some elements to the inventory
        myInventory.insertLast(10);
        myInventory.insertLast(20);
        myInventory.insertLast(30);

        // print the inventory
        myInventory.print();

        // delete an element from the inventory
        myInventory.deleteFirst();

        // print the inventory again
        myInventory.print();

        // insert an element at index 1
        myInventory.insertAt(1, 25);

        // print the inventory again
        myInventory.print();

        // set an element at index 2
        myInventory.setItem(2, 35);

        // print the inventory again
        myInventory.print();

        // create a copy of the inventory
        InventoryHolderInt myCopy(myInventory);

        // print the copy of the inventory
        myCopy.print();
    } catch (InventoryException &e) {
        e.displayMessage();
    }
    return 0;
}

// perintah untuk coba run : g++ InventoryHolderTest.cpp InventoryHolderInt.hpp ../../Exception/inventoryException.cpp ../../Exception/exception.cpp -o main
