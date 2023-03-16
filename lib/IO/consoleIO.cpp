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
#include "../Exception/playerCardExceptionInterface.hpp"
#include <algorithm>

#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define YELLOW "\033[1m\033[33m"
#define BLUE "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN "\033[1m\033[36m"
#define RESET "\033[0m"

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
        if (line == "") continue;
        try{
            input = stoi(line);
            break;
        }
        catch(invalid_argument& e){
            cout << RED << "Input tidak valid. Silahkan masukkan input bertipe integer" << RESET << endl;
        }
    }
    return input;
}

void ConsoleIO::waitEnterInput(){
    cin.ignore(1,'\n');
    cout << CYAN << "                                               press ENTER to continue" << RESET;
    cin.get();
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
            cout << RED << "Input tidak valid. Silahkan masukkan input antara " << _lower << " dan " << _upper << RESET << endl;
        }
    }
    return input;
}

void ConsoleIO::startPage(){
    cout << endl;
    cout << CYAN << "========================================================================================================================" << RESET << endl;
    cout << "          P           E           R           M           A           I           N           A           N           " << endl;
    cout << RED << "\t .----------------." << RESET << GREEN << "  .----------------. " << RESET << YELLOW << " .----------------. " << RESET << BLUE << " .----------------. " << RESET << MAGENTA << " .----------------. " << RESET << endl;
    cout << RED << "\t| .--------------. |" << RESET << GREEN << "| .--------------. |" << RESET << YELLOW << "| .--------------. |" << RESET << BLUE << "| .--------------. |" << RESET << MAGENTA << "| .--------------. |" << RESET << endl;
    cout << RED << "\t| |  ___  ____   | |" << RESET << GREEN << "| |      __      | |" << RESET << YELLOW << "| |  _______     | |" << RESET << BLUE << "| |  _________   | |" << RESET << MAGENTA << "| | _____  _____ | |" << RESET << endl;
    cout << RED << "\t| | |_  ||_  _|  | |" << RESET << GREEN << "| |     /  \\     | |" << RESET << YELLOW << "| | |_   __ \\    | |" << RESET << BLUE << "| | |  _   _  |  | |" << RESET << MAGENTA << "| ||_   _||_   _|| |" << RESET << endl;
    cout << RED << "\t| |   | |_/ /    | |" << RESET << GREEN << "| |    / /\\ \\    | |" << RESET << YELLOW << "| |   | |__) |   | |" << RESET << BLUE << "| | |_/ | | \\_|  | |" << RESET << MAGENTA << "| |  | |    | |  | |" << RESET << endl;
    cout << RED << "\t| |   |  __'.    | |" << RESET << GREEN << "| |   / ____ \\   | |" << RESET << YELLOW << "| |   |  __ /    | |" << RESET << BLUE << "| |     | |      | |" << RESET << MAGENTA << "| |  | '    ' |  | |" << RESET << endl;
    cout << RED << "\t| |  _| |  \\ \\_  | |" << RESET << GREEN << "| | _/ /    \\ \\_ | |" << RESET << YELLOW << "| |  _| |  \\ \\_  | |" << RESET << BLUE << "| |    _| |_     | |" << RESET << MAGENTA << "| |   \\ `--' /   | |" << RESET << endl;
    cout << RED << "\t| | |____||____| | |" << RESET << GREEN << "| ||____|  |____|| |" << RESET << YELLOW << "| | |____| |___| | |" << RESET << BLUE << "| |   |_____|    | |" << RESET << MAGENTA << "| |    `.__.'    | |" << RESET << endl;
    cout << RED << "\t| |              | |" << RESET << GREEN << "| |              | |" << RESET << YELLOW << "| |              | |" << RESET << BLUE << "| |              | |" << RESET << MAGENTA << "| |              | |" << RESET << endl;
    cout << RED << "\t| '--------------' |" << RESET << GREEN << "| '--------------' |" << RESET << YELLOW << "| '--------------' |" << RESET << BLUE << "| '--------------' |" << RESET << MAGENTA << "| '--------------' |" << RESET << endl;
    cout << RED << "\t '----------------' " << RESET << GREEN << " '----------------' " << RESET << YELLOW << " '----------------' " << RESET << BLUE << " '----------------' " << RESET << MAGENTA << " '----------------' " << RESET << endl;
    cout << "                                                 ALA KERAJAAN PERMEN                                                 " << endl;
    cout << CYAN << "========================================================================================================================" << RESET << endl;
    cout << endl;
}

void ConsoleIO::askForCommand(Player& _player, Game& _game){
    while(true)
    {
        cout << "Masukkan perintah yang ingin anda lakukan\t: " << endl;
        cout << GREEN << ">> " << RESET;
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

MainDeck ConsoleIO::readMainDeck() {
    string name;
    fstream file;
    file.exceptions (fstream::failbit | fstream::badbit);
    string input;
    int num;
    vector<int> numVal;
    string col;
    vector<string> colVal;
    vector<Card> cardVal;
    MainDeck mainDeck;

    while (true) {
        try {
            // meminta masukan nama file
            cout << "Masukkan nama file MainDeck: ";
            cin >> name;
            file.open(name);

            // parsing isi file
            file >> input;
            int nLines = stoi(input);
            for (int i = 0; i < nLines; i++) {
                file >> input;
                num = stoi(input);
                numVal.push_back(num);

                file >> input;
                col = input;
                colVal.push_back(col);
            }

            for (int i = 0; i < nLines; i++) {
                Card card(numVal[i], colVal[i]);
                cardVal.push_back(card);
            }

            reverse(cardVal.begin(), cardVal.end());
            MainDeck salinDeck(cardVal);
            mainDeck = salinDeck;

            break;
        } catch (const fstream::failure& error) {
            cout << "Error: File tidak ditemukan" << endl;
        } catch (invalid_argument& error) {
            cout << "Input tidak valid. Silahkan masukkan input bertipe integer" << endl;
        }

    }

    file.close();
    return mainDeck;
}