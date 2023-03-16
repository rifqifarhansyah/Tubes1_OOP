#include "SwitchCard.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.hpp"
#include "../IO/consoleIOInterface.hpp"

SwitchCard::SwitchCard() : Ability("Switch", 8){};

void SwitchCard::action(Player& p,Game& g) const {
    ConsoleIO input;
    cout << p.getNamePlayer() << " melakukan switch!" << endl;

    // kodisi awal
    cout << "Kartumu sekarang adalah:" << endl;
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
    int targetIdx = choosenPlayer[input.getNumberInRange(1,choosenPlayer.size())-1];
    Player& target = g.getPlayerByIDX(targetIdx);
    
    // menukar kartu pemain dengan target
    g.switchCard(g.getPlayerIDX(p), targetIdx);

    // kondisi akhir
    cout << "Kedua kartu " << p.getNamePlayer() << " telah ditukar dengan " << target.getNamePlayer() << endl;
    cout << "Kartumu sekarang adalah:" << endl;
    cout << p.getFirstCard() << " && " << p.getSecondCard() << endl;

}