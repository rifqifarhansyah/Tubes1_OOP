#ifndef REROLL_HPP
#define REROLL_HPP

#include "Ability.hpp"

class ReRoll : public Ability
{
    public:
        ReRoll();
        void action(Player&,Game&) const;
};


#endif