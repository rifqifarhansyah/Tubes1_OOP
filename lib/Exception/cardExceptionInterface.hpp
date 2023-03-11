#ifndef CARD_EXCEPTION_INTERFACE_HPP
#define CARD_EXCEPTION_INTERFACE_HPP

#include "exceptionInterface.hpp"
#include <string>

using namespace std;

class CardException : public Exception {
    protected:
        static int numOfCardException; // jumlah object CardException yang ada
    
    public:
        // tidak memerlukan default ctor (tidak ada list of exception), assignment operator (tidak ada assignment), dan dtor (perlunya perhitungan jumlah object CardException setelah dihapus)
        CardException(int); // user-defined ctor
        CardException(const CardException&); // cctor

        static int getNumOfCardException(); // numOfCardException getter
};

#endif