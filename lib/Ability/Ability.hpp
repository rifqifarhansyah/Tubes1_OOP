#ifndef ABILITY_HPP
#define ABILITY_HPP



#include <iostream>
class Player;
class Game;
using namespace std;

class Ability{
    protected:
        string abilityName;
        int abilityID;
    public:
        Ability();
        Ability(string nama,int);
        string getName() const;
        int getID() const;
        virtual void action(Player& p, Game& g) const;
};




#endif