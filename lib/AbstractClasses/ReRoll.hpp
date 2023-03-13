#ifndef REROLL_HPP
#define REROLL_HPP

#include"Ability.hpp"

class ReRoll : public Ability
{
    public:
        ReRoll() : Ability("Re-Roll"){}
        void action(Player p,Game& g)
        {
            
        }
};


#endif