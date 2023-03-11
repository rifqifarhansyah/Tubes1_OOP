#ifndef TABLE_CARD_EXCEPTION_INTERFACE_HPP
#define TABLE_CARD_EXCEPTION_INTERFACE_HPP

#include "cardExceptionInterface.hpp"

using namespace std;

class TableCardException : public CardException {
    private:
        static int numOfTableCardException; // jumlah object TableCardException yang ada
        static string errorMessage[]; // list of error message
    
    public:
        // tidak memerlukan default ctor (tidak ada list of exception), assignment operator (tidak ada assignment), dan dtor (perlunya perhitungan jumlah object TableCardException setelah dihapus)
        TableCardException(int); // user-defined ctor
        TableCardException(const TableCardException&); // cctor

        static int getNumOfTableCardException(); // numOfTableCardException getter

        void displayMessage() const; // message display
};

#endif