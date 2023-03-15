#include "SwapCard.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.hpp"

SwapCard::SwapCard() : Ability("Swap", 7){};

void SwapCard::action(Player& p,Game& g) const
{
    cout << p.getNamePlayer() << " melakukan SWAPCARD" << endl;
    std::vector<Player> playerList = g.makePlayerList(p, g);

    // memilih p1
    cout << "Silakan pilih pemain yang kartunya ingin anda tukar:" << endl;
    g.printPlayerList(playerList);
    Player p1 = g.getChosenPlayer(playerList);

    // memilih p2
    cout << "Silakan pilih pemain yang kartunya ingin anda tukar:" << endl;
    g.printPlayerList(playerList);
    Player p2 = g.getChosenPlayer(playerList);

    // memilih kartu p1
    cout << "Silakan pilih kartu kanan/kiri " << p1.getNamePlayer() << endl;
    int idx1 = g.getChosenCardID();
    Card card1 = g.getChosenCard(p1, idx1);

    // memilih kartu p2
    cout << "Silakan pilih kartu kanan/kiri " << p1.getNamePlayer() << endl;
    int idx2 = g.getChosenCardID();
    Card card2 = g.getChosenCard(p2, idx2);

    // menukar kedua kartu
    p1.setCard(card2, idx1);
    p2.setCard(card1, idx2);
}