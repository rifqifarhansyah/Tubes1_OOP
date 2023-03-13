#ifndef QUARTER_HPP
#define QUARTER_HPP

#include"Ability.hpp"

class Quarter : public Ability
{
    public:
        Quarter() : Ability("Quarter"){}
        void action(Player p,Game& g)
        {
            
        }
};


#endif