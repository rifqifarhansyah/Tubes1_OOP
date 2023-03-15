#include "SwapCard.hpp"
#include "../Player/Player.hpp"

SwapCard::SwapCard() : Ability("Swap", 7){};

void SwapCard::action(Player& p,Game& g) const
{
    cout << p.getNamePlayer() << " melakukan SWAPCARD" << endl;
    cout << "Silakan pilih pemain yang kartunya ingin anda tukar:" << endl;

    p.removeAbility();
}