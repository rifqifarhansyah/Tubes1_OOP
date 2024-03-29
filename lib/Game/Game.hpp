#ifndef GAME_HPP
#define GAME_HPP

#include "../Player/Player.hpp"
#include "../TableCard/TableCard.hpp"
#include "../MainDeck/MainDeck.hpp"
// #include "../Combination/Combination.hpp"
#include "../Card/Card.hpp"
#include "../Ability/Ability.hpp"
#include "../AbstractClasses/ValuedObject.hpp"
#include "../Exception/exceptionInterface.hpp"
#include "../IO/consoleIOInterface.hpp"
#include "../Exception/InputExceptionInterface.hpp"
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

class Game{
    protected:
        Player* playerList;
        Player* winner;
        vector<int> playOrder;
        vector<Ability*> abilityList;
        MainDeck deck;
        TableCard table;
        ConsoleIO consoleIO;
        int point;
        int round;
        int turn;
        int gameCount;
        bool isReversed;
        const int maxPlayer;
        const int maxRound;
        const int abilityCount;
        void startGame();
        void startRound();
        void resetGame();
    public:
        Game();
        ~Game();
        void play();
        Player& getPlayerByIDX(int);
        int getPlayerIDX(Player&);
        TableCard& getTable();
        MainDeck& getDeck();
        int getPoint();
        int getMaxPlayer(); // new
        ConsoleIO getConsoleIO(); // new

        int getChosenCardIDInput(); // new
        Card getChosenCard(Player, int); // new

        void setPlayer(int,const Player&);
        void setTable(const TableCard&);
        void setDeck(const MainDeck&);
        void setPoint(int);

        void reversePlayOrder();
        void switchCard(int IDXp1 ,int IDXp2); // new
        void swapCard(int IDXp1,int IDXp2,int idCardp1,int idCardp2);
        void giveAbilityToAll();

        void printOrder();
        void printRestOrder();
        void printNextRoundOrder();
        void printPlayerList(std::vector<int>); // new

};

#endif