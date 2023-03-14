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
        Ability();
        Ability(string nama);
        string getName();
        virtual void action(Player& p, Game& g);
};




#endif