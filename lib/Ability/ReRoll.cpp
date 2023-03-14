#include "ReRoll.hpp"

void ReRoll::action(Player& p,Game& g)
{
    cout << "Melakukan pembuangan pembuangan kartu yang sedang dimiliki" << endl;
    cout << "Kamu mendapatkan 2 kartu baru, yaitu: " << endl;
    Card c1 = g.getDeck().deal();
    Card c2 = g.getDeck().deal();
    cout << "1. " << c1 << endl;
    cout << "2. " << c2 << endl;
    p.setCard(c1, 0);
    p.setCard(c2, 1);
    p.removeAbility();
}