#ifndef CONSOLE_IO_INTERFACE_HPP
#define CONSOLE_IO_INTERFACE_HPP

#include "commandInterface.hpp"
#include <iostream>
#include <string>
class Player;
class Game;
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
        void askForCommand(Player& _player, Game& _game); // main logic
        int getIntInput(); // input number
        int getNumberInRange(int _lower, int _upper); // input range number
        void waitEnterInput();
        void startPage();
};

#endif