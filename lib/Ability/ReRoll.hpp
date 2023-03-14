#ifndef REROLL_HPP
#define REROLL_HPP

#include "Ability.hpp"

class ReRoll : public Ability
{
    public:
        ReRoll() : Ability("Re-Roll", 3){}
        void action(Player&,Game&);
};


#endif