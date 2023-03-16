#include "SwapCard.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.hpp"

#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define YELLOW "\033[1m\033[33m"
#define BLUE "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN "\033[1m\033[36m"
#define RESET "\033[0m"

SwapCard::SwapCard() : Ability("SWAP", 7){};

void SwapCard::action(Player& p,Game& g) const
{   
    ConsoleIO input;
    cout << p.getNamePlayer() << " melakukan SWAPCARD" << endl;
    vector<int> choosenPlayer;
    for (int i = 0;i < g.getMaxPlayer();i++){
        if (g.getPlayerByIDX(i).getIDPlayer() != p.getIDPlayer()){
            choosenPlayer.push_back(i);
        }
    }
    // memilih p1
    cout << "Silakan pilih pemain 1 yang kartunya ingin anda tukar:" << endl;
    g.printPlayerList(choosenPlayer);
    cout << GREEN << ">> " << RESET;
    int idxP1 = choosenPlayer[input.getNumberInRange(1,choosenPlayer.size())-1];

    choosenPlayer.erase(find(choosenPlayer.begin(),choosenPlayer.end(),idxP1));

    // memilih p2
    cout << "Silakan pilih pemain 2 yang kartunya ingin anda tukar:" << endl;
    g.printPlayerList(choosenPlayer);
    cout << GREEN << ">> " << RESET;
    int idxP2 = choosenPlayer[input.getNumberInRange(1,choosenPlayer.size())-1];

    // memilih kartu p1
    cout << "Silakan pilih kartu kiri/kanan " << g.getPlayerByIDX(idxP1).getNamePlayer() << endl;
    int cardIdP1 = g.getChosenCardIDInput();

    // memilih kartu p2
    cout << "Silakan pilih kartu kiri/kanan " << g.getPlayerByIDX(idxP2).getNamePlayer() << endl;
    int cardIdP2 = g.getChosenCardIDInput();

    // menukar kedua kartu
    g.swapCard(idxP1,idxP2,cardIdP1,cardIdP2);
}