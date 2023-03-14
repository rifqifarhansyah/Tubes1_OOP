#include "SwitchCard.hpp"
#include "../Player/Player.hpp"


void SwitchCard::action(Player& p,Game& g) {
        {
            cout << p.getNamePlayer() << " melakukan switch!" << endl;
            cout << "Kartumu sekarang adalah:" << endl;
            cout << p.getFirstCard() << endl;
            cout << p.getSecondCard() << endl;
            cout << "Silakan pilih pemain yang kartunya ingin anda tukar:" << endl;
        }
}