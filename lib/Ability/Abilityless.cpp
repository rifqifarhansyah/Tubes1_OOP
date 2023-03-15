#include "Abilityless.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.hpp"


Abilityless::Abilityless() : Ability("Abilityless",9){}

void Abilityless::action(Player& p,Game& g) const
{
    int maxplayer = 7;
    Player cek[maxplayer];
    for(int i = 0;i<maxplayer;i++)
    {
        cek[i] = g.getPlayerByIDX(i);
    }
    bool allUsed = true;
    for(int i = 0;i<maxplayer;i++)
    {
        if(!cek[i].isAbilityUsed())
        {
            allUsed = false;
        }
    }
    if(allUsed)
    {
        cout<<"Eitsss, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu kena sendiri deh, kemampuan kamu menjadi abilityless. Yah, penggunaan kartu ini sia-sia :D"<<endl;
    }
    else if(p.getNameAbility() != "Abilityless")
    {
        cout<<"Eits kamu tidak punya kartu :D"<<endl;
    }
    else
    {
        cout<<p.getNamePlayer()<<" akan mematikan kartu ability lawan!"<<endl;
        cout<<"Silahkan pilih pemain yang kartu abilitynya ingin dimatikan"<<endl;
        int index;
        int count=0;
        for(int i=0;i<maxplayer;i++)
        {
            if(cek[i].getNamePlayer()==p.getNamePlayer()) 
            {
                index = i;
                continue;
            }
            else cout<<count+1<<". "<<cek[i].getNamePlayer()<<endl;
            count+=1;
        }
        int pilihplayer;
        cin>>pilihplayer;
        if(pilihplayer-1>=index)
        {
            if(cek[pilihplayer].isAbilityUsed())
        {
            cout<<"Kartu ability "<<cek[pilihplayer].getNamePlayer()<<" telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia"<<endl;
        }
        else
        {
            cout<<"Kartu ability "<<cek[pilihplayer].getNamePlayer()<<" telah dimatikan."<<endl;
            g.getPlayerByIDX(pilihplayer).blockAbility();
        }
        p.setAbilityhasUsed();
        }
        else if(pilihplayer-1<index)
        {
        if(cek[pilihplayer-1].isAbilityUsed())
        {
            cout<<"Kartu ability "<<cek[pilihplayer-1].getNamePlayer()<<" telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia"<<endl;
        }
        else
        {
            cout<<"Kartu ability "<<cek[pilihplayer-1].getNamePlayer()<<" telah dimatikan."<<endl;
            g.getPlayerByIDX(pilihplayer-1).blockAbility();
        }
        p.setAbilityhasUsed();
        }
        
        
    }
}