#include "SwitchCard.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.hpp"


SwitchCard::SwitchCard() : Ability("Switch", 8){};

void SwitchCard::action(Player& p,Game& g) const {
    cout << p.getNamePlayer() << " melakukan switch!" << endl;
    std::vector<Player> playerList = g.makePlayerList(p, g);

    // kodisi awal
    cout << "Kartumu sekarang adalah:" << endl;
    cout << p.getFirstCard() << endl;
    cout << p.getSecondCard() << endl;

    // memilih target yang ingin ditukar
    cout << "Silakan pilih pemain yang kartunya ingin anda tukar:" << endl;
    g.printPlayerList(playerList);
    Player target = g.getChosenPlayer(playerList);

    // menukar kartu pemain dengan target
    g.switchCard(p, target);

    // kondisi akhir
    cout << "Kedua kartu " << p.getNamePlayer() << " telah ditukar dengan " << target.getNamePlayer() << endl;
    cout << "Kartumu sekarang adalah:" << endl;
    cout << p.getFirstCard() << " && " << p.getSecondCard() << endl;

}