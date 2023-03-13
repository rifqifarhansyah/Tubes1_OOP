#ifndef ABILITYLESS_HPP
#define ABILTYLESS_HPP

#include"Ability.hpp"

class Abilityless : public Ability
{
    public:
        Abilityless() : Ability("Abilityless"){}
        void action(Player p,Game& g)
        {
            
        }
};


#endif