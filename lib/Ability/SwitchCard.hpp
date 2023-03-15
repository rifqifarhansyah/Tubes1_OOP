#ifndef SWITCHCARD_HPP
#define SWITCHCARD_HPP

#include "Ability.hpp"

class SwitchCard : public Ability
{
    public:
        SwitchCard() : Ability("Switch", 8){};
        static void doAction(Player& _player,Game& _game){
            SwitchCard a;
            a.action(_player, _game);
        }
        void action(Player&,Game&);
};


#endif