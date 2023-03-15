#ifndef SWITCHCARD_HPP
#define SWITCHCARD_HPP

#include "Ability.hpp"

class SwitchCard : public Ability
{
    public:
        SwitchCard();
        void action(Player&,Game&) const;
};


#endif