#include "Game.hpp"
#include "../Ability/Abilityless.hpp"
#include "../Ability/Quadruple.hpp"
#include "../Ability/Quarter.hpp"
#include "../Ability/ReRoll.hpp"
#include "../Ability/ReverseDirection.hpp"
#include "../Ability/SwapCard.hpp"
#include "../Ability/SwitchCard.hpp"
#include "../TemplateFunction/TemplateFunction.hpp"
#include "../Combination/StraightFlush.hpp"
#include <iostream>

#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define YELLOW "\033[1m\033[33m"
#define BLUE "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN "\033[1m\033[36m"
#define RESET "\033[0m"

Game::Game() : maxPlayer(7), maxRound(6), abilityCount(7),deck(), table(), winner(NULL), consoleIO(){
    point = 64;
    round = 1;
    gameCount = 0;
    turn = 0;
    playOrder.resize(maxPlayer);
    playerList = new Player[maxPlayer];
    consoleIO.startPage();
    cout << "                                              " << GREEN << "--- INPUT NAMA PEMAIN ---" << RESET << "                                             " << endl;
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
    cout<<"Apakah anda ingin menginput file untuk Main Deck?"<<endl;
    cout<<"1. Ya"<<endl;
    cout<<"2. Tidak"<<endl;
    cout<<">> ";
    int pilihplayer = consoleIO.getNumberInRange(1,2);
    if(pilihplayer==1)
    {
        this->deck = consoleIO.readMainDeck();
    }
    else
    {
        this->deck.shuffle();
    }
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
        } else {
            cout << "Permainan akan dilanjutkan." << endl;
        }
        consoleIO.waitEnterInput();
        resetGame();
    }
    cout << "Permainan selesai." << endl;
    cout << "Pemenangnya adalah : " << endl;
    cout << winner->getNamePlayer() << " ! ! !" << endl;
    cout << "Dengan total poin : " << winner->getPointPlayer() << endl;
}

void Game::startGame(){
    gameCount++;
    cout << RED << "                                                --- PERMAINAN KE " << gameCount << " ---" << RESET << endl << endl;
    deck.shuffle();
    for (int i = 0;i < maxPlayer;i++){
        deck - playerList[i];
        deck - playerList[i];
    }
    for (round = 1;round <= maxRound;round++){
        startRound();
        playOrder.push_back(*playOrder.begin());
        playOrder.erase(playOrder.begin());

    }
    int idxWinner;
    map<int,StraightFlush> comboList;
    for (int i = 0;i < maxPlayer;i++){
        StraightFlush combo(playerList[i],table);
        comboList.insert(pair<int,StraightFlush>(i,combo));
    }
    idxWinner = getMaxMapKey(comboList);
    if (!(comboList[0].findMaxCombinationTable().empty()) && comboList[0].getHighestNumber() == 13){
        bool isAllNoStraigthFlush = true;
        for (int i = 0;i < maxPlayer;i++){
            if (!comboList[i].findMaxCombinationAll().empty()){
                isAllNoStraigthFlush = false;
                break;
            }
        }
        if (isAllNoStraigthFlush){
            map<int,ThreeOfAKind> comboListTAK;
            for (int i = 0;i < maxPlayer;i++){
                ThreeOfAKind comboTAK(playerList[i],table);
                comboListTAK.insert(pair<int,ThreeOfAKind>(i,comboTAK));
            }
            idxWinner = getMaxMapKey(comboListTAK);
        }
    }
    Player& roundWinner = playerList[idxWinner]; // nanti diganti dengan pemenang
    cout << "Pemenang di permainan ini adalah\t\t\t: \n";
    cout << roundWinner.getNamePlayer() << endl << endl;
    cout << "Poin hadiah sebesar " << point << " poin diberikan ke " << roundWinner.getNamePlayer() << endl;
    int oldPoin = roundWinner.getPointPlayer();
    int newPoin = oldPoin+point;
    roundWinner.setPoinPlayer(newPoin);
    cout << "Poin " << roundWinner.getNamePlayer() << " bertambah dari " << oldPoin << " menjadi " << newPoin << endl;
}

void Game::startRound(){
    cout << BLUE << "                                                  --- RONDE KE " << round << " ---" << RESET << endl << endl;;
    if (round == 2){
        giveAbilityToAll();
        cout << "Kartu ability sudah dibagikan!" << endl;
    }
    int i = 0;
    for (turn = 0;turn < maxPlayer;turn++){ 
        Player& curPlayer = playerList[playOrder[turn]];
        cout << "Giliran " << curPlayer.getNamePlayer() << "! " << endl;
        if (round >= 2){
            table.print();
            cout << endl;
        }
        cout << "Poin hadiah saat ini\t\t\t\t: " << point << endl;
        cout << "Kartu Anda\t\t\t\t\t: " << endl;
        cout << MAGENTA << "-- " << RESET;
        cout << curPlayer.getFirstCard() << " && " <<  curPlayer.getSecondCard() << endl;
        if (round >= 2) {
            cout << "Ability yang Anda punya\t\t\t\t:" << endl;
            cout << MAGENTA << "-- " << RESET;
            cout << curPlayer.getAbility()->getName();
            if (curPlayer.isAbilityBlocked()){
                cout << " (dimatikan)";
            } else if (curPlayer.isAbilityUsed()){
                cout << " (sudah digunakan)";
            }
            cout << endl;
        }
        consoleIO.askForCommand(curPlayer,*this);
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
    point = 0;
}

Player& Game::getPlayerByIDX(int i) {
    if (i < 0 || i >= maxPlayer)
    {
        // throw out of bound
        throw InventoryException(3);
    }
    return playerList[i];
}

int Game::getPlayerIDX(Player& p) {
    for (int i = 0;i < maxPlayer;i++){
        if (playerList[i].getIDPlayer() == p.getIDPlayer()){
            return i;
        }
    }
    return -1;
}

TableCard& Game::getTable()  {
    return table;
}
MainDeck& Game::getDeck() {
    return deck;
}

int Game::getPoint(){
    return point;
}

int Game::getMaxPlayer() {
    return maxPlayer;
}

ConsoleIO Game::getConsoleIO() {
    return consoleIO;
}

int Game::getChosenCardIDInput() {
    cout << "1. Kiri" << endl;
    cout << "2. Kanan" << endl;
    int idx = consoleIO.getNumberInRange(1, 2) - 1;
    return idx;
}

Card Game::getChosenCard(Player player, int idCard) {
    if (idCard == 0) {
        return player.getFirstCard();
    } else {
        return player.getSecondCard();
    }
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
    reverse(playOrder.begin()+turn+1,playOrder.end());
    reverse(playOrder.begin(),playOrder.begin()+turn+1);
}

void Game::switchCard(int IDXp1, int IDXp2) {
    Player& p1 = playerList[IDXp1];
    Player& p2 = playerList[IDXp2];
    Card firstCardP1 = p1.getFirstCard();
    Card secondCardP1 = p1.getSecondCard();
    Card firstCardP2 = p2.getFirstCard();
    Card secondCardP2 = p2.getSecondCard();
    p1.setCard(firstCardP2, 0);
    p1.setCard(secondCardP2, 1);
    p2.setCard(firstCardP1, 0);
    p2.setCard(secondCardP1, 1);    
}

void Game::swapCard(int IDXp1,int IDXp2,int idCardp1,int idCardp2){
    Player& p1 = playerList[IDXp1];
    Player& p2 = playerList[IDXp2];
    Card cardP1 = getChosenCard(p1, idCardp1);
    Card cardP2 = getChosenCard(p2, idCardp2);
    p1.setCard(cardP2, idCardp1);
    p2.setCard(cardP1, idCardp2); 
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

void Game::printPlayerList(vector<int> playerIDX){
    int counter = 1;
    for (auto it = playerIDX.begin();it != playerIDX.end();it++){
        cout << counter << ". " << playerList[*it].getNamePlayer() << endl;
        counter++;
    }
}

// P5 : 
// P6 : 

// P5 : 3H 8B
// P6 : 8B 3H