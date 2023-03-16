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
            cout << "Input tidak valid. Silahkan masukkan input bertipe integer" << endl;
        }
    }
    return input;
}

void ConsoleIO::waitEnterInput(){
    cin.ignore(1,'\n');
    cout << "press ENTER to continue...";
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
            cout << "Input tidak valid. Silahkan masukkan input antara " << _lower << " dan " << _upper << endl;
        }
    }
    return input;
}

void ConsoleIO::startPage(){
    cout << endl;
    cout << "\t  .----------------.  .----------------.  .----------------.  .----------------.  .----------------." << endl;
    cout << "\t| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |" << endl;
    cout << "\t| |  ___  ____   | || |      __      | || |  _______     | || |  _________   | || | _____  _____ | |" << endl;
    cout << "\t| | |_  ||_  _|  | || |     /  \\     | || | |_   __ \\    | || | |  _   _  |  | || ||_   _||_   _|| |" << endl;
    cout << "\t| |   | |_/ /    | || |    / /\\ \\    | || |   | |__) |   | || | |_/ | | \\_|  | || |  | |    | |  | |" << endl;
    cout << "\t| |   |  __'.    | || |   / ____ \\   | || |   |  __ /    | || |     | |      | || |  | '    ' |  | |" << endl;
    cout << "\t| |  _| |  \\ \\_  | || | _/ /    \\ \\_ | || |  _| |  \\ \\_  | || |    _| |_     | || |   \\ `--' /   | |" << endl;
    cout << "\t| | |____||____| | || ||____|  |____|| || | |____| |___| | || |   |_____|    | || |    `.__.'    | |" << endl;
    cout << "\t| |              | || |              | || |              | || |              | || |              | |" << endl;
    cout << "\t| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |" << endl;
    cout << "\t '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " << endl;
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

ostream& operator<<(ostream& os, const vector<int>& vector) {
    for (auto element : vector) {
        os << element << endl;
    }
    return os;
}

ostream& operator<<(ostream& os, const vector<string>& vector) {
    for (auto element : vector) {
        os << element << endl;
    }
    return os;
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

            // tes output
            cout << numVal << endl;
            cout << colVal << endl;

            for (int i = 0; i < nLines; i++) {
                Card card(numVal[i], colVal[i]);
                cardVal.push_back(card);
            }

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