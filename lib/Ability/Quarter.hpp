#ifndef QUARTER_HPP
#define QUARTER_HPP

#include "Ability.hpp"

class Quarter : public Ability
{
    public:
        Quarter() : Ability("Quarter", 5){};
        static void doAction(Player& _player,Game& _game){
            Quarter a;
            a.action(_player, _game);
        }
        void action(Player&,Game&);
};


#endif