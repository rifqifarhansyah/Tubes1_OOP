#include "inventoryExceptionInterface.hpp"

#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define YELLOW "\033[1m\033[33m"
#define BLUE "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN "\033[1m\033[36m"
#define RESET "\033[0m"

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
    cout << RED << errorMessage[this->Exception::ID] << RESET << endl;
}

// Path: Tubes1_OOP\lib\Exception\inventoryException.cpp
// Compare this snippet from Tubes1_OOP\lib\Exception\inventoryExceptionInterface.hpp: