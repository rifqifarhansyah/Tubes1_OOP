#include "inputExceptionInterface.hpp"

#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define YELLOW "\033[1m\033[33m"
#define BLUE "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN "\033[1m\033[36m"
#define RESET "\033[0m"

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
    cout << RED << errorMessage[this->Exception::ID] << RESET << endl;
}

// Path: Tubes1_OOP\lib\Exception\inputException.cpp
// Compare this snippet from Tubes1_OOP\lib\Exception\exception.cpp: