#include "playerCardExceptionInterface.hpp"

int PlayerCardException::numOfPlayerCardException = 0;

string PlayerCardException::errorMessage[] = {
    "Error: Kartu tidak ditemukan.",
    "Error: Kartu sudah ada.",
};

PlayerCardException::PlayerCardException(int ID) : CardException(ID) { // user-defined ctor
    numOfPlayerCardException++;
}

PlayerCardException::PlayerCardException(const PlayerCardException& PCE) : CardException(PCE) { // cctor
    numOfPlayerCardException++;
}

int PlayerCardException::getNumOfPlayerCardException() { // numOfPlayerCardException getter
    return numOfPlayerCardException;
}

void PlayerCardException::displayMessage() const { // message display
    cout << errorMessage[this->Exception::ID] << endl;
}

// Path: Tubes1_OOP\lib\Exception\playerCard.cpp
// Compare this snippet from Tubes1_OOP\lib\Exception\cardException.cpp: