#include "PlayerExceptionInterface.hpp"

int PlayerException::numOfPlayerException = 0;

string PlayerException::errorMessage[] = {
    "Error: Kartu tidak ditemukan.",
    "Error: Kartu sudah ada.",
};

PlayerException::PlayerException(int ID) : CardException(ID) { // user-defined ctor
    numOfPlayerException++;
}

PlayerException::PlayerException(const PlayerException& PCE) : CardException(PCE) { // cctor
    numOfPlayerException++;
}

int PlayerException::getNumOfPlayerException() { // numOfPlayerException getter
    return numOfPlayerException;
}

void PlayerException::displayMessage() const { // message display
    cout << errorMessage[this->Exception::ID] << endl;
}

// Path: Tubes1_OOP\lib\Exception\Player.cpp
// Compare this snippet from Tubes1_OOP\lib\Exception\cardException.cpp: