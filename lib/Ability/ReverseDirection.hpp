#ifndef REVERSEDIRECTION_HPP
#define REVERSEDIRECTION_HPP

#include "Ability.hpp"

class ReverseDirection : public Ability
{
    public:
        ReverseDirection() : Ability("Reverse Direction", 6){}
        void action(Player&,Game&);
};


#endif