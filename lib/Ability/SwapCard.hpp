#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP

#include "Ability.hpp"

class SwapCard : public Ability
{
    public:
        SwapCard() : Ability("Swap", 5){}
        void action(Player&,Game&);
};


#endif