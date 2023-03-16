#include "cardExceptionInterface.hpp"

#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define YELLOW "\033[1m\033[33m"
#define BLUE "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN "\033[1m\033[36m"
#define RESET "\033[0m"

int CardException::numOfCardException = 0;

CardException::CardException(int ID) : Exception(ID) { // user-defined ctor
    numOfCardException++;
}

CardException::CardException(const CardException& CE) : Exception(CE) { // cctor
    numOfCardException++;
}

int CardException::getNumOfCardException() { // numOfCardException getter
    return numOfCardException;
}

// Path: Tubes1_OOP\lib\Exception\cardException.cpp
// Compare this snippet from Tubes1_OOP\lib\Exception\cardExceptionInterface.hpp: