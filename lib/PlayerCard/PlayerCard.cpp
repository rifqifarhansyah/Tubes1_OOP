#include "PlayerCard.hpp"
#include<iostream>
#include<cstring>
using namespace std;


int Player::totalPlayer = 0;

Player::Player() : id(totalPlayer+1),InventoryHolder<Card>(0,2)
{
    this->poin = 0;
    this->playerName = "none";
    totalPlayer++;
}
Player::Player(const Player& p) : id(totalPlayer+1),InventoryHolder(0,p.maxSize)
{
    int banyak = p.getSize();
    for(int i=0;i<banyak;i++)
    {
        setCard(p.inventory[i]);
    }
    this->poin = p.poin;
    this->playerName = p.playerName;
    totalPlayer++;
}
Player::Player(std::vector<Card> kartu,int poin,string nama):id(totalPlayer+1),InventoryHolder(0,2)
{
    this->poin = poin;
    this->playerName = nama;
    for(int i=0;i<kartu.size();i++)
    {
        setCard(kartu[i]);
    }
    totalPlayer++;

}
Player::~Player()
{

}
Player& Player::operator=(const Player& p)
{
    int banyak = p.getSize();
    for(int i=0;i<banyak;i++)
    {
        setCard(p.inventory[i]);
    }
    this->poin = p.poin;
    this->playerName = p.playerName;
    return *this;
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
void Player::setCard(Card x)
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

void Player::printCard()
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



int main()
{
    // srand(time(0));
    // Player arr[5];
    // for(int i=0;i<5;i++)
    // {
    //     string nama;
    //     cout<<"Masukkan nama = "<<endl;
    //     cin>>nama;
    //     int a = rand()%13+1;
    //     int b = rand()%13+1;
    //     int c = rand();
    //     arr[i].setCard(a);
    //     arr[i].setCard(b);
    //     arr[i].addPoinPlayer(c);
    //     arr[i].setPlayerName(nama);
    // }
    // for(int i=0;i<5;i++)
    // {
    //     cout<<"ID:"<<arr[i].getIDPlayer()<<endl;
    //     arr[i].printCard();
        
    // }




}