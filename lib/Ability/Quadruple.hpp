#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include "Ability.hpp"

class Quadruple : public Ability
{
    public:
        Quadruple() : Ability("Quadruple", 2){}
        void action(Player& p,Game& g)
        {
            cout << p.getNamePlayer() << " melakukan DOUBLE! Poin hadiah naik dari " << g.getPoint() << " menjadi ";
            g.setPoint(g.getPoint()*4);
            cout << g.getPoint() << "!" << endl;
            p.removeAbility();
        }
};


#endif