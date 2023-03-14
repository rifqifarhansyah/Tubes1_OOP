#include"Ability.hpp"

Ability::Ability()
{
    this->abilityName = "none";
    this->abilityID = -1;
}
Ability::Ability(string name, int id)
{
    this->abilityName = name;
    this->abilityID = id;
}

void Ability::action(Player& p, Game& g)
{

}
string Ability::getName()
{
    return this->abilityName;
}
int Ability::getID()
{
    return this->abilityID;
}