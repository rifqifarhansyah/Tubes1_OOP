#include "SwitchCard.hpp"

void SwitchCard::action(Player& p,Game& g) {
        {
            cout << p.getNamePlayer() << " melakukan switch!" << endl;
            cout << "Kartumu sekarang adalah:" << endl;
            cout << p.getNumberFirstCard() << "(" << p.getColorFirstCard() << ")" << endl;
            cout << p.getNumberSecondCard() << "(" << p.getColorSecondCard() << ")" << endl;
            cout << "Silakan pilih pemain yang kartunya ingin anda tukar:" << endl;

            p.removeAbility();
        }
}