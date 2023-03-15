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

void Ability::action(Player& p, Game& g) const
{

}
string Ability::getName() const
{
    return this->abilityName;
}
int Ability::getID() const
{
    return this->abilityID;
}