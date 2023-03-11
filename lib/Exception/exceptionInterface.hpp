#ifndef EXCEPTION_INTERFACE_HPP
#define EXCEPTION_INTERFACE_HPP

#include <string>
#include <iostream>

using namespace std;

class Exception {
    protected:
        static int numOfException; // jumlah object Exception yang ada
        const int ID; // ID exception
    
    public:
        // tidak memerlukan default ctor (tidak ada list of exception), assignment operator (tidak ada assignment), dan dtor (perlunya perhitungan jumlah object Exception setelah dihapus)
        Exception(int); // user-defined ctor
        Exception(const Exception&); // cctor

        static int getNumOfException(); // numOfException getter
        int getID() const; // ID getter

        virtual void displayMessage() const = 0; // message display
};
#endif