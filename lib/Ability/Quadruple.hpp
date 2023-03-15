#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include "Ability.hpp"

class Quadruple : public Ability
{
    public:
        Quadruple();
        void action(Player&,Game&) const;
};


#endif