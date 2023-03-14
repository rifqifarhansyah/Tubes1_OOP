#include "Quadruple.hpp"

void Quadruple::action(Player& p,Game& g)
{
    cout << p.getNamePlayer() << " melakukan DOUBLE! Poin hadiah naik dari " << g.getPoint() << " menjadi ";
    g.setPoint(g.getPoint()*4);
    cout << g.getPoint() << "!" << endl;
    p.removeAbility();
}