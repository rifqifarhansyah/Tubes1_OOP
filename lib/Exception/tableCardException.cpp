#include "tableCardExceptionInterface.hpp"

int TableCardException::numOfTableCardException = 0;

string TableCardException::errorMessage[] = {
    "Error: Kartu tidak ditemukan.",
    "Error: Kartu sudah ada.",
};

TableCardException::TableCardException(int ID) : CardException(ID) { // user-defined ctor
    numOfTableCardException++;
}

TableCardException::TableCardException(const TableCardException& TCE) : CardException(TCE) { // cctor
    numOfTableCardException++;
}

int TableCardException::getNumOfTableCardException() { // numOfTableCardException getter
    return numOfTableCardException;
}

void TableCardException::displayMessage() const { // message display
    cout << errorMessage[this->Exception::ID] << endl;
}

// Path: Tubes1_OOP\lib\Exception\tableCardException.cpp
// Compare this snippet from Tubes1_OOP\lib\Exception\inputException.cpp: