#ifndef PLAYER_CARD_EXCEPTION_INTERFACE_HPP
#define PLAYER_CARD_EXCEPTION_INTERFACE_HPP

#include "cardExceptionInterface.hpp"

using namespace std;

class PlayerCardException : public CardException {
    private:
        static int numOfPlayerCardException; // jumlah object PlayerCardException yang ada
        static string errorMessage[]; // list of error message
    
    public:
        // tidak memerlukan default ctor (tidak ada list of exception), assignment operator (tidak ada assignment), dan dtor (perlunya perhitungan jumlah object PlayerCardException setelah dihapus)
        PlayerCardException(int); // user-defined ctor
        PlayerCardException(const PlayerCardException&); // cctor

        static int getNumOfPlayerCardException(); // numOfPlayerCardException getter

        void displayMessage() const; // message display
};

#endif