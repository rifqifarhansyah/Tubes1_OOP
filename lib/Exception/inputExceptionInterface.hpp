#ifndef INPUT_EXCEPTION_INTERFACE_HPP
#define INPUT_EXCEPTION_INTERFACE_HPP

#include "exceptionInterface.hpp"

class InputException : public Exception {
    protected:
        static int numOfInputException; // jumlah object InputException yang ada
        static string errorMessage[]; // list of error message
    
    public:
        // tidak memerlukan default ctor (tidak ada list of exception), assignment operator (tidak ada assignment), dan dtor (perlunya perhitungan jumlah object InputException setelah dihapus)
        InputException(int); // user-defined ctor
        InputException(const InputException&); // cctor

        static int getNumOfInputException(); // numOfInputException getter

        void displayMessage() const; // message display
};

#endif