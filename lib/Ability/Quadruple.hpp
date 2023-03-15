#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include "Ability.hpp"

class Quadruple : public Ability
{
    public:
        Quadruple() : Ability("Quadruple", 4){};
        static void doAction(Player& _player,Game& _game){
            Quadruple a;
            a.action(_player, _game);
        }
        void action(Player&,Game&);
};


#endif