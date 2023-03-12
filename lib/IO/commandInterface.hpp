#ifndef COMMAND_INTERFACE_HPP
#define COMMAND_INTERFACE_HPP

#include <iostream>
#include <string>
#include "../Exception/commandExceptionInterface.hpp"
// #include "../Exception/commandException.cpp"

using namespace std;

class Command{
    protected:
        static int numOfCommands;
    
    public:
        Command(); // Default Constructor
        int getNumofCommands(); // Returns the number of commands
        void NEXT(); // Next Command
        void REROLL(); // Reroll Command
        void DOUBLE(); // Double Command
        void QUADRUPLE(); // Quadruple Command
        void HALF(); // Half Command
        void QUARTER(); // Quarter Command
        void REVERSE(); // Reverse Command
        void SWAP(); // Swap Command
        void SWITCH(); // Add Command
        void ABILITYLESS(); // Abilityless Command
        void INVALIDCOMMAND(string command); // Invalid Command
};

#endif