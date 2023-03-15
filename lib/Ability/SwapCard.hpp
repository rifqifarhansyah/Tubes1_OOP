#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP

#include "Ability.hpp"

class SwapCard : public Ability
{
    public:
        SwapCard() : Ability("Swap", 7){};
        static void doAction(Player& _player,Game& _game){
            SwapCard a;
            a.action(_player, _game);
        }
        void action(Player&,Game&);
};


#endif