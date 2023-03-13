#include "../TableCard.hpp"

int main() {
    cout << endl << "TableCard Test" << endl;

    TableCard tc1;
    Card c1(1, "Merah");
    Card c2(2, "Jingga");
    Card c3(3, "Kuning");
    Card c4(4, "Hijau");
    Card c5(5, "Biru");
    Card c6(6, "Nila");
    Card c7(7, "Ungu");

    tc1.draw(c1);
    tc1.draw(c2);
    tc1.draw(c3);
    tc1.draw(c4);
    tc1.draw(c5);
    tc1.draw(c6);
    tc1.draw(c7);

    TableCard tc2(tc1);
    tc2.remove();
    tc2.remove();
    tc2.draw(c6);
    tc2.draw(c7);
    tc2.draw(c1);
    tc2.draw(c2);

    std::vector<Card> cards = tc2.getItem();
    cout << "Kartu TableCard:" << endl;
    for (int i = 0; i < cards.size(); i++) {
        cout << i+1 << ". Kartu " << cards[i] << endl;
    }

    return 0;
}