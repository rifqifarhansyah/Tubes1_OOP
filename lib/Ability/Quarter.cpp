#include "Quarter.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.hpp"
#include "../Card/Card.hpp"

void Quarter::action(Player& p,Game& g)
{
    if (g.getPoint() != 1) {
        cout << p.getNamePlayer() << " melakukan QUARTER! Poin hadiah naik dari " << g.getPoint() << " menjadi ";
        if (g.getPoint() == 2) {
            g.setPoint(g.getPoint()/2);
        } else {
            g.setPoint(g.getPoint()/4);
        }
        cout << g.getPoint() << "!" << endl;
    } else {
        cout << p.getNamePlayer() << " melakukan QUARTER! Sayangnya poin hadiah sudah bernilai 1. Poin hadiah tidak berubah.. Giliran dilanjut!" << endl;
    }
    p.removeAbility();
}