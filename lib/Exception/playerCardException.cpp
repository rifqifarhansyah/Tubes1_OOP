#include "PlayerCardExceptionInterface.hpp"

#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define YELLOW "\033[1m\033[33m"
#define BLUE "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN "\033[1m\033[36m"
#define RESET "\033[0m"

int PlayerException::numOfPlayerException = 0;

string PlayerException::errorMessage[] = {
    "Eits, tidak bisa. Kamu tidak punya kartu Ability QUADRUPLE.",
    "Eits, tidak bisa. Kamu tidak punya kartu Ability QUARTER.",
    "Eits, tidak bisa. Kamu tidak punya kartu Ability REVERSE.\n",
    "Eits, tidak bisa. Kamu tidak punya kartu Ability ABILITYLESS.",
    "Eits, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah, penggunaan kartu ini sia-sia.",
    "Oops, kartu ABILITY-mu telah dimatikan sebelumnya :(.",
    "Indeks kartu yang kamu masukkan tidak valid.",
    "Eits, tidak bisa. Kamu tidak punya kartu Ability REROLL.",
    "Eits, tidak bisa. Kamu tidak punya kartu Ability SWAP.",
    "Eits, tidak bisa. Kamu tidak punya kartu Ability SWITCH.",
    "Eits, kamu tidak punya kartunya :).",
    "Kartu ABILITY yang kamu pilih telah digunakan sebelumnya.",
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
    cout << RED << errorMessage[this->Exception::ID] << RESET << endl;
}

// Path: Tubes1_OOP\lib\Exception\Player.cpp
// Compare this snippet from Tubes1_OOP\lib\Exception\cardException.cpp: