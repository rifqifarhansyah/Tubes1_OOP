#include "inventoryExceptionInterface.hpp"

int InventoryException::numOfInventoryException = 0;

string InventoryException::errorMessage[] = {
    "Error: Ukuran maksimum inventory telah terlampaui.",
    "Error: Index yang dimasukkan diluar batas.",
    "Error: Inventory Telah penuh.",
    "Error: Inventory masih kosong.",
};

InventoryException::InventoryException(int ID) : Exception(ID) { // user-defined ctor
    numOfInventoryException++;
}

InventoryException::InventoryException(const InventoryException& IE) : Exception(IE) { // cctor
    numOfInventoryException++;
}

int InventoryException::getNumOfInventoryException() { // numOfInventoryException getter
    return numOfInventoryException;
}

void InventoryException::displayMessage() const { // message display
    cout << errorMessage[this->Exception::ID] << endl;
}

// Path: Tubes1_OOP\lib\Exception\inventoryException.cpp
// Compare this snippet from Tubes1_OOP\lib\Exception\inventoryExceptionInterface.hpp: