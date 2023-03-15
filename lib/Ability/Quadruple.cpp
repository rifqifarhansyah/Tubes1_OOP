#include "Quadruple.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.hpp"

Quadruple::Quadruple() : Ability("Quadruple", 4){}

void Quadruple::action(Player& p,Game& g) const
{
    cout << p.getNamePlayer() << " melakukan DOUBLE! Poin hadiah naik dari " << g.getPoint() << " menjadi ";
    g.setPoint(g.getPoint()*4);
    cout << g.getPoint() << "!" << endl;
}