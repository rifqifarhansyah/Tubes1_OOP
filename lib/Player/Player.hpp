#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include<iostream>
#include "../AbstractClasses/InventoryHolder.hpp"
#include "../MainDeck/MainDeck.hpp"
#include "../Ability/Ability.hpp"
#include "../Card/Card.hpp"
#include "../Game/Game.hpp"
using namespace std;
#define Max 2

class Player : public InventoryHolder<Card>{
protected:
    int poin;
    string playerName;
    const int id;
    bool abilityIsUsed; // new
    bool abilityIsBlocked;
    Ability* ability; //new
public:
    static int totalPlayer;
    Player();
    Player(string, Ability&);
    Player(const Player&);
    ~Player();
    Player& operator=(const Player&);
    bool operator>(const Player&);
    bool operator<(const Player&);
    Player& operator+(const Card&);

    int getNumberFirstCard();
    int getNumberSecondCard();
    string getColorFirstCard();
    string getColorSecondCard();

    void useAbility(int,Game&);
    void setAbility(Ability&);
    void removeAbility();
    bool hasAbility();
    bool isAbilityUsed();
    bool isAbilityBlocked();
    bool blockAbility();
    bool unblockAbility();

    int getTotalCard();
    int getIDPlayer();
    int getPointPlayer();
    string getNamePlayer();
    void setPlayerName(string);
    void setPoinPlayer(int x);
    void addPoinPlayer(int x);
    void setCard(Card, int);
    void addCard(Card x);
    void print();
};



#endif