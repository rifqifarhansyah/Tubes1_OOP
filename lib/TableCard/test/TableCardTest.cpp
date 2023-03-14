#include "../TableCard.hpp"

int main() {
    cout << "TableCardTest" << endl;

    // tes default ctor, inventory kosong
    TableCard tc1;
    tc1.print();
    tc1.remove();

    Card c1(1, "Merah");
    Card c2(2, "Jingga");
    Card c3(3, "Kuning");
    Card c4(4, "Hijau");
    Card c5(5, "Biru");

    tc1.draw(c1);
    tc1.draw(c2);
    tc1.draw(c3);
    tc1.draw(c4);
    tc1.draw(c5);
    
    // tes inventory penuh
    tc1.draw(c1);
    tc1.draw(c2);

    // tes cctor
    TableCard tc2(tc1);
    tc2.print();
    tc2.clear();
    tc2.draw(c3);
    tc2.draw(c4);

    // cek tc1
    tc1.clear();
    tc1.print();

    // cek tc2
    std::vector<Card> cards = tc2.getCards();
    cout << "Kartu TableCard:" << endl;
    for (int i = 0; i < cards.size(); i++) {
        cout << i+1 << ". Kartu " << cards[i] << endl;
    }

    return 0;
}