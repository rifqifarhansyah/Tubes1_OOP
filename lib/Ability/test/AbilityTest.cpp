#include "../Abilityless.hpp"
#include "../Quadruple.hpp"
#include "../Quarter.hpp"
#include "../ReRoll.hpp"
#include "../ReverseDirection.hpp"
#include "../SwapCard.hpp"
#include "../SwitchCard.hpp"

int main() {
    // ctor ability
    ReRoll ab1;
    Quadruple ab2;
    Quarter ab3;
    ReverseDirection ab4;
    SwapCard ab5;
    SwitchCard ab6;
    Abilityless ab7;

    // ctor player
    srand(time(0));
    string warna[4] = {"Biru","Merah","Hijau","Kuning"};
    Player arr[6];
    for(int i=0;i<5;i++)
    {
        string nama;
        cout<<"Masukkan nama = "<<endl;
        cin>>nama;
        int a = rand()%13+1;
        int b = rand()%13+1;
        int randwar = rand()%4;
        int randwar2 = rand()%4;
        Card first(a,warna[randwar]);
        Card second(b,warna[randwar2]);
        int c = rand();
        arr[i]+first;
        arr[i]+second;
        arr[i].addPoinPlayer(c);
        arr[i].setPlayerName(nama);
    }
    
    for(int i=0;i<6;i++)
    {
        cout<<"ID:"<<arr[i].getIDPlayer()<<endl;
        arr[i].print();
        
    }
    
    return 0;
}