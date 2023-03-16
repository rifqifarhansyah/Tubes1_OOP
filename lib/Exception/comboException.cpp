#include "comboExceptionInterface.hpp"

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