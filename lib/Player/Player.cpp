#include "Player.hpp"
#include"../Card/Card.cpp"
#include<iostream>
#include<cstring>
#include<ctime>

using namespace std;


int Player::totalPlayer = 0;

Player::Player() : id(totalPlayer+1),InventoryHolder<Card>(0,2)
{
    this->poin = 0;
    this->playerName = "none";
    this->ability = NULL;
    this->isUsedAbility = false;
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
    this->isUsedAbility = p.isUsedAbility;
    totalPlayer++;
}
Player::Player(string nama,Ability & ab):id(totalPlayer+1),InventoryHolder(0,2)
{
    this->poin = 0;
    this->playerName = nama;
    this->ability = &ab;
    this->isUsedAbility = false;
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
    this->isUsedAbility = p.isUsedAbility;
    return *this;
}

Player& Player::operator+(const Card& x)
{
    addCard(x);
}
int Player::getNumberFirstCard()
{
    return getItem(0).getNumber();//angka kartu 1
}
string Player::getColorFirstCard()
{
    return getItem(0).getColor();
}
string Player::getNamePlayer()
{
    return this->playerName;
}
int Player::getNumberSecondCard()
{
    return getItem(1).getNumber();//angka kartu 2
}
string Player::getColorSecondCard()
{
    return getItem(1).getColor();
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

void Player::setAbility(Ability& ab)
{
   this->ability = &ab;
   this->isUsedAbility = false;
}

void Player::removeAbility()
{
    this->ability = NULL;
    this->isUsedAbility = false;
}
bool Player::hasAbility()
{
    return (this->ability!=NULL);
}

void Player::useAbility(string namaAbility,Game& game)
{
    
    if(hasAbility()==false)
    {
        //exception tidak ada ability
    }
    else if(namaAbility!=(this->ability)->getName())
    {
        //exception tidak ada ability yang dimaksud
    }
    else
    {
        (this->ability)->action(*this,game);
    }
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
            cout<<"Kartu pertama : "<<getNumberFirstCard()<<" "<<getColorFirstCard()<<endl;
        }
        if(getTotalCard()==2)
        {
            cout<<"Kartu pertama : "<<getNumberFirstCard()<<" "<<getColorFirstCard()<<endl;
            cout<<"Kartu kedua : "<<getNumberSecondCard()<<" "<<getColorSecondCard()<<endl;
        }
    }
    cout<<"Memiliki poin : "<<getPointPlayer()<<endl;
}



