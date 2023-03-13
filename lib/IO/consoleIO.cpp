#include "consoleIOInterface.hpp"

ConsoleIO::ConsoleIO() : Command(){
    command = "";
}

ConsoleIO::ConsoleIO(string _command){
    command = _command;
}

ConsoleIO::ConsoleIO(const ConsoleIO& CI){
    command = CI.command;
}

string ConsoleIO::getCommand(){
    return command;
}

void ConsoleIO::setCommand(string _command){
    command = _command;
}

void ConsoleIO::setCommand(){
    string _command;
    cin >> _command;
    command = _command;
}

void ConsoleIO::start(){
    /* Read command from user */
    setCommand();
    

    cout << endl;
    cout << "\t\t\t\t  .----------------.  .----------------.  .----------------.  .----------------.  .----------------." << endl;
    cout << "\t\t\t\t| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |" << endl;
    cout << "\t\t\t\t| |  ___  ____   | || |      __      | || |  _______     | || |  _________   | || | _____  _____ | |" << endl;
    cout << "\t\t\t\t| | |_  ||_  _|  | || |     /  \\     | || | |_   __ \\    | || | |  _   _  |  | || ||_   _||_   _|| |" << endl;
    cout << "\t\t\t\t| |   | |_/ /    | || |    / /\\ \\    | || |   | |__) |   | || | |_/ | | \\_|  | || |  | |    | |  | |" << endl;
    cout << "\t\t\t\t| |   |  __'.    | || |   / ____ \\   | || |   |  __ /    | || |     | |      | || |  | '    ' |  | |" << endl;
    cout << "\t\t\t\t| |  _| |  \\ \\_  | || | _/ /    \\ \\_ | || |  _| |  \\ \\_  | || |    _| |_     | || |   \\ `--' /   | |" << endl;
    cout << "\t\t\t\t| | |____||____| | || ||____|  |____|| || | |____| |___| | || |   |_____|    | || |    `.__.'    | |" << endl;
    cout << "\t\t\t\t| |              | || |              | || |              | || |              | || |              | |" << endl;
    cout << "\t\t\t\t| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |" << endl;
    cout << "\t\t\t\t '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " << endl;
    cout << endl;

    /* loop until the round reach 6 */
    // i adalah variabel checking
    int i =0;
    while( i <= 6)
    {
        try
        {
            /* tidak melakukan apa-apa dan giliran diteruskan ke pemain selanjutnya */
            if(this->command  == "NEXT")
            {
                this->NEXT();
                i++;
            }
            else if(this->command == "REROLL")
            {
                this->REROLL();
                i++;
            }
            else if(this->command == "DOUBLE")
            {
                this->DOUBLE();
                i++;
            }
            else if(this->command == "QUADRUPLE")
            {
                this->QUADRUPLE();
                i++;
            }
            else if(this->command == "HALF")
            {
                this->HALF();
                i++;
            }
            else if(this->command == "QUARTER")
            {
                this->QUARTER();
                i++;
            }
            else if(this->command == "REVERSE")
            {
                this->REVERSE();
                i++;
            }
            else if(this->command == "SWAP")
            {
                this->SWAP();
                i++;
            }
            else if(this->command == "SWITCH")
            {
                this->SWITCH();
                i++;
            }
            else if(this->command == "ABILITYLESS")
            {
                this->ABILITYLESS();
                i++;
            }
            else
            {
                this->INVALIDCOMMAND(this->command);
            }
        }
        /* catch for any invalid command */
        catch(Exception& Err)
        {
            Err.displayMessage();
        }
        /* catch for any invalid argument */
        catch(invalid_argument& Err)
        {
            cout << "Can't be parsed to a number." << endl;
        }

        /* Read command from user */
        setCommand();
    }
}