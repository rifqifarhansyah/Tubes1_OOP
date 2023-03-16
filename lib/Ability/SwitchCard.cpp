#include "SwitchCard.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.hpp"
#include "../IO/consoleIOInterface.hpp"

#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define YELLOW "\033[1m\033[33m"
#define BLUE "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN "\033[1m\033[36m"
#define RESET "\033[0m"

SwitchCard::SwitchCard() : Ability("SWITCH", 8){};

void SwitchCard::action(Player& p,Game& g) const {
    ConsoleIO input;
    cout << p.getNamePlayer() << " melakukan switch!" << endl;

    // kodisi awal
    cout << "Kartumu sekarang adalah\t\t\t\t:" << endl;
    cout << p.getFirstCard() << endl;
    cout << p.getSecondCard() << endl;

    // memilih target yang ingin ditukar
    cout << "Silakan pilih pemain yang kartunya ingin anda tukar:" << endl;
    vector<int> choosenPlayer;
    for (int i = 0;i < g.getMaxPlayer();i++){
        if (g.getPlayerByIDX(i).getIDPlayer() != p.getIDPlayer()){
            choosenPlayer.push_back(i);
        }
    }
    g.printPlayerList(choosenPlayer);
    cout << GREEN << ">> " << RESET;
    int targetIdx = choosenPlayer[input.getNumberInRange(1,choosenPlayer.size())-1];
    Player& target = g.getPlayerByIDX(targetIdx);
    
    // menukar kartu pemain dengan target
    g.switchCard(g.getPlayerIDX(p), targetIdx);

    // kondisi akhir
    cout << "Kedua kartu " << p.getNamePlayer() << " telah ditukar dengan " << target.getNamePlayer() << endl;
    cout << "Kartumu sekarang adalah\t\t\t\t:" << endl;
    cout << p.getFirstCard() << " && " << p.getSecondCard() << endl;

}