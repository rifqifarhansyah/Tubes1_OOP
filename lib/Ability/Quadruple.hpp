#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include "Ability.hpp"

class Quadruple : public Ability
{
    public:
        Quadruple() : Ability("Quadruple", 2){}
        void action(Player&,Game&);
};


#endif