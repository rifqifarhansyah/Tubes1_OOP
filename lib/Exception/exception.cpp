#include "exceptionInterface.hpp"

int Exception::numOfException = 0;

Exception::Exception(int ID) : ID(ID) { // user-defined ctor
    numOfException++;
}

Exception::Exception(const Exception& E) : ID(E.ID) { // cctor
    numOfException++;
}

int Exception::getNumOfException() { // numOfException getter
    return numOfException;
}

int Exception::getID() const { // ID getter
    return ID;
}

// Path: Tubes1_OOP\lib\Exception\exception.cpp
// Compare this snippet from Tubes1_OOP\lib\Exception\exceptionInterface.hpp: