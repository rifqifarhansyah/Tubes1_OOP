#ifndef GAME_HPP
#define GAME_HPP

#include "../Player/Player.hpp"
#include "../TableCard/TableCard.hpp"
#include "../MainDeck/MainDeck.hpp"
#include "../Combination/Combination.hpp"
#include "../Card/Card.hpp"
#include "../AbstractClasses/ValuedObject.hpp"
#include <vector>

class Game{
    private:
        Player* playerList;
        vector<Player*> playOrder;
        MainDeck deck;
        TableCard table;
        int point;
        int round;
        int gameCount;
        bool isReversed;
        const int maxPlayer;
        const int maxRound;
    public:
        Game();
        void StartGame();
        Player& getPlayer(int);
        Player& getPlayer(string);
        TableCard& getTable();
        MainDeck& getDeck();
        int getPoint();

        void setPlayer(const Player&);
        void setTable(const TableCard&);
        void setDeck(const MainDeck&);
        void setPoint(int);

        void reversePlayOrder();
};

#endif