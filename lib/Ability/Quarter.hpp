#ifndef QUARTER_HPP
#define QUARTER_HPP

#include "Ability.hpp"

class Quarter : public Ability
{
    public:
        Quarter();
        void action(Player&,Game&) const;
};


#endif