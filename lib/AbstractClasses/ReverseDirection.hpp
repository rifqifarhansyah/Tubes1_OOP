#ifndef REVERSEDIRECTION_HPP
#define REVERSEDIRECTION_HPP

#include"Ability.hpp"

class ReverseDirection : public Ability
{
    public:
        ReverseDirection() : Ability("Reverse Direction"){}
        void action(Player p,Game& g)
        {
            
        }
};


#endif