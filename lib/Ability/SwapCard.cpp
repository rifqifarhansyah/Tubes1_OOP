#include "SwapCard.hpp"

void SwapCard::action(Player& p,Game& g)
{
    cout << p.getNamePlayer() << " melakukan SWAPCARD" << endl;
    cout << "Silakan pilih pemain yang kartunya ingin anda tukar:" << endl;

    p.removeAbility();
}