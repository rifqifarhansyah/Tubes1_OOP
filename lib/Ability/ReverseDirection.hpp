#ifndef REVERSEDIRECTION_HPP
#define REVERSEDIRECTION_HPP

#include "Ability.hpp"

class ReverseDirection : public Ability
{
    public:
        ReverseDirection() : Ability("Reverse Direction", 4){}
        void action(Player& p,Game& g)
        {
            g.reversePlayOrder();
            cout << p.getNamePlayer() << " melakukan reverse!" << endl;
            cout << "(sisa) urutan eksekusi giliran ini : " << "g.getPlayOrder" << endl; // hanya SISA urutan giliran pada ronde ketika kartu digunakan
            cout << "urutan eksekusi giliran selanjutnya : " << "g.getPlayOrder" << endl; // semua urutan giliran pada ronde berikutnya
            p.removeAbility();
        }
};


#endif