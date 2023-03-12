#ifndef CONSOLE_IO_INTERFACE_HPP
#define CONSOLE_IO_INTERFACE_HPP

#include "commandInterface.hpp"

#include <iostream>
#include <string>

using namespace std;

class ConsoleIO : public Command {
    private :
        string command; // command yang akan dijalankan
    public:
        // tidak memerlukan default ctor (tidak ada list of exception), assignment operator (tidak ada assignment), dan dtor (perlunya perhitungan jumlah object ConsoleIO setelah dihapus)
        ConsoleIO(); // user-defined ctor
        ConsoleIO(string); // cctor
        ConsoleIO(const ConsoleIO& CI); // cctor
        string getCommand(); // command getter
        void setCommand(string); // command setter  
        void setCommand(); // command setter (override function for CLI-based command)
        void start(); // main logic
};

#endif