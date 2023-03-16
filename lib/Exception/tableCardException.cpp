#include "tableCardExceptionInterface.hpp"

#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define YELLOW "\033[1m\033[33m"
#define BLUE "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN "\033[1m\033[36m"
#define RESET "\033[0m"

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
    cout << RED << errorMessage[this->Exception::ID] << RESET << endl;
}

// Path: Tubes1_OOP\lib\Exception\tableCardException.cpp
// Compare this snippet from Tubes1_OOP\lib\Exception\inputException.cpp: