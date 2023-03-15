#ifndef REVERSEDIRECTION_HPP
#define REVERSEDIRECTION_HPP

#include "Ability.hpp"

class ReverseDirection : public Ability
{
    public:
        ReverseDirection();
        void action(Player&,Game&) const;
};


#endif