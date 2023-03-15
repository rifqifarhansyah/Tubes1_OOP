#include "Game.hpp"
#include "../Ability/Abilityless.hpp"
#include "../Ability/Quadruple.hpp"
#include "../Ability/Quarter.hpp"
#include "../Ability/ReRoll.hpp"
#include "../Ability/ReverseDirection.hpp"
#include "../Ability/SwapCard.hpp"
#include "../Ability/SwitchCard.hpp"
#include "../TemplateFunction/TemplateFunction.hpp"
#include <iostream>



Game::Game() : maxPlayer(7), maxRound(6), abilityCount(7), deck(), table(), winner(NULL), consoleIO(){
    point = 64;
    round = 1;
    turn = 0;
    playOrder.resize(maxPlayer);
    playerList = new Player[maxPlayer];
    consoleIO.startPage();
    for (int i = 0;i < maxPlayer;i++){
        string name;
        cout << "Masukkan nama pemain ke-" << i+1 << " : ";
        cin >> name;
        playerList[i].setPlayerName(name);
    }
    for (int i = 0;i < maxPlayer;i++){
        playOrder[i] = i ;
    }
    abilityList.push_back(new Abilityless());
    abilityList.push_back(new Quadruple());
    abilityList.push_back(new Quarter());
    abilityList.push_back(new ReRoll());
    abilityList.push_back(new ReverseDirection());
    abilityList.push_back(new SwapCard());
    abilityList.push_back(new SwitchCard());
}

Game::~Game(){
    delete[] playerList;
    for (int i = 0;i < maxPlayer;i++){
        delete abilityList[i];
    }
}

void Game::play(){
    while(winner == NULL){
        startGame();
        Player* maxPlayer = &getMaxArr(playerList,7);
        if (maxPlayer->getPointPlayer() > pow(2,32)){
            winner = maxPlayer;
        }
        resetGame();
    }
    cout << "Permainan selesai." << endl;
    cout << "Pemenangnya adalah : " << endl;
    cout << winner->getNamePlayer() << " ! ! !" << endl;
    cout << "Dengan total poin : " << winner->getPointPlayer() << endl;
}

void Game::startGame(){
    deck.shuffle();
    for (int i = 0;i < maxPlayer;i++){
        deck - playerList[i];
        deck - playerList[i];
    }
    for (round = 1;round <= maxRound;round++){
        cout << endl;
        startRound();
        playOrder.push_back(*playOrder.begin());
        playOrder.erase(playOrder.begin());

    }

}

void Game::startRound(){
    cout << "Ronde ke - " << round << endl << endl;;
    if (round == 2)
        giveAbilityToAll();
    int i = 0;
    for (turn = 0;turn < maxPlayer;turn++){ 
        if (round >= 2){
            table.print();
            cout << endl;
        }
        int curPlayer = playOrder[turn];
        cout << "Kartu Anda(" << playerList[curPlayer].getNamePlayer() << ") :" << endl;
        cout << playerList[curPlayer].getFirstCard() << " && " <<  playerList[curPlayer].getSecondCard() << endl;
        if (round >= 2) {
            cout << "Ability Anda :" << endl;
            cout << playerList[curPlayer].getAbility()->getName() << " (" << playerList[curPlayer].getAbility()->getID() << ")" << endl;
        }
        consoleIO.askForCommand(playerList[curPlayer],*this);
        cout << endl;
    }
    if (round <= 5)
        deck - table;
    cout << endl;
}

void Game::resetGame(){
    for (int i = 0;i < maxPlayer;i++){
        playerList[i].clear();
    }
    table.clear();
    MainDeck newDeck;
    deck = newDeck;
}

Player& Game::getPlayerByIDX(int i){
    if (i < 0 || i >= maxPlayer)
    {
        // throw out of bound
    }
    return playerList[i];
}

TableCard& Game::getTable(){
    return table;
}
MainDeck& Game::getDeck(){
    return deck;
}

int Game::getPoint(){
    return point;
}

void Game::setPlayer(int i, const Player& player){
    playerList[i] = player;
}

void Game::setTable(const TableCard& table){
    this->table = table;
}

void Game::setDeck(const MainDeck& deck){
    this->deck = deck;
}

void Game::setPoint(int point){
    this->point = point;
}

void Game::reversePlayOrder()
{
    printOrder();
    cout << endl;
    reverse(playOrder.begin()+turn+1,playOrder.end());
    reverse(playOrder.begin(),playOrder.begin()+turn+1);
    printOrder();
    cout << endl;
}

void Game::printOrder(){
    for (int i = 0;i < maxPlayer;i++){
        if (i != 0) cout << " ";
        cout << playerList[playOrder[i]].getNamePlayer();
    }
}

void Game::printRestOrder(){
    for (int i = turn+1;i < maxPlayer;i++){
        if (i != turn+1) cout << " ";
        cout << playerList[playOrder[i]].getNamePlayer();
    }
}

void Game::printNextRoundOrder(){
    for (int i = 1;i < maxPlayer;i++){
        if (i != turn) cout << " ";
        cout << playerList[playOrder[i]].getNamePlayer();
    }
    cout << " " << playerList[playOrder[0]].getNamePlayer();
}

void Game::giveAbilityToAll(){
    ShuffleVec(abilityList);
    for (int i = 0;i < maxPlayer;i++){
        playerList[i].removeAbility();
        playerList[i].setAbility(abilityList[i]);
    }
}

