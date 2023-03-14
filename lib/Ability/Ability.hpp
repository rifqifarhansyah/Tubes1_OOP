#ifndef ABILITY_HPP
#define ABILITY_HPP

#include "../Player/Player.hpp"
#include "../Game/Game.hpp"
#include "../MainDeck/MainDeck.hpp"
#include <iostream>
using namespace std;

class Ability{
    protected:
        string abilityName;
        int abilityID;
    public:
        Ability();
        Ability(string nama,int);
        string getName();
        int getID();
        virtual void action(Player& p, Game& g);
};




#endif