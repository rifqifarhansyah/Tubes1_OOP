#include "commandExceptionInterface.hpp"
#include <string>
#include <iostream>

#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define YELLOW "\033[1m\033[33m"
#define BLUE "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN "\033[1m\033[36m"
#define RESET "\033[0m"


using namespace std;

int CommandException::numOfCommandException = 0;

CommandException::CommandException(string _command) : Exception(ID)
{ // user-defined ctor
    command = _command;
    numOfCommandException++;
}

CommandException::CommandException(const CommandException& CE) : Exception(CE.ID) 
{ // cctor
    command = CE.command;
    numOfCommandException++;
}

string CommandException::getCommandException()
{ // command getter
    return command;
}

int CommandException::getNumOfCommandException() 
{ // numOfCommandException getter
    return numOfCommandException;
}

void CommandException::displayMessage() const 
{ // message display
    cout << RED << "Command '" << command << "' invalid." << RESET << endl;
}