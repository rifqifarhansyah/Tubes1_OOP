#ifndef ABILITY_HPP
#define ABILITY_HPP

#include<iostream>
#include"../Player/Player.hpp"
#include "../Game/Game.hpp"
using namespace std;

class Ability{
    protected:
        string abilityName;
    public:
        Ability()
        {
            this->abilityName = "none";
        }
        Ability(string nama)
        {
            this->abilityName = nama;
        }
        virtual void action(Player& p, Game& g) = 0;
};




#endif