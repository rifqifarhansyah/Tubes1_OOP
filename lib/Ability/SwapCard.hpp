#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP

#include "Ability.hpp"
#include "../IO/consoleIOInterface.hpp"

class SwapCard : public Ability
{
    public:
        SwapCard();
        void action(Player&,Game&) const;
};


#endif