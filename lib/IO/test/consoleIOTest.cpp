#include "../consoleIOInterface.hpp"
#include "../commandInterface.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    // ConsoleIO CIO;
    // int test = CIO.getIntInput();
    // cout << test << endl;

    ConsoleIO CIO;
    MainDeck mainDeck = CIO.readMainDeck();
    Card card = mainDeck.deal();
    mainDeck.print();
    cout << "Kartu deck dealed: " << card << endl;

    return 0;
}
