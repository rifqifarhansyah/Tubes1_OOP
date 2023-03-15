#include "Player.hpp"
#include<iostream>
#include<cstring>
#include<ctime>
#include "../Exception/playerCardExceptionInterface.hpp"

using namespace std;


int Player::totalPlayer = 0;

Player::Player() : id(totalPlayer+1),InventoryHolder<Card>(0,2)
{
    this->poin = 0;
    this->playerName = "none";
    this->ability = NULL;
    this->abilityIsUsed = false;
    this->abilityIsBlocked = false;
    totalPlayer++;
}
Player::Player(const Player& p) : id(totalPlayer+1),InventoryHolder(0,p.maxSize)
{
    int banyak = p.getSize();
    for(int i=0;i<banyak;i++)
    {
        addCard(p.inventory[i]);
    }
    this->poin = p.poin;
    this->playerName = p.playerName;
    this->ability = p.ability;
    this->abilityIsUsed = p.abilityIsUsed;
    this->abilityIsBlocked = p.abilityIsBlocked;
    totalPlayer++;
}
Player::Player(string nama,Ability & ab):id(totalPlayer+1),InventoryHolder(0,2)
{
    this->poin = 0;
    this->playerName = nama;
    this->ability = &ab;
    this->abilityIsUsed = false;
    this->abilityIsBlocked = false;
    totalPlayer++;

}
Player::~Player()
{
    removeAbility();
}
Player& Player::operator=(const Player& p)
{
    int banyak = p.getSize();
    for(int i=0;i<banyak;i++)
    {
        addCard(p.inventory[i]);
    }
    this->poin = p.poin;
    this->playerName = p.playerName;
    this->ability = p.ability;
    this->abilityIsUsed = p.abilityIsUsed;
    this->abilityIsBlocked = false;
    return *this;
}

Player& Player::operator+(const Card& x)
{
    addCard(x);
    return *this;
}

bool Player::operator>(const Player& p)
{
    return(this->poin > p.poin);
}

bool Player::operator<(const Player& p)
{
    return(this->poin < p.poin);
}

Card Player::getFirstCard()
{
    return getItem(0);
}

Card Player::getSecondCard()
{
    return getItem(1);
}


string Player::getNamePlayer()
{
    return this->playerName;
}

int Player::getTotalCard()
{
    return getSize();
}

int Player::getIDPlayer()
{
    return this->id;
}

int Player::getPointPlayer()
{
    return this->poin;
}

void Player::setPlayerName(string n)
{
    this->playerName = n;
}

void Player::addCard(Card x)
{
    insertFirst(x);
}

void Player::setPoinPlayer(int x)
{
    this->poin = x;
}

void Player::addPoinPlayer(int x)
{
    this->poin+=x;
}

void Player::setCard(Card x,int index)
{
    int banyakkartu = getSize();
    if(index>=banyakkartu)
    {
        //exception
    }
    else
    {
        this->inventory[index] = x;
    }
}

void Player::setAbility(Ability* ab)
{
   this->ability = ab;
   this->abilityIsUsed = false;
   this->abilityIsBlocked = false;
}

Ability* Player::getAbility()
{
    return this->ability;
}

void Player::removeAbility()
{
    this->ability = NULL;
    this->abilityIsUsed = false;
    this->abilityIsBlocked = false;
}
bool Player::hasAbility()
{
    return (this->ability!=NULL);
}

void Player::useAbility(const Ability& abilityToUse,Game& game)
{
    
    if(hasAbility()==false)
    {
        //exception tidak ada ability
    }
    else if(abilityToUse.getID()!=(this->ability)->getID())
    {
        //exception tidak ada ability yang dimaksud
    }
     else if (isAbilityBlocked()){
        //exception ability dimatikan
    } 
    else 
    {
        (this->ability)->action(*this,game);
        abilityIsUsed = true;
    }
}

bool Player::isAbilityBlocked(){
    return abilityIsBlocked;
}

void Player::blockAbility(){
    abilityIsBlocked = true;
}

void Player::unblockAbility(){
    abilityIsBlocked = false;
}

void Player::print()
{
    cout<<"Player dengan nama "<<getNamePlayer();
    if(getTotalCard()==0)
    {
        cout<<" tidak memiliki kartu"<<endl;
    }
    else
    {
        cout<<" memiliki kartu:"<<endl;
        if(getTotalCard()==1)
        {
            cout<<"Kartu pertama : "<< getFirstCard() <<endl;
        }
        if(getTotalCard()==2)
        {
            cout<<"Kartu pertama : "<<getFirstCard()<<endl;
            cout<<"Kartu kedua : "<<getSecondCard()<<endl;
        }
    }
    cout<<"Memiliki poin : "<<getPointPlayer()<<endl;
}



