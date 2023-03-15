#include "../StraightFlush.hpp"
#include "../../Player/Player.hpp"
#include "../../TableCard/TableCard.hpp"
#include "../../MainDeck/MainDeck.hpp"
#include <vector>
#include <iostream>
using namespace std;


int main(){
    int inp;
    cout << "1. random card\n";
    cout << "2. input manual";
    cin >> inp;
    Player P;
    TableCard T;
    switch (inp){
        case 1:
        {
            MainDeck Deck;
            Deck.shuffle();
            for (int i = 0;i < 2;i++){
                Deck - P;
            }
            for (int i = 0;i < 5;i++){
                Deck - T;
            }
            break;
        }
        case 2:
        {
            cout << "format input kartu : <angka> <Warna>" << endl;
            cout << "Masukkan 2 kartu player :" << endl;
            for (int i = 0;i < 2;i++){
                int a; string w;
                cin >> a >> w;
                Card tmp(a,w);
                P.addCard(tmp);
            }
            cout << "Masukkan 5 kartu table : " << endl;
            for (int i = 0;i < 5;i++){
                int a; string w;
                cin >> a >> w;
                Card tmp(a,w);
                T.draw(tmp);
            }
            break;
        }
    }
    P.print();
    T.print();
    StraightFlush S(P,T);
    // diapain lagi?
}
