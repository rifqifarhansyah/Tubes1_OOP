#include "ReverseDirection.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.hpp"

ReverseDirection::ReverseDirection() : Ability("Reverse Direction", 6){}

void ReverseDirection::action(Player& p,Game& g) const
{
    g.reversePlayOrder();
    cout << p.getNamePlayer() << " melakukan reverse!" << endl;
    cout << "(sisa) urutan eksekusi giliran ini : ";
    g.printRestOrder(); 
    cout << endl; // hanya SISA urutan giliran pada ronde ketika kartu digunakan
    cout << "urutan eksekusi giliran selanjutnya : ";
    g.printNextRoundOrder();
    cout << endl; // semua urutan giliran pada ronde berikutnya
    p.removeAbility();
}