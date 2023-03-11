#ifndef COMMAND_EXCEPTION_INTERFACE_HPP
#define COMMAND_EXCEPTION_INTERFACE_HPP

#include "exceptionInterface.hpp"
#include <string>

using namespace std;

class CommandException : public Exception {
    protected:
        static int numOfCommandException; // jumlah object CommandException yang ada
        string command; // list of error message
    
    public:
        // tidak memerlukan default ctor (tidak ada list of exception), assignment operator (tidak ada assignment), dan dtor (perlunya perhitungan jumlah object CommandException setelah dihapus)
        CommandException(string); // user-defined ctor
        CommandException(const CommandException&); // cctor

        string getCommandException(); // command getter
        static int getNumOfCommandException(); // numOfCommandException getter
        void displayMessage() const; // message display
};

#endif