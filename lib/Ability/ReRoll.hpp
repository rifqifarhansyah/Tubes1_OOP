#ifndef REROLL_HPP
#define REROLL_HPP

#include "Ability.hpp"

class ReRoll : public Ability
{
    public:
        ReRoll() : Ability("Re-Roll", 3){};
        static void doAction(Player& _player,Game& _game){
            ReRoll a;
            a.action(_player, _game);
        }
        void action(Player&,Game&);
};


#endif