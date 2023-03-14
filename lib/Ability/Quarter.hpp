#ifndef QUARTER_HPP
#define QUARTER_HPP

#include "Ability.hpp"

class Quarter : public Ability
{
    public:
        Quarter() : Ability("Quarter", 3){}
        void action(Player&,Game&);
};


#endif