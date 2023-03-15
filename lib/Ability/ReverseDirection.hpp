#ifndef REVERSEDIRECTION_HPP
#define REVERSEDIRECTION_HPP

#include "Ability.hpp"

class ReverseDirection : public Ability
{
    public:
        ReverseDirection() : Ability("Reverse Direction", 6){};
        static void doAction(Player& _player,Game& _game){
            ReverseDirection a;
            a.action(_player, _game);
        }
        void action(Player&,Game&);
};


#endif