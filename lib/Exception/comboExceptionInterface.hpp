#ifndef COMBO_EXCEPTION_INTERFACE_HPP
#define COMBO_EXCEPTION_INTERFACE_HPP

#include "exceptionInterface.hpp"
#include <string>

using namespace std;

class ComboException : public Exception {
    protected:
        static int numOfComboException; // jumlah object ComboException yang ada
        static string errorMessage[]; // list of error message
    
    public:
        // tidak memerlukan default ctor (tidak ada list of exception), assignment operator (tidak ada assignment), dan dtor (perlunya perhitungan jumlah object ComboException setelah dihapus)
        ComboException(int, string); // user-defined ctor
        ComboException(const ComboException&); // cctor

        static int getNumOfComboException(); // numOfComboException getter

        void displayMessage() const; // message display
};

#endif