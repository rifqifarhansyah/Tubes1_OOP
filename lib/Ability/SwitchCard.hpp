#ifndef SWITCHCARD_HPP
#define SWITCHCARD_HPP

#include "Ability.hpp"

class SwitchCard : public Ability
{
    public:
        SwitchCard() : Ability("Switch", 8){}
        void action(Player&,Game&);
};


#endif