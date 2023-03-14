#include"Ability.hpp"

Ability::Ability()
{
    this->abilityName = "none";
}
Ability::Ability(string name)
{
    this->abilityName = name;
}
void Ability::action(Player& p, Game& g)
{

}
string Ability::getName()
{
    return this->abilityName;
}