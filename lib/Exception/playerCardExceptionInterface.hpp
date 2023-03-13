#ifndef PLAYER_CARD_EXCEPTION_INTERFACE_HPP
#define PLAYER_CARD_EXCEPTION_INTERFACE_HPP

#include "cardExceptionInterface.hpp"

using namespace std;

class PlayerException : public CardException {
    private:
        static int numOfPlayerException; // jumlah object PlayerException yang ada
        static string errorMessage[]; // list of error message
    
    public:
        // tidak memerlukan default ctor (tidak ada list of exception), assignment operator (tidak ada assignment), dan dtor (perlunya perhitungan jumlah object PlayerException setelah dihapus)
        PlayerException(int); // user-defined ctor
        PlayerException(const PlayerException&); // cctor

        static int getNumOfPlayerException(); // numOfPlayerException getter

        void displayMessage() const; // message display
};

#endif