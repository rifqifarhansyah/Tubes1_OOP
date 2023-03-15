#include "SwitchCard.hpp"
#include "../Player/Player.hpp"


SwitchCard::SwitchCard() : Ability("Switch", 8){};

void SwitchCard::action(Player& p,Game& g) const {
        {
            cout << p.getNamePlayer() << " melakukan switch!" << endl;
            cout << "Kartumu sekarang adalah:" << endl;
            cout << p.getFirstCard() << endl;
            cout << p.getSecondCard() << endl;
            cout << "Silakan pilih pemain yang kartunya ingin anda tukar:" << endl;
        }
}