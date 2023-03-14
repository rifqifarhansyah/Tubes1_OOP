#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP

#include "Ability.hpp"

class SwapCard : public Ability
{
    public:
        SwapCard() : Ability("Swap", 5){}
        void action(Player& p,Game& g)
        {
            cout << p.getNamePlayer() << " melakukan SWAPCARD" << endl;
            cout << "Silakan pilih pemain yang kartunya ingin anda tukar:" << endl;

            p.removeAbility();
        }
};


#endif