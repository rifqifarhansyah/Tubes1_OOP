#include "Game.hpp"
#include <iostream>

template <class T>
T& getMaxArr(T arr[], int n){
    T& min = arr[0];
    for (int i = 1;i < n;i++){
        if (arr[i] > min){
            min = arr[i];
        }
    }
    return min;
}


Game::Game() : maxPlayer(7), maxRound(6), deck(), table(), winner(NULL), playOrder(maxPlayer){
    point = 64;
    round = 1;
    playerList = new Player[maxPlayer];
    for (int i = 0;i < maxPlayer;i++){
        string name;
        cout << "Masukkan nama pemain ke-" << i+1 << " : ";
        cin >> name;
        playerList[i].setPlayerName(name);
    }
    for (int i = 0;i < maxPlayer;i++){
        playOrder[i] = i ;
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
        deck - playerList[i] - playerList[i];
    }
    for (int round = 1;round <= maxRound;round++){
        startRound();
        playOrder.push_back(*playOrder.begin());
        playOrder.erase(playOrder.begin());
    }

}

void Game::startRound(){
    if (round == 2)
        giveAbilityToAll();
    int i = 0;
    for (turn = 0;turn < maxPlayer;turn++){ 
        if (round >= 2){
            cout << "Kartu pada table :" << endl;
            table.print();
        }
        cout << "Kartu anda :" << endl;
        cout << playerList[i].getColorFirstCard() << endl;
        while (true){
            try {
                // tanya aksi
                int kode;
                cin >> kode;
                if (kode >= 3){
                    playerList[turn].useAbility(kode,*this);
                } else {
                    
                }
                break;
            } catch (Exception& e){
                e.displayMessage();
            }
        }
    }
    if (round <= 5)
        deck - table;
}

void Game::resetGame(){
    for (int i = 0;i < 7;i++){
        playerList[i].clear();
    }
    table.clear();
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
    reverse(playOrder.begin()+turn+1,playOrder.end());
    reverse(playOrder.begin(),playOrder.begin()+turn+1);
}

void Game::printRestOrder(){
    for (int i = turn;i < maxPlayer;i++){
        if (i != turn) cout << " ";
        cout << playerList[i].getNamePlayer();
    }
}

void Game::printNextRoundOrder(){
    for (int i = 1;i < maxPlayer;i++){
        if (i != turn) cout << " ";
        cout << playerList[i].getNamePlayer();
    }
    cout << " " << playerList[0].getNamePlayer();
}

void Game::giveAbilityToAll(){
    cout << "test\n";
}

