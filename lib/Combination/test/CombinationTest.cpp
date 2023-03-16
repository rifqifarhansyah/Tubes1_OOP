#include "../StraightFlush.hpp"
#include "../../Player/Player.hpp"
#include "../../TableCard/TableCard.hpp"
#include "../../MainDeck/MainDeck.hpp"
#include <vector>
#include <iostream>
using namespace std;


int main(){
    srand(time(0));
    int inp;
    cout << "1. random card\n";
    cout << "2. input manual\n";
    cout << "pilihan : ";
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
            Card c1(5,"biru");
            Card c2(1,"hijau");
            P.addCard(c1);
            P.addCard(c2);
            // cout << "format input kartu : <angka> <Warna>" << endl;
            // cout << "Masukkan 2 kartu player :" << endl;
            // for (int i = 0;i < 2;i++){
            //     int a; string w;
            //     cout << i+1 << ". ";
            //     cin >> a >> w;
            //     Card tmp(a,w);
            //     P.addCard(tmp);
            // }
            Card T1(1,"merah");
            Card T2(5,"merah");
            Card T3(5,"kuning");
            Card T4(7,"biru");
            Card T5(8,"biru");
            T.draw(T1);
            T.draw(T2);
            T.draw(T3);
            T.draw(T4);
            T.draw(T5);
            // cout << "Masukkan 5 kartu table : " << endl;
            // for (int i = 0;i < 5;i++){
            //     int a; string w;
            //     cout << i+1 << ". ";
            //     cin >> a >> w;
            //     Card tmp(a,w);
            //     T.draw(tmp);
            // }
            break;
        }
    }
    P.print();
    T.print();
    StraightFlush S(P,T);
    HighCard H(P,T);
    Pair PA(P,T);
    cout << "Hasil : " << S.getValue() << endl;
    cout << "Hasil : " << H.getValue() << endl;
    cout << "Hasil : " << PA.getValue() << endl;
}


Hasil : 12.28
Hasil : 0.83
Hasil : 2.28


*/
