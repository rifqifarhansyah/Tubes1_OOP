#include "cardExceptionInterface.hpp"

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