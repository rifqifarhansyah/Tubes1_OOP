#include "consoleIOInterface.hpp"
#include "../Player/Player.hpp"
#include "../Ability/Ability.hpp"
#include "../Ability/Abilityless.hpp"
#include "../Ability/Quadruple.hpp"
#include "../Ability/Quarter.hpp"
#include "../Ability/ReRoll.hpp"
#include "../Ability/ReverseDirection.hpp"
#include "../Ability/SwapCard.hpp"
#include "../Ability/SwitchCard.hpp"
#include "../Player/Player.hpp"

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
    return input;
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

void ConsoleIO::startPage(){
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
}

void ConsoleIO::askForCommand(Player& _player, Game& _game){
    while(true)
    {
        cout << "Masukkan perintah yang ingin anda lakukan : " << endl;
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
                ReRoll ability;
                _player.useAbility(ability,_game);
            }
            else if(this->command == "DOUBLE")
            {
                this->DOUBLE(_player,_game);
            }
            else if(this->command == "QUADRUPLE")
            {
                Quadruple ability;
                _player.useAbility(ability,_game);
            }
            else if(this->command == "HALF")
            {
                this->HALF(_player,_game);
            }
            else if(this->command == "QUARTER")
            {
                Quarter ability;
                _player.useAbility(ability,_game);
            }
            else if(this->command == "REVERSE")
            {
                ReverseDirection ability;
                _player.useAbility(ability,_game);
                continue;
            }
            else if(this->command == "SWAP")
            {
                SwapCard ability;
                _player.useAbility(ability,_game);
            }
            else if(this->command == "SWITCH")
            {
                SwitchCard ability;
                _player.useAbility(ability,_game);
            }
            else if(this->command == "ABILITYLESS")
            {
                Abilityless ability;
                _player.useAbility(ability,_game);
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