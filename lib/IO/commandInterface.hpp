#ifndef COMMAND_INTERFACE_HPP
#define COMMAND_INTERFACE_HPP

#include <iostream>
#include <string>
#include "../Exception/commandExceptionInterface.hpp"
class Game;
class Player;
// #include "../Exception/commandException.cpp"

using namespace std;

class Command{
    protected:
        static int numOfCommands;
    
    public:
        Command(); // Default Constructor
        int getNumofCommands(); // Returns the number of commands
        void NEXT(); // Next Command
        void DOUBLE(Player&,Game&); // Double Command
        void HALF(Player&,Game&); // Half Command
        void INVALIDCOMMAND(string command); // Invalid Command
};

#endif