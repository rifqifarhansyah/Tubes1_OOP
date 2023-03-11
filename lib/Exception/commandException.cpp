#include "commandExceptionInterface.hpp"

int CommandException::numOfCommandException = 0;

CommandException::CommandException(string _command) : Exception(ID) { // user-defined ctor
    command = _command;
    numOfCommandException++;
}

CommandException::CommandException(const CommandException& CE) : Exception(CE) { // cctor
    command = CE.command;
    numOfCommandException++;
}

string CommandException::getCommandException(){ // command getter
    return command;
}

int CommandException::getNumOfCommandException() { // numOfCommandException getter
    return numOfCommandException;
}

void CommandException::displayMessage() const { // message display
    cout << "Command '" << command << "' invalid." << endl;
}