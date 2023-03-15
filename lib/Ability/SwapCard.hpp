#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP

#include "Ability.hpp"

class SwapCard : public Ability
{
    public:
        SwapCard();
        void action(Player&,Game&) const;
};


#endif