#include "inputExceptionInterface.hpp"

int InputException::numOfInputException = 0;

string InputException::errorMessage[] = {
    "Error: Input tidak valid.",
};

InputException::InputException(int ID) : Exception(ID) { // user-defined ctor
    numOfInputException++;
}

InputException::InputException(const InputException& IE) : Exception(IE) { // cctor
    numOfInputException++;
}

int InputException::getNumOfInputException() { // numOfInputException getter
    return numOfInputException;
}

void InputException::displayMessage() const { // message display
    cout << errorMessage[this->Exception::ID] << endl;
}

// Path: Tubes1_OOP\lib\Exception\inputException.cpp
// Compare this snippet from Tubes1_OOP\lib\Exception\exception.cpp: