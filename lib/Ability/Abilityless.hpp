#ifndef ABILITYLESS_HPP
#define ABILTYLESS_HPP

#include "Ability.hpp"

class Abilityless : public Ability
{
    public:
        Abilityless() : Ability("Abilityless",9){};
        static void doAction(Player& _player,Game& _game){
            Abilityless a;
            a.action(_player, _game);
        }
        void action(Player&,Game&);
};


#endif