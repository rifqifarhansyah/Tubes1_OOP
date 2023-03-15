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

// input number
int ConsoleIO::getIntInput(){
    int input;
    string line;
    while(true){
        getline(cin, line);
        try{
            input = stoi(line);
            break;
        }
        catch(invalid_argument& e){
            cout << "Input tidak valid. Silahkan masukkan input bertipe integer" << endl;
        }
    }
}

// input range number
int ConsoleIO::getNumberInRange(int _lower, int _upper){
    int input;
    while(true){
        input = getIntInput();
        if(input >= _lower && input <= _upper){
            break;
        }
        else{
            cout << "Input tidak valid. Silahkan masukkan input antara " << _lower << " dan " << _upper << endl;
        }
    }
    return input;
}

void ConsoleIO::start(Player& _player, Game& _game){

    // cout << endl;
    // cout << "\t\t\t\t  .----------------.  .----------------.  .----------------.  .----------------.  .----------------." << endl;
    // cout << "\t\t\t\t| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |" << endl;
    // cout << "\t\t\t\t| |  ___  ____   | || |      __      | || |  _______     | || |  _________   | || | _____  _____ | |" << endl;
    // cout << "\t\t\t\t| | |_  ||_  _|  | || |     /  \\     | || | |_   __ \\    | || | |  _   _  |  | || ||_   _||_   _|| |" << endl;
    // cout << "\t\t\t\t| |   | |_/ /    | || |    / /\\ \\    | || |   | |__) |   | || | |_/ | | \\_|  | || |  | |    | |  | |" << endl;
    // cout << "\t\t\t\t| |   |  __'.    | || |   / ____ \\   | || |   |  __ /    | || |     | |      | || |  | '    ' |  | |" << endl;
    // cout << "\t\t\t\t| |  _| |  \\ \\_  | || | _/ /    \\ \\_ | || |  _| |  \\ \\_  | || |    _| |_     | || |   \\ `--' /   | |" << endl;
    // cout << "\t\t\t\t| | |____||____| | || ||____|  |____|| || | |____| |___| | || |   |_____|    | || |    `.__.'    | |" << endl;
    // cout << "\t\t\t\t| |              | || |              | || |              | || |              | || |              | |" << endl;
    // cout << "\t\t\t\t| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |" << endl;
    // cout << "\t\t\t\t '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " << endl;
    // cout << endl;

    /* loop until the round reach 6 */
    // i adalah variabel checking
    while(true)
    {
        setCommand();
        try
        {
            /* tidak melakukan apa-apa dan giliran diteruskan ke pemain selanjutnya */
            if(this->command  == "NEXT")
            {
                this->NEXT();
            }
            else if(this->command == "REROLL")
            {
                ReRoll::doAction(_player, _game);
            }
            else if(this->command == "DOUBLE")
            {
                this->DOUBLE();
            }
            else if(this->command == "QUADRUPLE")
            {
                Quadruple::doAction(_player, _game);
            }
            else if(this->command == "HALF")
            {
                this->HALF();
            }
            else if(this->command == "QUARTER")
            {
                Quarter::doAction(_player, _game);
            }
            else if(this->command == "REVERSE")
            {
                ReverseDirection::doAction(_player, _game);
            }
            else if(this->command == "SWAP")
            {
                SwapCard::doAction(_player, _game);
            }
            else if(this->command == "SWITCH")
            {
                SwitchCard::doAction(_player, _game);
            }
            else if(this->command == "ABILITYLESS")
            {
                Abilityless::doAction(_player, _game);
            }
            else
            {
                this->INVALIDCOMMAND(this->command);
            }
            break;
        }
        /* catch for any invalid command */
        catch(Exception& Err)
        {
            Err.displayMessage();
        }
    }
}