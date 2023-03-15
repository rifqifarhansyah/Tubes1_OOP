#ifndef COMMAND_INTERFACE_HPP
#define COMMAND_INTERFACE_HPP

#include <iostream>
#include <string>
#include "../Exception/commandExceptionInterface.hpp"
#include "../Ability/Ability.hpp"
#include "../Ability/Abilityless.hpp"
#include "../Ability/Quadruple.hpp"
#include "../Ability/Quarter.hpp"
#include "../Ability/ReRoll.hpp"
#include "../Ability/ReverseDirection.hpp"
#include "../Ability/SwapCard.hpp"
#include "../Ability/SwitchCard.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.hpp"


// #include "../Exception/commandException.cpp"

using namespace std;

class Command{
    protected:
        static int numOfCommands;
    
    public:
        Command(); // Default Constructor
        int getNumofCommands(); // Returns the number of commands
        void NEXT(); // Next Command
        void DOUBLE(); // Double Command
        void HALF(); // Half Command
        void INVALIDCOMMAND(string command); // Invalid Command
};

#endif