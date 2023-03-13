#ifndef INVENTORY_EXCEPTION_INTERFACE_HPP
#define INVENTORY_EXCEPTION_INTERFACE_HPP

#include "exceptionInterface.hpp"
#include <string>

using namespace std;

class InventoryException : public Exception {
    protected:
        static int numOfInventoryException; // jumlah object InventoryException yang ada
        static string errorMessage[]; // list of error message
    
    public:
        // tidak memerlukan default ctor (tidak ada list of exception), assignment operator (tidak ada assignment), dan dtor (perlunya perhitungan jumlah object InventoryException setelah dihapus)
        InventoryException(int); // user-defined ctor
        InventoryException(const InventoryException&); // cctor

        static int getNumOfInventoryException(); // numOfInventoryException getter

        void displayMessage() const; // message display
};

#endif