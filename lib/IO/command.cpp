#include "commandInterface.hpp"

using namespace std;

int Command::numOfCommands = 0;

Command::Command()
{
}

int Command::getNumofCommands()
{
    return numOfCommands;
}

void Command::NEXT()
{
    numOfCommands++;
}

void Command::REROLL()
{
    numOfCommands++;
}

void Command::DOUBLE()
{
    numOfCommands++;
}

void Command::QUADRUPLE()
{
    numOfCommands++;
}

void Command::HALF()
{
    numOfCommands++;
}

void Command::QUARTER()
{
    numOfCommands++;
}

void Command::REVERSE()
{
    numOfCommands++;
}

void Command::SWAP()
{
    numOfCommands++;
}

void Command::SWITCH()
{
    numOfCommands++;
}

void Command::ABILITYLESS()
{
    numOfCommands++;
}

void Command::INVALIDCOMMAND(string _command)
{
    throw CommandException(_command);
}

// Path: lib\IO\command.cpp
// Compare this snippet from lib\IO\CommandInterface.hpp: