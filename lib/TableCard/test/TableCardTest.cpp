#include "../TableCard.hpp"

int main() {
    cout << "TableCardTest" << endl;
    
    // inisialisasi kartu
    std::vector<Card> inCards;
    Card c1(1, "Merah");
    Card c2(2, "Jingga");
    Card c3(3, "Kuning");
    Card c4(4, "Hijau");
    Card c5(5, "Biru");
    inCards.push_back(c1);
    inCards.push_back(c2);
    inCards.push_back(c3);
    inCards.push_back(c4);
    inCards.push_back(c5);

    // tes default ctor
    TableCard tc1;
    // tes user defined ctor
    TableCard tc2(inCards);
    // tes cctor
    TableCard tc3(tc2);

    // tes draw()
    for (int i = 0; i < 5; i++) {
        tc1.draw(inCards[i]);
    }
    // tes inventory penuh
    tc1.print();
    tc1.draw(c1);

    // tes remove()
    tc2.remove();
    tc2.print();
    // tes clear()
    tc3.clear();
    // tes inventory kosong
    tc3.print();
    tc3.remove();

    // tes getCards()
    std::vector<Card> outCards = tc2.getCards();
    cout << "Kartu TableCard:" << endl;
    for (int i = 0; i < outCards.size(); i++) {
        cout << i+1 << ". Kartu " << outCards[i] << endl;
    }

    return 0;
}