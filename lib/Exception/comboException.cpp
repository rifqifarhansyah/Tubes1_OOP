#include "comboExceptionInterface.hpp"

#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define YELLOW "\033[1m\033[33m"
#define BLUE "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN "\033[1m\033[36m"
#define RESET "\033[0m"

int ComboException::numOfComboException = 0;

string ComboException::errorMessage[] = {
    "Error: Combo tidak ditemukan.",
    "Error: Combo sudah ada.",
};

ComboException::ComboException(int ID, string message) : Exception(ID) { // user-defined ctor
    numOfComboException++;
}

ComboException::ComboException(const ComboException& CE) : Exception(CE) { // cctor
    numOfComboException++;
}

int ComboException::getNumOfComboException() { // numOfComboException getter
    return numOfComboException;
}

void ComboException::displayMessage() const { // message display
    cout << errorMessage[this->Exception::ID] << endl;
}

// Path: Tubes1_OOP\lib\Exception\comboException.cpp
// Compare this snippet from Tubes1_OOP\lib\Exception\comboExceptionInterface.hpp: