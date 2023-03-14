#ifndef SWITCHCARD_HPP
#define SWITCHCARD_HPP

#include "Ability.hpp"

class SwitchCard : public Ability
{
    public:
        SwitchCard() : Ability("Switch", 6){}
        void action(Player& p,Game& g)
        {
            cout << p.getNamePlayer() << " melakukan switch!" << endl;
            cout << "Kartumu sekarang adalah:" << endl;
            cout << p.getNumberFirstCard() << "(" << p.getColorFirstCard() << ")" << endl;
            cout << p.getNumberSecondCard() << "(" << p.getColorSecondCard() << ")" << endl;
            cout << "Silakan pilih pemain yang kartunya ingin anda tukar:" << endl;

        }
};


#endif