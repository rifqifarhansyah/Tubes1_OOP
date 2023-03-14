#ifndef QUARTER_HPP
#define QUARTER_HPP

#include "Ability.hpp"

class Quarter : public Ability
{
    public:
        Quarter() : Ability("Quarter", 3){}
        void action(Player& p,Game& g)
        {
            if (g.getPoint() != 1) {
                cout << p.getNamePlayer() << " melakukan QUARTER! Poin hadiah naik dari " << g.getPoint() << " menjadi ";
                if (g.getPoint() == 2) {
                    g.setPoint(g.getPoint()/2);
                } else {
                    g.setPoint(g.getPoint()/4);
                }
                cout << g.getPoint() << "!" << endl;
            }
        }
};


#endif