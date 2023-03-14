#ifndef ABILITYLESS_HPP
#define ABILTYLESS_HPP

#include "Ability.hpp"

class Abilityless : public Ability
{
    public:
        Abilityless() : Ability("Abilityless",7){}
        void action(Player&,Game&);
};


#endif